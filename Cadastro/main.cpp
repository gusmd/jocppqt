#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("JoCPP");
    QCoreApplication::setApplicationName("Cadastro");

    MainWindow w;
    w.show();

    return a.exec();
}
