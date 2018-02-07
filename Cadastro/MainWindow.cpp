#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ContactInfo.h"

#include <QJSonObject>
#include <QJSonDocument>
#include <QJSonArray>
#include <QSettings>

#include <iostream>
#include <ciso646>

static constexpr char* CONTACTS_SETTINGS = "contacts_list";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    populateContactsFromJson();
    updateContactList();

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addContact);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::deleteContact);
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::editContactOnClick);
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

void MainWindow::editContactOnClick(QListWidgetItem *item)
{
    int clickedIndex = ui->listWidget->row(item);

    Contact contact = m_contacts.at(clickedIndex);

    Contact editedContact = ContactInfo::editContact(contact, this);

    if (editedContact.firstName.isEmpty()) {
        return;
    }

    m_contacts.replace(clickedIndex, editedContact);

    updateContactList();
}

void MainWindow::storeNewContactList(const QList<Contact> contacts)
{
    QJsonObject root;

    QJsonArray jcontacts;

    for (const auto contact : contacts) {
        QJsonObject jcontact;
        jcontact["firstName"] = contact.firstName;
        jcontact["lastName"] = contact.lastName;
        jcontact["email"] = contact.email;
        jcontact["phoneNumber"] = contact.phoneNumber;
        jcontact["address"] = contact.address;

        jcontacts.append(jcontact);
    }

    root["Contacts"] = jcontacts;

    QJsonDocument document(root);

    QSettings settings;
    settings.setValue(CONTACTS_SETTINGS, document.toJson());
}

void MainWindow::populateContactsFromJson()
{
    QSettings settings;
    QJsonDocument document = QJsonDocument::fromJson(settings.value(CONTACTS_SETTINGS).toByteArray());

    QJsonArray jcontacts = document.object()["Contacts"].toArray();

    m_contacts.clear();

    for (auto jcontactRef : jcontacts) {
        QJsonObject jcontact = jcontactRef.toObject();
        m_contacts.append({ jcontact["firstName"].toString(), jcontact["lastName"].toString(),
            jcontact["email"].toString(), jcontact["phoneNumber"].toString(),
            jcontact["address"].toString() });
    }
}


void MainWindow::updateContactList()
{
    ui->listWidget->clear();
    for (const Contact &contact : m_contacts) {
        ui->listWidget->addItem(contact.firstName);
    }

    storeNewContactList(m_contacts);
}
