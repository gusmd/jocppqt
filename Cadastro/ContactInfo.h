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

    QString getFName() const;
    void setFName(const QString &name);
    QString getLName() const;
    void setLName(const QString &lastName);
    QString getEmail() const;
    void setEmail(const QString &email);
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &phone);
    QString getAddress() const;
    void setAddress(const QString &address);


    static Contact createNewContact(QWidget *parent = nullptr);
    static Contact editContact(const Contact &contact, QWidget *parent = nullptr);

private slots:
    void processSaveClick();

private:
    Ui::ContactInfo *ui;
};
