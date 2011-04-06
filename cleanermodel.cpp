/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cleanermodel.h"

#include "cleaner_kross.h"
#include "cleaner_plugin.h"

#include "cleaners/cleaner_ark.h"
#include "cleaners/cleaner_choqoktimeline.h"
#include "cleaners/cleaner_cookie.h"
#include "cleaners/cleaner_cookiepolicy.h"
#include "cleaners/cleaner_dolphin.h"
#include "cleaners/cleaner_favicon.h"
#include "cleaners/cleaner_fcitxrecord.h"
#include "cleaners/cleaner_flashplayer.h"
#include "cleaners/cleaner_gwenview.h"
#include "cleaners/cleaner_kaffeine.h"
#include "cleaners/cleaner_kate.h"
#include "cleaners/cleaner_kdeglobal.h"
#include "cleaners/cleaner_kgamerenderer.h"
#include "cleaners/cleaner_kget.h"
#include "cleaners/cleaner_kgethistory.h"
#include "cleaners/cleaner_khtmlform.h"
#include "cleaners/cleaner_kickoff.h"
#include "cleaners/cleaner_kiohelpcache.h"
#include "cleaners/cleaner_kiohttpcache.h"
#include "cleaners/cleaner_klipper.h"
#include "cleaners/cleaner_kmid.h"
#include "cleaners/cleaner_kolourpaint.h"
#include "cleaners/cleaner_konqhistory.h"
#include "cleaners/cleaner_konqlocbar.h"
#include "cleaners/cleaner_konqueror.h"
#include "cleaners/cleaner_kpixmapcache.h"
#include "cleaners/cleaner_kpresenter.h"
#include "cleaners/cleaner_krita.h"
#include "cleaners/cleaner_krunner.h"
#include "cleaners/cleaner_kspread.h"
#include "cleaners/cleaner_ktorrent.h"
#include "cleaners/cleaner_ktorrentlog.h"
#include "cleaners/cleaner_ktrash.h"
#include "cleaners/cleaner_kword.h"
#include "cleaners/cleaner_kwrite.h"
#include "cleaners/cleaner_marbletilecache.h"
#include "cleaners/cleaner_nepomukcache.h"
#include "cleaners/cleaner_okular.h"
#include "cleaners/cleaner_okulardocdata.h"
#include "cleaners/cleaner_plasmawallpaper.h"
#include "cleaners/cleaner_recentdoc.h"
#include "cleaners/cleaner_rekonqhistory.h"
#include "cleaners/cleaner_rekonqsnap.h"
#include "cleaners/cleaner_smplayer.h"
#include "cleaners/cleaner_thumbnail.h"
#include "cleaners/cleaner_vlc.h"
#include "cleaners/cleaner_winetrickscache.h"

#include "cleaner.h"
#include "cleaneritem.h"
#include "cleanerjob.h"

#include "ksaolajiadaptor.h"

#include <KDebug>
#include <KIcon>
#include <KStandardDirs>
#include <KPluginFactory>
#include <KPluginInfo>
#include <KPluginLoader>
#include <KServiceTypeTrader>
#include <ThreadWeaver/Weaver>

#include <QDir>
#include <QTimer>

CleanerModel::CleanerModel( QObject* parent )
: QAbstractListModel(parent)
{
    QTimer::singleShot( 0, this, SLOT(initialize()) );
    connect( ThreadWeaver::Weaver::instance(), SIGNAL(finished()),
             this, SLOT(refresh()) );
}

CleanerModel::~CleanerModel()
{
    qDeleteAll( m_cleanerItems );
    qDeleteAll( m_scriptItems );
    m_modelItems.clear();
    m_cleanerItems.clear();
    m_scriptItems.clear();
}

