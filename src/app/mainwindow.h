#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graph.h>

extern "C" {
    #include "../back/calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_build_clicked();

private:
    Ui::MainWindow *ui;
    graph my_graph;

private slots:
    void add_value();
    void aboba();
    void clear();
};
#endif // MAINWINDOW_H
