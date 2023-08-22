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
  QString credit_sum_str = ui->lineEdit_1->text();
  QString period_str = ui->lineEdit_2->text();
  QString percent_str = ui->lineEdit_3->text();

  bool ok;

  double credit_sum = credit_sum_str.toDouble(&ok);
  if (!ok || credit_sum <= 0) {
    QMessageBox::warning(
        this, "Ошибка",
        "Некорректное значение суммы кредита. Введите положительное число.");
    return;
  }

  double period = period_str.toDouble(&ok);
  QString selectedText = ui->comboBox->currentText();

  if (selectedText == "лет") {
    if (!ok || period <= 0 || period > 50) {
      QMessageBox::warning(this, "Ошибка",
                           "Некорректное значение срока кредита. Введите "
                           "положительное число от 1 до 50.");
      return;
    }
    period = period_str.toDouble() * 12;
  } else if (selectedText == "месяцев") {
    if (!ok || period <= 0 || period > 600) {
      QMessageBox::warning(this, "Ошибка",
                           "Некорректное значение срока кредита. Введите "
                           "положительное число от 1 до 600.");
      return;
    }
    period = period_str.toDouble();
  } else {
    QMessageBox::warning(this, "Ошибка",
                         "Необходимо выбрать единицу измерения периода.");
    return;
  }

  double percent = percent_str.toDouble(&ok);
  if (!ok || percent <= 0 || percent > 999) {
    QMessageBox::warning(this, "Ошибка",
                         "Некорректное значение процентной ставки. Введите "
                         "положительное число до 999.");
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
    return;
  }

  ui->textBrowser_monthly->setText(QString::number(monthly, 'f', 2));
  ui->textBrowser_overpay->setText(QString::number(overpay, 'f', 2));
  ui->textBrowser_total->setText(QString::number(total, 'f', 2));
}
