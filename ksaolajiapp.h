
#ifndef KSAOLAJIAPP_H
#define KSAOLAJIAPP_H

#include <KUniqueApplication>

class MainWindow;
class KSaoLaJiApplication : public KUniqueApplication
{
    Q_OBJECT
    public:
        explicit KSaoLaJiApplication();
        virtual ~KSaoLaJiApplication();
        virtual int newInstance();
    public Q_SLOTS:
        virtual void loadCommandLineOptionsForNewInstance();
    private:
        MainWindow* m_mainwindow;
};

#endif // KSAOLAJIAPP_H
