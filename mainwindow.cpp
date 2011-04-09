/*
 *  This file is part of KSaoLaJi, an advanced system cleaner for KDE
 *  Copyright (C) 2011 Ni Hui <shuizhuyuanluo@126.com>

 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
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
#include "profile.h"

#include <KAction>
#include <KActionCollection>
#include <KDebug>
#include <KIcon>
#include <KInputDialog>
#include <KLineEdit>
#include <KLocale>
#include <KMessageBox>
#include <KPushButton>
#include <KStandardAction>
#include <KStandardDirs>

#include <knewstuff3/downloaddialog.h>

#include <QDir>
#include <QFile>
#include <QHBoxLayout>
#include <QListView>
#include <QSignalMapper>
#include <QSortFilterProxyModel>
#include <QTimer>
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
    m_searchEdit->setClearButtonShown( true );
    m_searchEdit->setClickMessage( i18n( "Type here to start searching..." ) );
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

    m_cancelProfileButton = new KPushButton( i18n( "Cancel" ) );
    buttonLayout->addWidget( m_cancelProfileButton );
    connect( m_cancelProfileButton, SIGNAL(clicked()), this, SLOT(cancelProfile()) );

    m_saveProfileButton = new KPushButton( i18n( "Save" ) );
    buttonLayout->addWidget( m_saveProfileButton );
    connect( m_saveProfileButton, SIGNAL(clicked()), this, SLOT(saveProfile()) );

    m_cancelProfileButton->hide();
    m_saveProfileButton->hide();
    m_edittingProfile = 0;

    KAction* knsDownloadAction = actionCollection()->addAction( "kns_download" );
    knsDownloadAction->setText( i18n( "&Download scripts..." ) );
    knsDownloadAction->setIcon( KIcon( "get-hot-new-stuff" ) );
    connect( knsDownloadAction, SIGNAL(triggered()), this, SLOT(knsDownload()) );

    KAction* newProfileAction = actionCollection()->addAction( "new_profile" );
    newProfileAction->setText( i18n( "New profile..." ) );
    newProfileAction->setIcon( KIcon( "bookmark-new" ) );
    connect( newProfileAction, SIGNAL(triggered()), this, SLOT(newProfile()) );

    connect( m_searchEdit, SIGNAL(textChanged(QString)), this, SLOT(filterList(QString)) );
    connect( m_listModel, SIGNAL(refreshFinished()), this, SLOT(sortList()) );

    KStandardAction::selectAll( m_listModel, SLOT(selectAll()), actionCollection() );
    KStandardAction::deselect( m_listModel, SLOT(deselect()), actionCollection() );
    KStandardAction::quit( this, SLOT(close()), actionCollection() );

    setupGUI( KXmlGuiWindow::Keys | KXmlGuiWindow::Save | KXmlGuiWindow::Create );

    m_selectProfileSignalMapper = new QSignalMapper( this );
    connect( m_selectProfileSignalMapper, SIGNAL(mapped(QObject*)),
             this, SLOT(selectProfile(QObject*)) );
    m_editProfileSignalMapper = new QSignalMapper( this );
    connect( m_editProfileSignalMapper, SIGNAL(mapped(QObject*)),
             this, SLOT(editProfile(QObject*)) );
    m_deleteProfileSignalMapper = new QSignalMapper( this );
    connect( m_deleteProfileSignalMapper, SIGNAL(mapped(QObject*)),
             this, SLOT(deleteProfile(QObject*)) );

    QTimer::singleShot( 0, this, SLOT(setupProfileActions()) );
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupProfileActions()
{
    QDir profileDir( KStandardDirs::locateLocal( "appdata", "profiles/" ) );
    QStringList profileNames = profileDir.entryList( QDir::Files | QDir::Readable );
    QStringList::ConstIterator it = profileNames.constBegin();
    QStringList::ConstIterator end = profileNames.constEnd();
    while ( it != end ) {
        m_profiles << new Profile( *it );
        ++it;
    }
    updateProfileActions();
}

void MainWindow::updateProfileActions()
{
    qDeleteAll( m_selectProfileActions );
    m_selectProfileActions.clear();
    qDeleteAll( m_editProfileActions );
    m_editProfileActions.clear();
    qDeleteAll( m_deleteProfileActions );
    m_deleteProfileActions.clear();

    QList<Profile*>::ConstIterator it = m_profiles.constBegin();
    QList<Profile*>::ConstIterator end = m_profiles.constEnd();
    while ( it != end ) {
        Profile* profile = *it;
        ++it;

        QString name = profile->name();

        KAction* selectProfileAction = new KAction( name, 0 );
        connect( selectProfileAction, SIGNAL(triggered()),
                 m_selectProfileSignalMapper, SLOT(map()) );
        m_selectProfileSignalMapper->setMapping( selectProfileAction, profile );
        m_selectProfileActions << selectProfileAction;

        KAction* editProfileAction = new KAction( name, 0 );
        connect( editProfileAction, SIGNAL(triggered()),
                 m_editProfileSignalMapper, SLOT(map()) );
        m_editProfileSignalMapper->setMapping( editProfileAction, profile );
        m_editProfileActions << editProfileAction;

        KAction* deleteProfileAction = new KAction( name, 0 );
        connect( deleteProfileAction, SIGNAL(triggered()),
                 m_deleteProfileSignalMapper, SLOT(map()) );
        m_deleteProfileSignalMapper->setMapping( deleteProfileAction, profile );
        m_deleteProfileActions << deleteProfileAction;
    }

    unplugActionList( "select_profiles" );
    plugActionList( "select_profiles", m_selectProfileActions );
    unplugActionList( "edit_profiles" );
    plugActionList( "edit_profiles", m_editProfileActions );
    unplugActionList( "delete_profiles" );
    plugActionList( "delete_profiles", m_deleteProfileActions );
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

void MainWindow::setProfileEditting( bool editting )
{
    m_listModel->setProfileEditting( editting );
    m_refreshButton->setVisible( !editting );
    m_cleanupButton->setVisible( !editting );
    m_cancelProfileButton->setVisible( editting );
    m_saveProfileButton->setVisible( editting );

    if ( !editting ) {
        m_edittingProfile = 0;
    }
}

void MainWindow::cancelProfile()
{
    setProfileEditting( false );
    m_listModel->deselect();
}

void MainWindow::saveProfile()
{
    m_listModel->saveToProfile( m_edittingProfile );
    m_edittingProfile->save();
    setProfileEditting( false );
}

void MainWindow::newProfile()
{
    bool ok = false;
    QString name = KInputDialog::getText( i18n( "New profile" ),
                                          i18n( "Enter the name of the profile" ),
                                          i18n( "My profile" ),
                                          &ok
                                        );
    if ( !ok )
        return;

    if ( QFile::exists( KStandardDirs::locateLocal( "appdata", "profiles/" ) + name ) ) {
        KMessageBox::error( this, i18n( "The profile named %1 already exists.", name ) );
        return;
    }

    m_profiles << new Profile( name );
    updateProfileActions();
}

void MainWindow::selectProfile( QObject* obj )
{
    Profile* profile = static_cast<Profile*>(obj);
    profile->load();
    m_listModel->selectProfile( profile );
}

void MainWindow::editProfile( QObject* obj )
{
    setProfileEditting( true );
    m_edittingProfile = static_cast<Profile*>(obj);
    m_listModel->selectProfile( m_edittingProfile );
}

void MainWindow::deleteProfile( QObject* obj )
{
    Profile* profile = static_cast<Profile*>(obj);
    if ( profile == m_edittingProfile ) {
        KMessageBox::error( this, i18n( "You can not delete profile while editing it." ) );
        return;
    }

    profile->remove();
    int index = m_profiles.indexOf( profile );
    m_profiles.removeAt( index );
    delete profile;
    updateProfileActions();
}