QVariant CleanerModel::data( const QModelIndex& index, int role ) const
{
    if ( !index.isValid() )
        return QVariant();

    if ( role == Qt::DisplayRole )
        return m_modelItems.at( index.row() )->description();
    if ( role == Qt::DecorationRole )
        return KIcon( m_modelItems.at( index.row() )->iconName() );
    if ( role == Qt::CheckStateRole )
        return m_modelItems.at( index.row() )->isChecked() ? Qt::Checked : Qt::Unchecked;
    if ( role == Qt::UserRole )
        return m_modelItems.at( index.row() )->useCount();

    return QVariant();
}

Qt::ItemFlags CleanerModel::flags( const QModelIndex& index ) const
{
    Q_UNUSED(index)
    return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
}

int CleanerModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED(parent)
    return m_modelItems.count();
}

bool CleanerModel::setData( const QModelIndex& index, const QVariant& value, int role )
{
    if ( role == Qt::CheckStateRole ) {
        m_modelItems[ index.row() ]->setChecked( value == Qt::Checked );
        emit(dataChanged(index, index));
    }
    return true;
}

void CleanerModel::refresh()
{
    beginRemoveRows( QModelIndex(), 0, m_modelItems.count() );
    m_modelItems.clear();
    endRemoveRows();

    int row = 0;
    /// add scripts
    QList<CleanerItem*>::Iterator it = m_scriptItems.begin();
    QList<CleanerItem*>::Iterator end = m_scriptItems.end();
    while ( it != end ) {
        if ( ( *it )->youlaji( true ) ) {
            beginInsertRows( QModelIndex(), row, row );
            m_modelItems << *it;
            ++row;
            endInsertRows();
        }
        ++it;
    }
    /// add cleaners
    it = m_cleanerItems.begin();
    end = m_cleanerItems.end();
    while ( it != end ) {
        if ( ( *it )->youlaji( true ) ) {
            beginInsertRows( QModelIndex(), row, row );
            m_modelItems << *it;
            ++row;
            endInsertRows();
        }
        ++it;
    }

    emit refreshFinished();
}

void CleanerModel::saolaji()
{
    bool needRefresh = false;
    QList<CleanerItem*>::Iterator it = m_modelItems.begin();
    QList<CleanerItem*>::Iterator end = m_modelItems.end();
    while ( it != end ) {
        CleanerItem* cleanerItem = *it;
        if ( cleanerItem->isChecked() ) {
            if ( cleanerItem->isThreadSafe() ) {
                /// thread safe, really happy ^_^
                CleanerJob* job = new CleanerJob( cleanerItem );
                ThreadWeaver::Weaver::instance()->enqueue( job );
            }
            else {
                /// not thread safe, run synchonously
                cleanerItem->saolaji();
                needRefresh = true;
            }
        }
        ++it;
    }

    if ( needRefresh && ThreadWeaver::Weaver::instance()->isEmpty() ) {
        /// some synchonous cleaning finished, refresh immediately
        refresh();
    }
}

void CleanerModel::reloadScripts()
{
    qDeleteAll( m_scriptItems );
    m_scriptItems.clear();
    /// load kross cleaners and kns scripts
    QDir krossdir( KStandardDirs::locateLocal( "appdata", "kross" ) );
    QDir kns3dir( KStandardDirs::locateLocal( "appdata", "knewstuff3" ) );
    QFileInfoList scripts = krossdir.entryInfoList( QDir::Files | QDir::NoSymLinks );
    scripts << kns3dir.entryInfoList( QDir::Files | QDir::NoSymLinks );
    QFileInfoList::ConstIterator it = scripts.constBegin();
    QFileInfoList::ConstIterator end = scripts.constEnd();
    while ( it != end ) {
        KSaoLaJi::Cleaner* cleaner = new CleanerKross( ( *it ).absoluteFilePath() );
        m_scriptItems << new CleanerItem( cleaner );
        ++it;
    }
    refresh();
}

