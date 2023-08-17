#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QWidget {
  Q_OBJECT

 public:
  explicit AnotherWindow(QWidget *parent = 0);
  ~AnotherWindow();

 signals:
  void MainWindow();  // Сигнал для первого окна на открытие

 private slots:
  // Слот-обработчик нажатия кнопки
  void on_mainButton_clicked();
  void equal_click();

 private:
  Ui::AnotherWindow *ui;
};

#endif  // ANOTHERWINDOW_H
