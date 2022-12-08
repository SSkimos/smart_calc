#include "graph.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) : QWidget(parent), ui(new Ui::graph)
{
    ui->setupUi(this);
}

graph::~graph()
{
    delete ui;
}

void graph::slot(QString str, double xmin, double xmax, double ymin, double ymax) {
  x.clear();
  y.clear();

  QByteArray ba = str.toLocal8Bit();
  char *str1 = ba.data();
    double h = 0.1;
    ui->widget->xAxis->setRange(xmin, xmax);
    ui->widget->yAxis->setRange(ymin, ymax);

    double X = ymin;
    for (X = xmin; X <= xmax; X += 0.001) {
      if (!std::isnan(polish(a,X) && !std::isinf(polish(a,X)))) {
        x.push_back(X);
        y.push_back(polish(str1, &X));
      }
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}
