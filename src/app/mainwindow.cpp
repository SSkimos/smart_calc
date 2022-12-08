#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    delete my_graph;
    my_graph = new graph();

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_LBr, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_RBr, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_min, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_s, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_c, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_t, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_S, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_T, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_l, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_L, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(add_value()));
    connect(ui->pushButton_v, SIGNAL(clicked()), this, SLOT(add_value()));

    connect(ui->pushButton_ans, SIGNAL(clicked()), this, SLOT(aboba()));

    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->pushButton_build, SIGNAL(clicked()), this, SLOT(on_pushButton_build_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::aboba()
{
    QString old_label;
    old_label = ui->lineEdit_str->text();
    QByteArray ba = old_label.toLatin1();
    char *buffer = ba.data();

    QString x_val;
    x_val = ui->lineEdit_x_val->text();
    double x = ui->lineEdit_x_val->text().toDouble();

    double value = polish(buffer, &x);

    QString toStr = QString().asprintf("%0.6f", value);
    ui->lineEdit_ans->setText(toStr);
}

void MainWindow::clear()
{
    QString first_label;
    first_label = "";
    ui->lineEdit_str->setText(first_label);

    QString second_label;
    second_label = "";
    ui->lineEdit_ans->setText(second_label);
}

void MainWindow::add_value()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->lineEdit_str->text() + button->text();

    ui->lineEdit_str->setText(new_label);
}


void MainWindow::on_pushButton_build_clicked()
{
    connect(this, &MainWindow::signal, my_graph, &graph::slot);
    emit signal(ui->lineEdit_str->text(), ui->lineEdit_x_min->text().toDouble(),
                  ui->lineEdit_x_max->text().toDouble(), ui->lineEdit_y_min->text().toDouble(),
                  ui->lineEdit_y_max->text().toDouble());
    my_graph->show();
}

