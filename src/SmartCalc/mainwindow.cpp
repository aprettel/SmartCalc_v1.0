#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "calculator.h"
#include "calculator.c"

extern "C" {
    #include "calculator.h"
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // удаление
    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(AC_click()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(C_click()));
    // скобки
    connect(ui->pushButton_left, SIGNAL(clicked()), this, SLOT(num_and_funcs_click()));
    connect(ui->pushButton_right, SIGNAL(clicked()), this, SLOT(num_and_funcs_click()));

    // дописать x

    // вводимые кнопки
    QPushButton* buttons[] = { ui->pushButton_0,
                                     ui->pushButton_1,
                                     ui->pushButton_2,
                                     ui->pushButton_3,
                                     ui->pushButton_4,
                                     ui->pushButton_5,
                                     ui->pushButton_6,
                                     ui->pushButton_7,
                                     ui->pushButton_8,
                                     ui->pushButton_9,
                                     ui->pushButton_plus,
                                     ui->pushButton_minus,
                                     ui->pushButton_pow,
                                     ui->pushButton_mult,
                                     ui->pushButton_div,
                                     ui->pushButton_mod,
                                     ui->pushButton_dot,
                                     ui->pushButton_sin,
                                     ui->pushButton_cos,
                                     ui->pushButton_tan,
                                     ui->pushButton_asin,
                                     ui->pushButton_acos,
                                     ui->pushButton_atan,
                                     ui->pushButton_ln,
                                     ui->pushButton_log,
                                     ui->pushButton_sqrt};

      for (QPushButton *button : buttons) {
        connect(button, SIGNAL(clicked()), this, SLOT(num_and_funcs_click()));
      }

    // подсчитываем
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal_click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::num_and_funcs_click() {
  QPushButton* button = (QPushButton*)sender();
  if (button->text() == "cos(x)") {
       ui->lineEdit->setText(ui->lineEdit->text() + 'c');
  } else if (button->text() == "sin(x)") {
      ui->lineEdit->setText(ui->lineEdit->text() + 's');
  } else if (button->text() == "tan(x)") {
      ui->lineEdit->setText(ui->lineEdit->text() + 't');
  } else if (button->text() == "acos(x)") {
      ui->lineEdit->setText(ui->lineEdit->text() + 'C');
  } else if (button->text() == "asin(x)") {
     ui->lineEdit->setText(ui->lineEdit->text() + 'S');
  } else if (button->text() == "atan(x)") {
     ui->lineEdit->setText(ui->lineEdit->text() + 'T');
  } else if (button->text() == "sqrt(x)") {
     ui->lineEdit->setText(ui->lineEdit->text() + 'Q');
  } else if (button->text() == "ln(x)") {
      ui->lineEdit->setText(ui->lineEdit->text() + 'l');
  } else if (button->text() == "log(x)") {
      ui->lineEdit->setText(ui->lineEdit->text() + 'L');
  } else {
      ui->lineEdit->setText(ui->lineEdit->text() + button->text());
  }
}

void MainWindow::C_click()
{
    QString str = ui->lineEdit->text();
      QByteArray ba = str.toLocal8Bit();
      char* prev_char = ba.data();
      char next_char[256] = {0};
      if (!str.isNull()) {
        for (int i = 0; i < str.length() - 1; i++) {
          next_char[i] = prev_char[i];
        }
        ui->lineEdit->setText(next_char);
      }
    }

void MainWindow::AC_click()
{
    ui->lineEdit->setText("");
}


void MainWindow::equal_click()
{
    // Получаем введенное пользователем выражение
        QString expression = ui->lineEdit->text();

        // Передаем выражение в функцию для вычисления
        double result = calculate_expression(expression.toStdString().c_str());

        // Выводим результат на экран
        ui->lineEdit->setText(QString::number(result));
//        ui->lineEdit->setText((expression + "ok"));

}
