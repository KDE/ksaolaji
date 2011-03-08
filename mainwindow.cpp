#include "mainwindow.h"

#include "cleanermodel.h"

#include <KActionCollection>
#include <KDebug>
#include <KLineEdit>
#include <KLocale>
#include <KPushButton>
#include <KStandardAction>
#include <KStandardDirs>

#include <QDir>
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
    m_proxyModel = new QSortFilterProxyModel;
    m_listModel = new CleanerModel;
    m_proxyModel->setFilterCaseSensitivity( Qt::CaseInsensitive );
    m_proxyModel->setSourceModel( m_listModel );
    m_listView->setSelectionMode( QAbstractItemView::NoSelection );
    m_listView->setUniformItemSizes( true );
    m_listView->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    m_listView->setModel( m_proxyModel );
    layout->addWidget( m_listView );

    m_refreshButton = new KPushButton( i18n( "Refresh" ) );
    layout->addWidget( m_refreshButton );

    connect( m_refreshButton, SIGNAL(clicked()), m_listModel, SLOT(refresh()) );

    m_button = new KPushButton( i18n( "Clean up..." ) );
    layout->addWidget( m_button );

    connect( m_button, SIGNAL(clicked()), m_listModel, SLOT(saolaji()) );

    connect( m_searchEdit, SIGNAL(textChanged(QString)), m_proxyModel, SLOT(setFilterFixedString(QString)) );

    KStandardAction::quit( this, SLOT(close()), actionCollection() );

    setupGUI();
}

MainWindow::~MainWindow()
{
}
