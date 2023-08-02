#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
  void num_and_funcs_click();
  void C_click();
  void AC_click();
  void equal_click();

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
