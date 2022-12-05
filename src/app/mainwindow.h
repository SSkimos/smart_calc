#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

private slots:
    void add_value();
    void aboba();
    void clear();
};
#endif // MAINWINDOW_H
