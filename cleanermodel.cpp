#include "cleanermodel.h"

#include "cleaner_kross.h"

#include "cleaner_ark.h"
#include "cleaner_choqoktimeline.h"
#include "cleaner_cookie.h"
#include "cleaner_cookiepolicy.h"
#include "cleaner_dolphin.h"
#include "cleaner_dummy.h"
#include "cleaner_favicon.h"
#include "cleaner_fcitxrecord.h"
#include "cleaner_flashplayer.h"
#include "cleaner_gwenview.h"
#include "cleaner_kaffeine.h"
#include "cleaner_kate.h"
#include "cleaner_kdeglobal.h"
#include "cleaner_kgamerenderer.h"
#include "cleaner_kget.h"
#include "cleaner_kgethistory.h"
#include "cleaner_khtmlform.h"
#include "cleaner_kickoff.h"
#include "cleaner_kiohelpcache.h"
#include "cleaner_kiohttpcache.h"
#include "cleaner_klipper.h"
#include "cleaner_kmid.h"
#include "cleaner_kolourpaint.h"
#include "cleaner_konqhistory.h"
#include "cleaner_konqlocbar.h"
#include "cleaner_konqueror.h"
#include "cleaner_kpixmapcache.h"
#include "cleaner_kpresenter.h"
#include "cleaner_krita.h"
#include "cleaner_krunner.h"
#include "cleaner_kspread.h"
#include "cleaner_ktorrent.h"
#include "cleaner_ktorrentlog.h"
#include "cleaner_ktrash.h"
#include "cleaner_kword.h"
#include "cleaner_kwrite.h"
#include "cleaner_nepomukcache.h"
#include "cleaner_okular.h"
#include "cleaner_okulardocdata.h"
#include "cleaner_plasmawallpaper.h"
#include "cleaner_recentdoc.h"
#include "cleaner_rekonqhistory.h"
#include "cleaner_rekonqsnap.h"
#include "cleaner_smplayer.h"
#include "cleaner_thumbnail.h"
#include "cleaner_vlc.h"
#include "cleaner_winetrickscache.h"

#include "cleaner.h"
#include "cleaneritem.h"

#include <KDebug>
#include <KIcon>
#include <KStandardDirs>

#include <QDir>
#include <QTimer>

CleanerModel::CleanerModel( QObject* parent )
: QAbstractListModel(parent)
{
    QTimer::singleShot( 0, this, SLOT(loadCleaners()) );
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

void CleanerModel::loadCleaners()
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

    /// load built-in cleaners
    {
        addCleaner( new CleanerArk );
        addCleaner( new CleanerChoqokTimeline );
        addCleaner( new CleanerCookie );
        addCleaner( new CleanerCookiePolicy );
        addCleaner( new CleanerDolphin );
        addCleaner( new CleanerDummy );
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
}

void CleanerModel::addCleaner( Cleaner* cleaner )
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
