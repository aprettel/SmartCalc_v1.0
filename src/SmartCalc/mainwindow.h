#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QString>
#include <QVector>

#include "creditwindow.h"

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
  void on_creditButton_clicked();
  void on_graphButton_clicked();
  void num_and_funcs_click();
  void C_click();
  void AC_click();
  void equal_click();
  void change_X();
  bool isValidExpression(const QString &expression);

 private:
  Ui::MainWindow *ui;
  AnotherWindow *creditWindow;
};

#endif  // MAINWINDOW_H
