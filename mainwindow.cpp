#include "mainwindow.h"

#include "cleanermodel.h"

#include <KActionCollection>
#include <KDebug>
#include <KIcon>
#include <KLineEdit>
#include <KLocale>
#include <KPushButton>
#include <KStandardAction>

#include <QHBoxLayout>
#include <QListView>
#include <QSortFilterProxyModel>
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

    m_searchEdit = new KLineEdit;
    layout->addWidget( m_searchEdit );

    m_listView = new QListView;
    m_proxyModel = new QSortFilterProxyModel( this );
    m_listModel = new CleanerModel( this );
    m_proxyModel->setFilterCaseSensitivity( Qt::CaseInsensitive );
    m_proxyModel->setSortRole( Qt::UserRole );
    m_proxyModel->setSourceModel( m_listModel );
    m_listView->setSelectionMode( QAbstractItemView::NoSelection );
    m_listView->setUniformItemSizes( true );
    m_listView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    m_listView->setModel( m_proxyModel );
    layout->addWidget( m_listView );

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->setMargin( 0 );
    buttonLayout->setSpacing( 0 );
    layout->addLayout( buttonLayout );

    m_refreshButton = new KPushButton( i18n( "Refresh" ) );
    m_refreshButton->setIcon( KIcon( "view-refresh" ) );
    buttonLayout->addWidget( m_refreshButton );

    connect( m_refreshButton, SIGNAL(clicked()), m_listModel, SLOT(refresh()) );

    m_cleanupButton = new KPushButton( i18n( "Clean up..." ) );
    m_cleanupButton->setIcon( KIcon( "edit-clear" ) );
    buttonLayout->addWidget( m_cleanupButton );

    connect( m_cleanupButton, SIGNAL(clicked()), m_listModel, SLOT(saolaji()) );

    connect( m_searchEdit, SIGNAL(textChanged(QString)), this, SLOT(filterList(QString)) );
    connect( m_listModel, SIGNAL(refreshFinished()), this, SLOT(sortList()) );

    KStandardAction::quit( this, SLOT(close()), actionCollection() );

    setupGUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::filterList( const QString& text )
{
    m_proxyModel->setFilterFixedString( text );
    sortList();
}

void MainWindow::sortList()
{
    m_proxyModel->sort( 0, Qt::DescendingOrder );
}
