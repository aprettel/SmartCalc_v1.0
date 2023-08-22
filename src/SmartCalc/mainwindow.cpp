#include "mainwindow.h"

#include "calculator.c"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_creditButton_clicked() {
  creditWindow = new AnotherWindow();
  connect(creditWindow, &AnotherWindow::MainWindow, this, &MainWindow::show);
  creditWindow->show();
  this->close();
}

void MainWindow::on_graphButton_clicked() {
  ui->plot->clearGraphs();
  ui->plot->addGraph();

  ui->plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);

  QString expr = ui->lineEdit->text();
  QRegularExpression validExpression(
      "[\\+\\%\\-\\*/"
      "\\.^\\(\\)\\s\\d|(?:(?:sin|cos|tan|asin|acos|atan|log|lg|sqrt)\\())]*");
  if (!validExpression.match(expr).hasMatch()) {
    QMessageBox::warning(this, "Ошибка", "Некорректное выражение функции.");
    return;
  }

  bool ok;
  double x1 = ui->lineEdit_2->text().toDouble(&ok);  // min X
  if (!ok) {
    QMessageBox::warning(this, "Ошибка",
                         "Некорректное значение минимального X.");
    return;
  }
  double x2 = ui->lineEdit_3->text().toDouble(&ok);  // max X
  if (!ok) {
    QMessageBox::warning(this, "Ошибка",
                         "Некорректное значение максимального X.");
    return;
  }

  if ((x1 >= -1000000 && x1 <= 1000000) && (x2 >= -1000000 && x2 <= 1000000)) {
    double step = 0.01;

    QVector<double> xData;
    QVector<double> yData;

    if (x1 < x2) {
      while (x1 <= x2) {
        QString exprWithValue = expr;
        exprWithValue.replace("x", QString::number(x1, 'f', 6));

        char rpn[MAX_EXPRESSION_LENGTH];
        infixToRPN(exprWithValue.toStdString().c_str(), rpn);
        double result = calculateRPN(rpn);
        xData.append(x1);
        yData.append(result);

        x1 += step;
      }

      ui->plot->graph(0)->setData(xData, yData);
      ui->plot->xAxis->setRange(xData.first(), xData.last());
      ui->plot->yAxis->setRange(
          *std::min_element(yData.constBegin(), yData.constEnd()),
          *std::max_element(yData.constBegin(), yData.constEnd()));

      QCPAxisRect* rect = ui->plot->axisRect();
      rect->setRangeZoomAxes(ui->plot->xAxis, ui->plot->yAxis);
      rect->setRangeDragAxes(ui->plot->xAxis, ui->plot->yAxis);
      rect->setRangeZoom(Qt::Horizontal | Qt::Vertical);

      ui->plot->replot();
    } else {
      QMessageBox::warning(
          this, "Ошибка",
          "Некорректное значение минимального X и максимального X.");
      return;
    }
  } else {
    QMessageBox::warning(
        this, "Ошибка",
        "Область определения и область значения функций должны быть ограничены "
        "числами от -1000000 до 1000000.");
  }
}

void MainWindow::num_and_funcs_click() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());
  QLineEdit* currentLineEdit = qobject_cast<QLineEdit*>(focusWidget());
  if (currentLineEdit == ui->lineEdit_2) {
    currentLineEdit->setText(currentLineEdit->text() + button->text());
  } else if (currentLineEdit == ui->lineEdit_3) {
    currentLineEdit->setText(currentLineEdit->text() + button->text());
  } else if (currentLineEdit == ui->lineEdit) {
    ui->lineEdit->setText(ui->lineEdit->text() + button->text());
  }
}

void MainWindow::change_X() {
  ui->lineEdit_2->setFocus();
  QString inputValue = ui->lineEdit_2->text();
  double X = inputValue.toDouble();

  // подставить значение X в выражение
  QString expression = ui->lineEdit->text();
  if (expression.contains("x")) {  // проверка наличия символа "x"
    expression.replace("x", QString::number(X, 'f', 6));
    // обновить значение выражения в lineEdit
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
  } else if (ui->lineEdit_3->hasFocus()) {
    QString str = ui->lineEdit_3->text();
    if (!str.isEmpty()) {
      str.chop(1);
      ui->lineEdit_3->setText(str);
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
  } else if (ui->lineEdit_3->hasFocus()) {
    ui->lineEdit_3->setText("");
  } else {
    ui->lineEdit->setText("");
  }
}

void MainWindow::equal_click() {
  QString expression = ui->lineEdit->text();
  // Проверка наличия числа или операции перед скобкой
  if (expression.contains(")(") || expression.startsWith(")")) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
    return;
  }

  // Проверка наличия точки перед или после другой точки
  if (expression.contains("..") || expression.startsWith(".") ||
      expression.endsWith(".")) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
    return;
  }

  // Проверка правильного использования скобок
  int openParenthesesCount = expression.count("(");
  int closeParenthesesCount = expression.count(")");
  if (openParenthesesCount != closeParenthesesCount) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
    return;
  }

  QRegularExpression validExpression(
      "[\\+\\%\\-\\*/"
      "\\.^\\(\\)\\s\\d|(?:(?:sin|cos|tan|asin|acos|atan|log|lg|sqrt)\\())]*");
  QRegularExpressionValidator validatorExpression(validExpression, this);
  int pos = 0;
  QValidator::State state = validatorExpression.validate(expression, pos);

  if (state != QValidator::Acceptable) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
  }

  char rpn[MAX_EXPRESSION_LENGTH];
  infixToRPN(expression.toStdString().c_str(), rpn);
  double result = calculateRPN(rpn);

  if (std::isinf(result) || std::isnan(result)) {
    ui->lineEdit->setText("Error");
    return;
  }

  ui->lineEdit->setText(QString::number(result, 'f', 6));
}
