#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QWidget>
extern "C" {
#include "../back/calc.h"
}

namespace Ui {
class graph;
}

class graph : public QWidget {
  Q_OBJECT

public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();

public slots:
  void slot(QString str, double xmin, double xmax, double ymin, double ymax);

private:
  Ui::graph *ui;

  QVector<double> x, y;
};

#endif // GRAPH_H
