#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QMessageBox>
#include <QWidget>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QWidget {
  Q_OBJECT

 public:
  explicit AnotherWindow(QWidget *parent = 0);
  ~AnotherWindow();

 signals:
  void MainWindow();

 private slots:
  void on_mainButton_clicked();
  void equal_click();

 private:
  Ui::AnotherWindow *ui;
};

#endif  // ANOTHERWINDOW_H
