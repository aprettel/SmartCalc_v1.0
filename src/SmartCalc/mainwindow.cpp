#include "mainwindow.h"

#include "ui_mainwindow.h"
//#include "calculator.h"
#include "calculator.c"

extern "C" {
#include "calculator.h"
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // удаление
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(AC_click()));
  connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(C_click()));
  // скобки
  connect(ui->pushButton_left, SIGNAL(clicked()), this,
          SLOT(num_and_funcs_click()));
  connect(ui->pushButton_right, SIGNAL(clicked()), this,
          SLOT(num_and_funcs_click()));

  // X
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(change_X()));

  // вводимые кнопки
  QPushButton* buttons[] = {
      ui->pushButton_0,    ui->pushButton_1,    ui->pushButton_2,
      ui->pushButton_3,    ui->pushButton_4,    ui->pushButton_5,
      ui->pushButton_6,    ui->pushButton_7,    ui->pushButton_8,
      ui->pushButton_9,    ui->pushButton_plus, ui->pushButton_minus,
      ui->pushButton_pow,  ui->pushButton_mult, ui->pushButton_div,
      ui->pushButton_mod,  ui->pushButton_dot,  ui->pushButton_sin,
      ui->pushButton_cos,  ui->pushButton_tan,  ui->pushButton_asin,
      ui->pushButton_acos, ui->pushButton_atan, ui->pushButton_ln,
      ui->pushButton_log,  ui->pushButton_sqrt};

  for (QPushButton* button : buttons) {
    connect(button, SIGNAL(clicked()), this, SLOT(num_and_funcs_click()));
  }

  // подсчитываем
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal_click()));

  // Инициализируем второе окно
  creditWindow = new AnotherWindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(creditWindow, &AnotherWindow::MainWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_creditButton_clicked() {
  creditWindow->show();  // Показываем второе окно
  this->close();         // Закрываем основное окно
}

void MainWindow::num_and_funcs_click() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  QLineEdit* currentLineEdit = qobject_cast<QLineEdit*>(focusWidget());
  if (currentLineEdit == ui->lineEdit_2) {
    currentLineEdit->setText(currentLineEdit->text() + button->text());
  } else {
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
  }
}

void MainWindow::change_X() {
  ui->lineEdit_2->setFocus();
  QString inputValue = ui->lineEdit_2->text();
  double X = inputValue.toDouble();

  // Подставить значение X в выражение
  QString expression = ui->lineEdit->text();
  if (expression.contains("x")) {  // проверка наличия символа "x"
    expression.replace("x", QString::number(X));
    // Обновить значение выражения в lineEdit
    ui->lineEdit->setText(expression);
    ui->lineEdit_2->setText("");
  } else {
      QMessageBox::warning(this, "Ошибка", "Символ 'x' не найден в выражении.");
  }
}

void MainWindow::C_click() {
  if (ui->lineEdit_2->hasFocus()) {
    QString str = ui->lineEdit_2->text();
    if (!str.isEmpty()) {
      str.chop(1); 
      ui->lineEdit_2->setText(str);
    }
  } else {
    QString str = ui->lineEdit->text();
    if (!str.isEmpty()) {
      str.chop(1); 
      ui->lineEdit->setText(str);
    }
  }
}


void MainWindow::AC_click() { 
  if (ui->lineEdit_2->hasFocus()) {
      ui->lineEdit_2->setText("");
  } else {
      ui->lineEdit->setText(""); 
  }
}

void MainWindow::equal_click() {
  // Получаем введенное пользователем выражение
  QString expression = ui->lineEdit->text();

  char rpn[MAX_EXPRESSION_LENGTH];
  infixToRPN(expression.toStdString().c_str(), rpn);
  // Передаем выражение в функцию для вычисления
  double result = calculateRPN(rpn);

  // Выводим результат на экран
  ui->lineEdit->setText(QString::number(result));
}
