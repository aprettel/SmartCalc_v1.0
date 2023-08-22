#include "creditwindow.h"

#include "credit_calc.c"
#include "ui_creditwindow.h"

extern "C" {
#include "credit_calc.h"
}

AnotherWindow::AnotherWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::AnotherWindow) {
  ui->setupUi(this);

  // подсчитываем
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal_click()));
}

AnotherWindow::~AnotherWindow() { delete ui; }

void AnotherWindow::on_mainButton_clicked() {
  this->close();      // Закрываем окно
  emit MainWindow();  // И вызываем сигнал на открытие главного окна
}

void AnotherWindow::equal_click() {
  // Получаем введенное пользователем выражение
  QString credit_sum_str = ui->lineEdit_1->text();
  bool ok;
  double credit_sum = credit_sum_str.toDouble(&ok);
  if (!ok) {
    QMessageBox::warning(this, "Ошибка",
                         "Некорректное значение суммы кредита.");
    return;
  }

  QString period_str = ui->lineEdit_2->text();
  QString selectedText = ui->comboBox->currentText();
  double period = 0;
  if (selectedText == "лет") {
    period = period_str.toDouble() * 12;
  } else if (selectedText == "месяцев") {
    period = period_str.toDouble();
  } else {
    QMessageBox::warning(this, "Ошибка",
                         "Необходимо выбрать единицу измерения периода.");
    return;
  }

  QString percent_str = ui->lineEdit_3->text();
  double percent = percent_str.toDouble(&ok);
  if (!ok) {
    QMessageBox::warning(this, "Ошибка",
                         "Некорректное значение процентной ставки.");
    return;
  }

  double monthly = 0.0;
  double overpay = 0.0;
  double total = 0.0;

  if (ui->radioButton_A->isChecked()) {
    monthly = A_MonthlyPayment(credit_sum, period, percent);
    overpay = A_Overpayment(credit_sum, period, monthly);
    total = TotalPayout(credit_sum, overpay);
  } else if (ui->radioButton_D->isChecked()) {
    monthly = D_MonthlyPayment(credit_sum, period, percent);
    overpay = D_Overpayment(credit_sum, period, percent);
    total = TotalPayout(credit_sum, overpay);
  } else {
    QMessageBox::warning(this, "Ошибка",
                         "Необходимо выбрать тип ежемесячного платежа");
  }

  ui->textBrowser_monthly->setText(QString::number(monthly, 'f', 2));
  ui->textBrowser_overpay->setText(QString::number(overpay, 'f', 2));
  ui->textBrowser_total->setText(QString::number(total, 'f', 2));
}
