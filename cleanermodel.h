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

#ifndef CLEANERMODEL_H
#define CLEANERMODEL_H

#include <QAbstractListModel>
#include <QList>

namespace KSaoLaJi { class Cleaner; }
class CleanerItem;

class CleanerModel : public QAbstractListModel
{
    Q_OBJECT
    public:
        explicit CleanerModel( QObject* parent = 0 );
        virtual ~CleanerModel();
        virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
        virtual Qt::ItemFlags flags( const QModelIndex& index ) const;
        virtual int rowCount( const QModelIndex& parent = QModelIndex() ) const;
        virtual bool setData( const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
    public Q_SLOTS:
        void refresh();
        void saolaji();
        void reloadScripts();
    Q_SIGNALS:
        void refreshFinished();
    private Q_SLOTS:
        void initialize();
    private:
        void addCleaner( KSaoLaJi::Cleaner* cleaner );
    private:
        QList<CleanerItem*> m_modelItems;
        QList<CleanerItem*> m_cleanerItems;
        QList<CleanerItem*> m_scriptItems;
};

#endif // CLEANERMODEL_H
