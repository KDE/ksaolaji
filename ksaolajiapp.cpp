
#include "ksaolajiapp.h"
#include "mainwindow.h"

KSaoLaJiApplication::KSaoLaJiApplication()
: KUniqueApplication()
{
    m_mainwindow = new MainWindow;
    m_mainwindow->show();
}

KSaoLaJiApplication::~KSaoLaJiApplication()
{
}

int KSaoLaJiApplication::newInstance()
{
    return KUniqueApplication::newInstance();
}

void KSaoLaJiApplication::loadCommandLineOptionsForNewInstance()
{
}
