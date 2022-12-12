#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>

extern "C" {
#include "../back/calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void signal(QString str, double xmin, double xmax, double ymin, double ymax);

private:
  Ui::MainWindow *ui;
  graph *my_graph;

private slots:
  void add_value();
  void aboba();
  void clear();
  void on_pushButton_build_clicked();
};
#endif // MAINWINDOW_H
