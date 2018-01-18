#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operatorComboBox->addItem("+");

    connect(ui->butao, &QPushButton::clicked, this, &MainWindow::computeResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::computeResult()
{
    // Read numbes from fields
    double num1 = ui->num1Edit->text().toDouble();
    double num2 = ui->num2Edit->text().toDouble();

    double result;

    // ver qual a operacao (%%%)
    // fazer n1 %%% n2
    result = num1 + num2;

    // Show message box with result
    QMessageBox::warning(this, "Resultado", "O resultado da sua operação é: " + QString::number(result));
}
