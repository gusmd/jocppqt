#include "ContactInfo.h"
#include "ui_ContactInfo.h"

ContactInfo::ContactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);

    connect(ui->SaveButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->CancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

ContactInfo::~ContactInfo()
{
    delete ui;
}

QString ContactInfo::getFName()
{
    return ui->FnameEdit->text();
}

QString ContactInfo::getLName()
{
    return ui->LnameEdit->text();
}

QString ContactInfo::getEmail()
{
    return ui->EmailEdit->text();
}

QString ContactInfo::getPhoneNumber()
{
    return ui->PhoneEdit->text();
}

QString ContactInfo::getAddress()
{
    return ui->AddressEdit->text();
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
