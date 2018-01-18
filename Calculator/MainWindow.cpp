#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operatorComboBox->addItem("+");
    ui->operatorComboBox->addItem("-");
    ui->operatorComboBox->addItem("x");
    ui->operatorComboBox->addItem("/");

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

    int currentOption = ui->operatorComboBox->currentIndex();
    switch (currentOption) {
    case 0: // +
        result = num1 + num2;
        break;
    case 1: // -
        result = num1 - num2;
        break;
    case 2: // x
        result = num1 * num2;
        break;
    case 3: // division
        result = num1 / num2;
        break;
    default:
        QMessageBox::warning(this, "Erro!", "Operação Inválida!");
        return;
    }

    // Show message box with result
    QMessageBox::warning(this, "Resultado", "O resultado da sua operação é: " + QString::number(result));
}
