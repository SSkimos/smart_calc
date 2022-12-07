#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) : QWidget(parent), ui(new Ui::graph)
{
    ui->setupUi(this);
//    double h = 0.1;
//    ui->widget->xAxis->setRange(-4, 4);
//    ui->widget->yAxis->setRange(0, 9);

//    double X = -3;
//    for (X = -3; X <= 3 + 0.1; X+= 0.1) {
//        x.push_back(X);
//        y.push_back(X*X);
//    }
//    ui->widget->addGraph();
//    ui->widget->graph(0)->addData(x, y);
//    ui->widget->replot();
}

graph::~graph()
{
    delete ui;
}

void graph::slot(QString str, double xmin, double xmax, double ymin, double ymax) {
//  x.clear();
//  y.clear();
//  ui->widget->xAxis->setRange(xmin, xmax);
//  ui->widget->yAxis->setRange(ymin, ymax);

//  QByteArray ba = str.toLocal8Bit();
//  char *str1 = ba.data();

//  int N = 500;
//  int h = (xmax - xmin)/N;
//  int i = 0;

//  double X = ymin;

//  for (X = xmin; X <= xmax; X += h) {
//    if (X <= xmax) {
//        double a = polish(str1, &X);
//        x.push_back(X);
//        y.push_back(polish(str1, &X));
//    }
//  }
//  ui->widget->addGraph();
//  ui->widget->graph(0)->addData(x, y);
//  ui->widget->replot();
    double h = 0.1;
    ui->widget->xAxis->setRange(-4, 4);
    ui->widget->yAxis->setRange(0, 9);

    double X = -3;
    for (X = -3; X <= 3 + 0.1; X+= 0.1) {
        x.push_back(X);
        y.push_back(X*X);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}
