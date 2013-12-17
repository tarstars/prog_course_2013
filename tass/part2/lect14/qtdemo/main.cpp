
#include "ourdialog.h"

#include <QApplication>
#include <QDialog>

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  OurDialog sam(0);
  sam.show();
  return app.exec();
}
