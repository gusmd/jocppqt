#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDoubleValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator *validator = new QDoubleValidator(-10000.0, 10000.0, 3, this);
    ui->num1Edit->setValidator(validator);
    ui->num2Edit->setValidator(validator);
	ui->num3Edit->setValidator(validator);
    
    connect(ui->butao, &QPushButton::clicked, this, &MainWindow::computeResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::computeResult()
{
    // Read numbes from fields
    double num1 = ui->num1Edit->text().toDouble();//Ultima quantidade de curtidas
    double num2 = ui->num2Edit->text().toDouble();//Atual quantidade de curtidas
    double num3 = ui->num3Edit->text().toDouble();//Quantidade de curtidas pagas

    double result = num2 - num1; //Quantidade que aumentou
    double result0 = ((num2 / num1) - 1) * 100; //Percentual de aumento das curtidas
    double result1 = result - num3; //Curtidas Organicas
    double result2 = (result1 / result) * 100; //Percentual das curtidas organicas

    QString msg = QString("Aumentou: %0 Curtidas" "\n"
        "Percentual de aumento: %1%" "\n"
        "Quantidade de curtidas Orgânicas: %2" "\n"
        "Percentual de curtidas orgânicas: %3%").arg(
        QString::number(result),
        QString::number(result0, 'f', 1),
        QString::number(result1),
        QString::number(result2, 'f', 1));


    // Show message box with result
    QMessageBox::information(this, "Resultado", msg);
}
