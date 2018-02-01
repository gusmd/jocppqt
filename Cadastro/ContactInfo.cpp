#include "ContactInfo.h"
#include "ui_ContactInfo.h"

ContactInfo::ContactInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);
}

ContactInfo::~ContactInfo()
{
    delete ui;
}
