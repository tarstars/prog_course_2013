#pragma once

#include <QDialog>
#include <QPushButton>

#include "ui_demodialog.h"

class OurDialog : public QDialog, public Ui::DemoDialog {
  Q_OBJECT

    QTimer *pTimer;
  QPushButton *pb;

    protected:
  void paintEvent(QPaintEvent*);
    public:
  OurDialog(QWidget *parent, Qt::WindowFlags wf = 0);

  public slots:
  void timerSlot();
};
