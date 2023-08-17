#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <creditwindow.h>

#include <QMainWindow>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  // Слоты от кнопок главного окна
  void on_creditButton_clicked();

  void num_and_funcs_click();
  void C_click();
  void AC_click();
  void equal_click();
  void change_X();

 private:
  Ui::MainWindow *ui;
  AnotherWindow *creditWindow;
};
#endif  // MAINWINDOW_H
