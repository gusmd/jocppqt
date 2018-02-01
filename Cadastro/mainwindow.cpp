#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ContactInfo.h"

#include <iostream>
#include <ciso646>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_contacts.append({ "Jocemar", "Luiz", "joce@gmail.com", "619 999 9999", "R. Das Acácias" });
    m_contacts.append({ "Augusto", "Merdeiros", "gutinhosafado@gmail.com", "619 666 6666", "R. Dos Machos" });
    updateContactList();

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addContact);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteContact);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addContact()
{
    Contact contact = ContactInfo::createNewContact(this);
    if (contact.firstName.isEmpty()) {
        std::cout << "Canceled!!!" << std::endl;
        return;
    }

    m_contacts.append(contact);
    updateContactList();
}

void MainWindow::deleteContact()
{
    auto selectedItems = ui->listWidget->selectedItems();
    if (not selectedItems.empty()) {
        int selectedIndex =  ui->listWidget->row(selectedItems.at(0));
        
        m_contacts.removeAt(selectedIndex);

        updateContactList();
    }
}

void MainWindow::updateContactList()
{
    ui->listWidget->clear();
    for (const Contact &contact : m_contacts) {
        ui->listWidget->addItem(contact.firstName);
    }
}
