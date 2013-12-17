#include "ourdialog.h"

#include <iostream>

#include <QPainter>
#include <QTimer>
#include <qwt_plot_curve.h>
#include <qwt_plot.h>

using namespace std;

OurDialog::OurDialog(QWidget *parent, Qt::WindowFlags wf) :
  QDialog(parent, wf) {
  setupUi(this);

  //  pTimer = new QTimer(this);
  //pb = new QPushButton(this);
  //pTimer -> setInterval(333);
  
  //connect(pTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));

  //pTimer -> start();

  //this->setStyleSheet("background-color: green;");

  // add curves
  QwtPlotCurve *curve1 = new QwtPlotCurve("Curve 1");

  // connect or copy the data to the curves
  const int n = 10;
  double x[n], y[n];
  for(int t = 0; t < n; t++) {
    x[t] = t;
    y[t] = t * t;
  }
  curve1->setSamples(x, y, n);

  curve1->attach(qwtPlot);

  // finally, refresh the plot
  qwtPlot -> replot();
}

void
OurDialog::timerSlot() {
  update();
}

void
OurDialog::paintEvent(QPaintEvent* pe) {
  QPainter dc(this);

  //dc.setBrush(QBrush(qRgb(255, 25, 0)));

  //static int x = 10;
  //x ++;
  //dc.drawEllipse(x, 100, 50, 50);
  //x = x % 200;
}
