#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->butao, &QPushButton::clicked, this, &MainWindow::butaoClicado);
    connect(ui->text, &QLineEdit::textChanged, this, &MainWindow::textoMudou);
    connect(this, &MainWindow::digitouMerda, this, &MainWindow::merdaFoiDigitada);

    textoMudou(ui->text->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textoMudou(const QString &texto)
{
    ui->butao->setDisabled(texto.isEmpty());

    if (texto == "merda") {
        emit digitouMerda();
    }
}

void MainWindow::merdaFoiDigitada()
{
   QMessageBox::warning(this, "Ahh", "Seu merda");
}

void MainWindow::butaoClicado()
{
    QString texto = ui->text->text();
    QMessageBox::warning(this, "Ahh", texto);
}
