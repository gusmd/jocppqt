#include "ContactInfo.h"
#include "ui_ContactInfo.h"

#include <QMessageBox>

ContactInfo::ContactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);

    connect(ui->SaveButton, &QPushButton::clicked, this, &ContactInfo::processSaveClick);
    connect(ui->CancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

ContactInfo::~ContactInfo()
{
    delete ui;
}

QString ContactInfo::getFName() const
{
    return ui->FnameEdit->text();
}

void ContactInfo::setFName(const QString &name)
{
    ui->FnameEdit->setText(name);
}

QString ContactInfo::getLName() const
{
    return ui->LnameEdit->text();
}

void ContactInfo::setLName(const QString &lastName)
{
    ui->LnameEdit->setText(lastName);
}

QString ContactInfo::getEmail() const
{
    return ui->EmailEdit->text();
}

void ContactInfo::setEmail(const QString &email)
{
    ui->EmailEdit->setText(email);
}

QString ContactInfo::getPhoneNumber() const
{
    return ui->PhoneEdit->text();
}

void ContactInfo::setPhoneNumber(const QString &phone)
{
    ui->PhoneEdit->setText(phone);
}

QString ContactInfo::getAddress() const
{
    return ui->AddressEdit->text();
}

void ContactInfo::setAddress(const QString &address)
{
    ui->AddressEdit->setText(address);
}

Contact ContactInfo::createNewContact(QWidget *parent)
{
    ContactInfo dialog(parent);

    dialog.exec();

    if (dialog.result() != Accepted) {
        return {"","","","",""};
    }

    return {dialog.getFName(),dialog.getLName(),
        dialog.getEmail(), dialog.getPhoneNumber(),
        dialog.getAddress()};
}

Contact ContactInfo::editContact(const Contact &contact, QWidget *parent)
{
    ContactInfo dialog(parent);

    dialog.setFName(contact.firstName);
    dialog.setLName(contact.lastName);
    dialog.setEmail(contact.email);
    dialog.setPhoneNumber(contact.phoneNumber);
    dialog.setAddress(contact.address);

    dialog.exec();

    if (dialog.result() != Accepted) {
        return { "","","","","" };
    }

    return { dialog.getFName(),dialog.getLName(),
        dialog.getEmail(), dialog.getPhoneNumber(),
        dialog.getAddress() };
}

void ContactInfo::processSaveClick()
{
    if (getFName().isEmpty()) {
        QMessageBox::critical(this, "Error!", "Please provide a first name.");
        return;
    }

    accept();
}
