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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KXmlGuiWindow>

class QListView;
class QSortFilterProxyModel;
class KLineEdit;
class KPushButton;
class CleanerModel;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
    public:
        explicit MainWindow();
        virtual ~MainWindow();
    private Q_SLOTS:
        void setupProfileActions();
        void filterList( const QString& text );
        void sortList();
        void knsDownload();
        void newProfile();
    private:
        KLineEdit* m_searchEdit;
        QListView* m_listView;
        QSortFilterProxyModel* m_proxyModel;
        CleanerModel* m_listModel;
        KPushButton* m_refreshButton;
        KPushButton* m_cleanupButton;
};

#endif // MAINWINDOW_H
