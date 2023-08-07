#include "creditwindow.h"

#include "ui_creditwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::AnotherWindow) {
  ui->setupUi(this);
}

AnotherWindow::~AnotherWindow() { delete ui; }

void AnotherWindow::on_mainButton_clicked() {
  this->close();      // Закрываем окно
  emit MainWindow();  // И вызываем сигнал на открытие главного окна
}
