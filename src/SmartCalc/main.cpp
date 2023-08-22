    #include <QApplication>

    #include "calculator.h"
    #include "mainwindow.h"

    int main(int argc, char *argv[]) {
      QApplication a(argc, argv);
      QIcon icon(":/icon.png");
      a.setWindowIcon(icon);

      MainWindow w;
      w.show();
      return a.exec();
    }
