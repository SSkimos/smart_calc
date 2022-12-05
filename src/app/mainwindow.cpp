#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::aboba()
{
    QString old_label;
    old_label = ui->label_str->text();
    QByteArray ba = old_label.toLocal8Bit();
    char *buffer = ba.data();
    long double value = polish(buffer);
    QString toStr = QString::number(value,'g',6);
    ui->label_show->setText(toStr);

}

void MainWindow::clear()
{
    QString first_label;
    first_label = "";
    ui->label_str->setText(first_label);

    QString second_label;
    second_label = "";
    ui->label_show->setText(second_label);
}

void MainWindow::add_value()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->label_str->text() + button->text();

    ui->label_str->setText(new_label);
}

