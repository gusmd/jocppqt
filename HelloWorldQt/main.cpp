#include <iostream>
#include <string>

#include <QString>

int main() {
    QString hello("Hello, World");
    std::string world(" World");

    std::cout << hello.endsWith("lo") << std::endl;

    std::cout << hello.toStdString() + world << std::endl;
    return 0;
}
