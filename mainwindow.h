#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KXmlGuiWindow>
#include <QList>

class QListWidget;
class KPushButton;
class Cleaner;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
    public:
        explicit MainWindow();
        virtual ~MainWindow();
    public Q_SLOTS:
        void refresh();
        void saolaji();
    private Q_SLOTS:
        void loadCleaners();
    private:
        QListWidget* m_listWidget;
        KPushButton* m_refreshButton;
        KPushButton* m_button;
        QList<Cleaner*> m_cleaners;
};

#endif // MAINWINDOW_H
