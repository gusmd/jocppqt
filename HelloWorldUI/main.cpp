#include <iostream>
#include <string>

#include <QString>

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMessageBox::warning(nullptr, "Ahhh", "Hello World");

    return 0;
}
