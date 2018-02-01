#pragma once

#include <QDialog>
#include <QString>

#include "Contact.h"

namespace Ui {
class ContactInfo;
}

class ContactInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ContactInfo(QWidget *parent = nullptr);
    ~ContactInfo();

    QString getFName();
    QString getLName();
    QString getEmail();
    QString getPhoneNumber();
    QString getAddress();

    static Contact createNewContact(QWidget *parent = nullptr);

private:
    Ui::ContactInfo *ui;
};
