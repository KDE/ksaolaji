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
        void filterList( const QString& text );
        void sortList();
        void knsDownload();
    private:
        KLineEdit* m_searchEdit;
        QListView* m_listView;
        QSortFilterProxyModel* m_proxyModel;
        CleanerModel* m_listModel;
        KPushButton* m_refreshButton;
        KPushButton* m_cleanupButton;
};

#endif // MAINWINDOW_H