void CleanerModel::initialize()
{
    /// load scripts cleaners
    reloadScripts();

    /// load plugin cleaners
    KService::List offers = KServiceTypeTrader::self()->query( "KSaoLaJi/Cleaner" );
    KService::List::ConstIterator it2 = offers.constBegin();
    KService::List::ConstIterator end2 = offers.constEnd();
    while ( it2 != end2 ) {
        KService::Ptr service = *it2;
        ++it2;

        KPluginFactory* factory = KPluginLoader( service->library() ).factory();
        if ( !factory ) {
            kWarning() << "can not load plugin " << service->library();
            continue;
        }

        KSaoLaJi::CleanerPlugin* plugin = factory->create<KSaoLaJi::CleanerPlugin>( 0 );
        if ( !plugin ) {
            kWarning() << "error loading plugin " << service->library();
            continue;
        }

        kWarning() << "Load plugin: " << service->library();
        addCleaner( plugin );
    }

    /// load built-in cleaners
    {
        addCleaner( new CleanerArk );
        addCleaner( new CleanerChoqokTimeline );
        addCleaner( new CleanerCookie );
        addCleaner( new CleanerCookiePolicy );
        addCleaner( new CleanerDolphin );
        addCleaner( new CleanerFavicon );
        addCleaner( new CleanerFcitxRecord );
        addCleaner( new CleanerFlashPlayer );
        addCleaner( new CleanerGwenview );
        addCleaner( new CleanerKaffeine );
        addCleaner( new CleanerKate );
        addCleaner( new CleanerKDEGlobal );
        addCleaner( new CleanerKGameRenderer );
        addCleaner( new CleanerKGet );
        addCleaner( new CleanerKGetHistory );
        addCleaner( new CleanerKHTMLForm );
        addCleaner( new CleanerKickoff );
        addCleaner( new CleanerKIOHelpCache );
        addCleaner( new CleanerKIOHttpCache );
        addCleaner( new CleanerKlipper );
        addCleaner( new CleanerKMid );
        addCleaner( new CleanerKolourPaint );
        addCleaner( new CleanerKonqHistory );
        addCleaner( new CleanerKonqLocBar );
        addCleaner( new CleanerKonqueror );
        addCleaner( new CleanerKPixmapCache );
        addCleaner( new CleanerKPresenter );
        addCleaner( new CleanerKrita );
        addCleaner( new CleanerKRunner );
        addCleaner( new CleanerKSpread );
        addCleaner( new CleanerKTorrent );
        addCleaner( new CleanerKTorrentLog );
        addCleaner( new CleanerKTrash );
        addCleaner( new CleanerKWord );
        addCleaner( new CleanerKWrite );
        addCleaner( new CleanerMarbleTileCache );
        addCleaner( new CleanerNepomukCache );
        addCleaner( new CleanerOkular );
        addCleaner( new CleanerOkularDocData );
        addCleaner( new CleanerPlasmaWallpaper );
        addCleaner( new CleanerRecentDoc );
        addCleaner( new CleanerRekonqHistory );
        addCleaner( new CleanerRekonqSnap );
        addCleaner( new CleanerSMPlayer );
        addCleaner( new CleanerThumbnail );
        addCleaner( new CleanerVLC );
        addCleaner( new CleanerWinetricksCache );
    }

    /// setup dbus adaptor
    new KSaoLaJiAdaptor( this );
    QDBusConnection dbus = QDBusConnection::sessionBus();
    dbus.registerObject( "/KSaoLaJi", this );
    dbus.registerService( "org.kde.ksaolaji" );

    /// emit signal to sort list
    emit refreshFinished();
}

void CleanerModel::addCleaner( KSaoLaJi::Cleaner* cleaner )
{
    CleanerItem* item = new CleanerItem( cleaner );
    if ( item->youlaji() ) {
        int row = m_modelItems.count();
        beginInsertRows( QModelIndex(), row, row );
        m_modelItems << item;
        endInsertRows();
    }
    m_cleanerItems << item;
}
