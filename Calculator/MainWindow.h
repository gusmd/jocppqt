#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

signals:
  void digitouMerda();

private slots:
  void butaoClicado();
  void textoMudou(const QString &texto);
  void merdaFoiDigitada();

private:
  Ui::MainWindow *ui;
};
