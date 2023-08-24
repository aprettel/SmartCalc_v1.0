#include "mainwindow.h"

#include "../calculator.c"
#include "ui_mainwindow.h"

extern "C" {
#include "../calculator.h"
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->lineEdit->setReadOnly(true);
  ui->lineEdit_2->setReadOnly(true);
  ui->lineEdit_3->setReadOnly(true);

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
        exprWithValue.replace("x", QString::number(x1, 'f', 7));

        char rpn[MAX_EXPRESSION_LENGTH];
        infixToRPN(exprWithValue.toStdString().c_str(), rpn);
        double result = calculateRPN(rpn);
        xData.append(x1);
        yData.append(result);
        x1 += step;
      }

      ui->plot->graph(0)->setData(xData, yData);
      ui->plot->xAxis->setRange(xData.first(), xData.last());
      ui->plot->yAxis->setRange(-5, 5);

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

  bool ok;
  double X = inputValue.toDouble(&ok);

  if (ok) {
    QString expression = ui->lineEdit->text();

    if (expression.contains("x")) {
      expression.replace("x", QString::number(X));
      ui->lineEdit->setText(expression);
      ui->lineEdit_2->setText("");
    } else {
      QMessageBox::warning(this, "Ошибка", "Символ 'x' не найден в выражении.");
    }
  } else {
    QMessageBox::warning(this, "Ошибка",
                         "Введено некорректное значение для X.");
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

  // Проверка на наличие ошибок в выражении
  if (!isValidExpression(expression)) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
    ui->lineEdit->setText("Error");
    return;
  }

  // Преобразование выражения в ОПН
  char rpn[MAX_EXPRESSION_LENGTH];
  infixToRPN(expression.toStdString().c_str(), rpn);

  // Вычисление результата
  double result = calculateRPN(rpn);

  // Проверка на наличие ошибок в результате
  if (std::isinf(result) || std::isnan(result)) {
    QMessageBox::warning(this, "Ошибка", "Недопустимое выражение!");
    ui->lineEdit->setText("Error");
    return;
  }

  // Отображение результата
  ui->lineEdit->setText(QString::number(result, 'f', 7));
}

bool MainWindow::isValidExpression(const QString& expression) {
  // Проверка наличия точки
  QRegularExpression invalidNumberRegex("\\d+\\.\\d+\\.");
  if (expression.contains(invalidNumberRegex)) {
    return false;
  }

  if (expression.contains("..") ||
      (expression.contains("\\.\\d") && expression.indexOf("\\.\\d") != 0) ||
      (expression.contains("\\d\\.") && expression.indexOf("\\d\\.") != 0)) {
    return false;
  }

  // Проверка правильного использования скобок
  int openParenthesesCount = expression.count("(");
  int closeParenthesesCount = expression.count(")");
  if (expression.contains(")(") ||
      openParenthesesCount != closeParenthesesCount) {
    return false;
  }

  // Проверка наличия пустых скобок
  QRegularExpression emptyParenthesesRegex("\\(\\s*\\)");
  if (expression.contains(emptyParenthesesRegex)) {
    return false;
  }

  // Проверка наличия недопустимых последовательностей операторов
  QRegularExpression multipleOperatorRegex("[\\+\\-\\*/%^]{2,}");
  if (expression.contains(multipleOperatorRegex)) {
    return false;
  }

  QRegularExpression numberBeforeDotRegex("(?<!\\d)00\\.[\\d]+");
  if (expression.contains(numberBeforeDotRegex)) {
    return false;
  }

  // Проверка наличия букв перед и после скобками
  QRegularExpression invalidCharacterRegex("[a-zA-Z]+\\(|\\)[a-zA-Z]+");
  if (expression.contains(invalidNumberRegex) ||
      expression.contains(invalidCharacterRegex)) {
    return false;
  }

  // Проверка выражения с помощью валидатора
  QRegularExpression validExpression(
      "[\\+\\%\\-\\*/"
      "\\.^\\(\\)\\s\\d|(?:(?:sin|cos|tan|asin|acos|atan|log|lg|sqrt)\\())]*");
  QRegularExpressionValidator validatorExpression(validExpression, this);
  int pos = 0;
  QString expressionCopy = expression;
  QValidator::State state = validatorExpression.validate(expressionCopy, pos);
  if (state != QValidator::Acceptable) {
    return false;
  }

  return true;
}
