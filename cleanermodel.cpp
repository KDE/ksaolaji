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

#include "ksaolajiadaptor.h"

#include <KDebug>
#include <KIcon>
#include <KStandardDirs>
#include <KPluginFactory>
#include <KPluginInfo>
#include <KPluginLoader>
#include <KServiceTypeTrader>

#include <QDir>
#include <QTimer>

CleanerModel::CleanerModel( QObject* parent )
: QAbstractListModel(parent)
{
    QTimer::singleShot( 0, this, SLOT(initialize()) );
}

CleanerModel::~CleanerModel()
{
    qDeleteAll( m_cleanerItems );
    m_modelItems.clear();
    m_cleanerItems.clear();
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
    QList<CleanerItem*>::Iterator it = m_cleanerItems.begin();
    QList<CleanerItem*>::Iterator end = m_cleanerItems.end();
    while ( it != end ) {
        if ( ( *it )->youlaji( true ) ) {
            beginInsertRows( QModelIndex(), row, row );
            m_modelItems << *it;
            ++row;
            endInsertRows();
        }
        ++it;
    }
}

void CleanerModel::saolaji()
{
    QList<CleanerItem*>::Iterator it = m_modelItems.begin();
    QList<CleanerItem*>::Iterator end = m_modelItems.end();
    while ( it != end ) {
        if ( ( *it )->isChecked() )
            ( *it )->saolaji();
        ++it;
    }
    refresh();
}

void CleanerModel::initialize()
{
    /// load kross cleaners
    QDir krossdir( KStandardDirs::locateLocal( "appdata", "kross" ) );
    QFileInfoList scripts = krossdir.entryInfoList( QDir::Files | QDir::NoSymLinks );
    QFileInfoList::ConstIterator it = scripts.constBegin();
    QFileInfoList::ConstIterator end = scripts.constEnd();
    while ( it != end ) {
        addCleaner( new CleanerKross( ( *it ).absoluteFilePath() ) );
        ++it;
    }

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
    dbus.registerService( "org.foo.ksaolaji" );
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
