#pragma once

#include <QMainWindow>
#include <QList>

#include "Contact.h"

class QListWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addContact();
    void deleteContact();
    void editContactOnClick(QListWidgetItem *item);

    void storeNewContactList(const QList<Contact> contacts);

    void populateContactsFromJson();

private:
    void updateContactList();

    Ui::MainWindow *ui;

    QList<Contact> m_contacts;
};
