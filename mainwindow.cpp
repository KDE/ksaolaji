#include "mainwindow.h"

#include "cleaner_ark.h"
#include "cleaner_cookie.h"
#include "cleaner_cookiepolicy.h"
#include "cleaner_dolphin.h"
#include "cleaner_dummy.h"
#include "cleaner_favicon.h"
#include "cleaner_flashplayer.h"
#include "cleaner_gwenview.h"
#include "cleaner_kaffeine.h"
#include "cleaner_kate.h"
#include "cleaner_kdeglobal.h"
#include "cleaner_kgamerenderer.h"
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
#include "cleaner_okular.h"
#include "cleaner_okulardocdata.h"
#include "cleaner_plasmawallpaper.h"
#include "cleaner_recentdoc.h"
#include "cleaner_rekonqsnap.h"
#include "cleaner_smplayer.h"
#include "cleaner_thumbnail.h"
#include "cleaner_vlc.h"

#include <KActionCollection>
#include <KDebug>
#include <KIcon>
#include <KLocale>
#include <KPushButton>
#include <KStandardAction>

#include <QTimer>
#include <QListWidget>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow()
: KXmlGuiWindow()
{
    QWidget* mainWidget = new QWidget;
    setCentralWidget( mainWidget );

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setMargin( 0 );
    layout->setSpacing( 0 );
    mainWidget->setLayout( layout );

    m_listWidget = new QListWidget;
    layout->addWidget( m_listWidget );

    m_refreshButton = new KPushButton( i18n( "Refresh" ) );
    layout->addWidget( m_refreshButton );

    connect( m_refreshButton, SIGNAL(clicked()), this, SLOT(refresh()) );

    m_button = new KPushButton( i18n( "Clean up..." ) );
    layout->addWidget( m_button );

    connect( m_button, SIGNAL(clicked()), this, SLOT(saolaji()) );

    KStandardAction::quit( this, SLOT(close()), actionCollection() );

    setupGUI();

    QTimer::singleShot( 0, this, SLOT(loadCleaners()) );
}

MainWindow::~MainWindow()
{
    /// unload cleaners
    QList<Cleaner*>::Iterator it = m_cleaners.begin();
    QList<Cleaner*>::Iterator end = m_cleaners.end();
    while ( it != end ) {
        delete *it;
        ++it;
    }
    m_cleaners.clear();
}

void MainWindow::refresh()
{
    m_listWidget->clear();

    QList<Cleaner*>::ConstIterator it = m_cleaners.constBegin();
    QList<Cleaner*>::ConstIterator end = m_cleaners.constEnd();
    while ( it != end ) {
        Cleaner* cleaner = *it;
        ++it;
        if ( cleaner->youlaji() ) {
            QListWidgetItem* item = new QListWidgetItem;
            item->setText( cleaner->description() );
            item->setIcon( KIcon( cleaner->iconName() ) );
            item->setCheckState( Qt::Unchecked );
            item->setData( Qt::UserRole, QVariant::fromValue( cleaner ) );
            m_listWidget->addItem( item );
        }
    }
}

void MainWindow::saolaji()
{
    int itemCount = m_listWidget->count();
    for ( int i = 0; i < itemCount; ++i ) {
        QListWidgetItem* item = m_listWidget->item( i );
        if ( item->checkState() == Qt::Checked ) {
            Cleaner* cleaner = item->data( Qt::UserRole ).value<Cleaner*>();
            cleaner->saolaji();
        }
    }

    /// refresh lists
    refresh();
}

void MainWindow::loadCleaners()
{
    m_cleaners << new CleanerArk;
    m_cleaners << new CleanerCookie;
    m_cleaners << new CleanerCookiePolicy;
    m_cleaners << new CleanerDolphin;
    m_cleaners << new CleanerDummy;
    m_cleaners << new CleanerFavicon;
    m_cleaners << new CleanerFlashPlayer;
    m_cleaners << new CleanerGwenview;
    m_cleaners << new CleanerKaffeine;
    m_cleaners << new CleanerKate;
    m_cleaners << new CleanerKDEGlobal;
    m_cleaners << new CleanerKGameRenderer;
    m_cleaners << new CleanerKHTMLForm;
    m_cleaners << new CleanerKickoff;
    m_cleaners << new CleanerKIOHelpCache;
    m_cleaners << new CleanerKIOHttpCache;
    m_cleaners << new CleanerKlipper;
    m_cleaners << new CleanerKMid;
    m_cleaners << new CleanerKolourPaint;
    m_cleaners << new CleanerKonqHistory;
    m_cleaners << new CleanerKonqLocBar;
    m_cleaners << new CleanerKonqueror;
    m_cleaners << new CleanerKPixmapCache;
    m_cleaners << new CleanerKPresenter;
    m_cleaners << new CleanerKrita;
    m_cleaners << new CleanerKRunner;
    m_cleaners << new CleanerKSpread;
    m_cleaners << new CleanerKTorrent;
    m_cleaners << new CleanerKTorrentLog;
    m_cleaners << new CleanerKTrash;
    m_cleaners << new CleanerKWord;
    m_cleaners << new CleanerKWrite;
    m_cleaners << new CleanerOkular;
    m_cleaners << new CleanerOkularDocData;
    m_cleaners << new CleanerPlasmaWallpaper;
    m_cleaners << new CleanerRecentDoc;
    m_cleaners << new CleanerRekonqSnap;
    m_cleaners << new CleanerSMPlayer;
    m_cleaners << new CleanerThumbnail;
    m_cleaners << new CleanerVLC;

    refresh();
}

