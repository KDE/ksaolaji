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
