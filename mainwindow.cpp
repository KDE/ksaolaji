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

#include "mainwindow.h"

#include "cleanermodel.h"

#include <KAction>
#include <KActionCollection>
#include <KDebug>
#include <KIcon>
#include <KLineEdit>
#include <KLocale>
#include <KMessageBox>
#include <KPushButton>
#include <KStandardAction>

#include <knewstuff3/downloaddialog.h>

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

    KAction* knsDownloadAction = actionCollection()->addAction( "kns_download" );
    knsDownloadAction->setText( i18n( "&Download scripts..." ) );
    knsDownloadAction->setIcon( KIcon( "get-hot-new-stuff" ) );

    connect( knsDownloadAction, SIGNAL(triggered()), this, SLOT(knsDownload()) );

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

void MainWindow::knsDownload()
{
    KNS3::DownloadDialog dialog;
    dialog.exec();
    if ( !dialog.changedEntries().isEmpty() ) {
        m_listModel->reloadScripts();
    }
}
