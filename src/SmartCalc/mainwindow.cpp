#include "mainwindow.h"

#include "ui_mainwindow.h"
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

  // инициализируем второе окно
  creditWindow = new AnotherWindow();
  // подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(creditWindow, &AnotherWindow::MainWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_creditButton_clicked() {
  creditWindow->show();  // показываем второе окно
  this->close();         // закрываем основное окно
}

void MainWindow::on_graphButton_clicked() {
    // Получаем данные из LineEdit
        QString expression = ui->lineEdit->text(); // Введенное пользователем выражение

        // Очищаем график
        ui->plot->clearGraphs();

        // Создаем график функции
        ui->plot->addGraph();

        // Добавление обработчика событий колесика мыши
        ui->plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);

        // Установка масштабируемости и перемещения графика по оси x и y
        ui->plot->axisRect()->setRangeZoomAxes(ui->plot->xAxis, ui->plot->yAxis);
        ui->plot->axisRect()->setRangeDragAxes(ui->plot->xAxis, ui->plot->yAxis);

        // Подготавливаем переменные для вычисления функции
        double x = ui->lineEdit_2->text().toDouble(); // min X
        double y = ui->lineEdit_3->text().toDouble(); // max X
        double step = 0.01; // Шаг изменения аргумента x

        QVector<double> xData;
        QVector<double> yData;

        // Перебираем точки и вычисляем значение функции
        while (x <= y) {
            // Создаем выражение с аргументом x
            QString expr = expression;
            expr.replace("x", QString::number(x));

            // Конвертируем в обратную польскую запись
            char rpn[MAX_EXPRESSION_LENGTH];
            infixToRPN(expr.toStdString().c_str(), rpn);

            // Вычисляем значение выражения
            double result = calculateRPN(rpn);

            // Добавляем значения в векторы xData и yData
            xData.append(x);
            yData.append(result);

            // Увеличиваем x на шаг
            x += step;
        }

        // Добавляем значения в график
        ui->plot->graph(0)->setData(xData, yData);

        // Устанавливаем подписи осей
//        ui->plot->xAxis->setLabel("x");
//        ui->plot->yAxis->setLabel("y");

        // Устанавливаем интервалы осей
        ui->plot->xAxis->setRange(xData.first(), xData.last());
        ui->plot->yAxis->setRange(*std::min_element(yData.constBegin(), yData.constEnd()),
                                  *std::max_element(yData.constBegin(), yData.constEnd()));

        // Обновляем график
        ui->plot->replot();
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
    expression.replace("x", QString::number(X));
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
  // получаем введенное пользователем выражение
  QString expression = ui->lineEdit->text();

  char rpn[MAX_EXPRESSION_LENGTH];
  infixToRPN(expression.toStdString().c_str(), rpn);
  // передаем выражение в функцию для вычисления
  double result = calculateRPN(rpn);

  // выводим результат на экран
  ui->lineEdit->setText(QString::number(result, 'f', 6));
}


