/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_str;
    QPushButton *pushButton_ans;
    QLineEdit *lineEdit_ans;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_LBr;
    QPushButton *pushButton_RBr;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_div;
    QPushButton *pushButton_S;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QLineEdit *lineEdit_x_val;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_C;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_min;
    QPushButton *pushButton_T;
    QHBoxLayout *horizontalLayout_19;
    QLineEdit *lineEdit_x_min;
    QLineEdit *lineEdit_x_max;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_v;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_14;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_x;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_L;
    QHBoxLayout *horizontalLayout_20;
    QLineEdit *lineEdit_y_min;
    QLineEdit *lineEdit_y_max;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_s;
    QPushButton *pushButton_c;
    QPushButton *pushButton_t;
    QPushButton *pushButton_l;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_build;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(669, 495);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 647, 471));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineEdit_str = new QLineEdit(layoutWidget);
        lineEdit_str->setObjectName("lineEdit_str");

        horizontalLayout_10->addWidget(lineEdit_str);

        pushButton_ans = new QPushButton(layoutWidget);
        pushButton_ans->setObjectName("pushButton_ans");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_ans->sizePolicy().hasHeightForWidth());
        pushButton_ans->setSizePolicy(sizePolicy);
        pushButton_ans->setMinimumSize(QSize(20, 20));
        pushButton_ans->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_10->addWidget(pushButton_ans);

        lineEdit_ans = new QLineEdit(layoutWidget);
        lineEdit_ans->setObjectName("lineEdit_ans");
        sizePolicy.setHeightForWidth(lineEdit_ans->sizePolicy().hasHeightForWidth());
        lineEdit_ans->setSizePolicy(sizePolicy);
        lineEdit_ans->setMinimumSize(QSize(50, 0));

        horizontalLayout_10->addWidget(lineEdit_ans);


        horizontalLayout_9->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_LBr = new QPushButton(layoutWidget);
        pushButton_LBr->setObjectName("pushButton_LBr");
        pushButton_LBr->setMinimumSize(QSize(61, 61));
        pushButton_LBr->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(174, 173, 172);\n"
"	color: black;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout->addWidget(pushButton_LBr);

        pushButton_RBr = new QPushButton(layoutWidget);
        pushButton_RBr->setObjectName("pushButton_RBr");
        pushButton_RBr->setMinimumSize(QSize(61, 61));
        pushButton_RBr->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(174, 173, 172);\n"
"	color: black;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout->addWidget(pushButton_RBr);

        pushButton_mod = new QPushButton(layoutWidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setMinimumSize(QSize(61, 61));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(174, 173, 172);\n"
"	color: black;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout->addWidget(pushButton_mod);

        pushButton_div = new QPushButton(layoutWidget);
        pushButton_div->setObjectName("pushButton_div");
        pushButton_div->setMinimumSize(QSize(61, 61));
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout->addWidget(pushButton_div);

        pushButton_S = new QPushButton(layoutWidget);
        pushButton_S->setObjectName("pushButton_S");
        pushButton_S->setMinimumSize(QSize(61, 61));
        pushButton_S->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout->addWidget(pushButton_S);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        label_16->setFont(font);

        horizontalLayout_18->addWidget(label_16);

        lineEdit_x_val = new QLineEdit(layoutWidget);
        lineEdit_x_val->setObjectName("lineEdit_x_val");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_x_val->sizePolicy().hasHeightForWidth());
        lineEdit_x_val->setSizePolicy(sizePolicy2);
        lineEdit_x_val->setMinimumSize(QSize(50, 0));

        horizontalLayout_18->addWidget(lineEdit_x_val);


        horizontalLayout->addLayout(horizontalLayout_18);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(61, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(61, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setMinimumSize(QSize(61, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}\n"
""));

        horizontalLayout_2->addWidget(pushButton_9);

        pushButton_mult = new QPushButton(layoutWidget);
        pushButton_mult->setObjectName("pushButton_mult");
        pushButton_mult->setMinimumSize(QSize(61, 61));
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_mult);

        pushButton_C = new QPushButton(layoutWidget);
        pushButton_C->setObjectName("pushButton_C");
        pushButton_C->setMinimumSize(QSize(61, 61));
        pushButton_C->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_C);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(16);
        label_7->setFont(font1);

        verticalLayout_4->addWidget(label_7);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        horizontalLayout_16->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");
        label_12->setFont(font);

        horizontalLayout_16->addWidget(label_12);


        verticalLayout_4->addLayout(horizontalLayout_16);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(61, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(61, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(61, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_min = new QPushButton(layoutWidget);
        pushButton_min->setObjectName("pushButton_min");
        pushButton_min->setMinimumSize(QSize(61, 61));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_min);

        pushButton_T = new QPushButton(layoutWidget);
        pushButton_T->setObjectName("pushButton_T");
        pushButton_T->setMinimumSize(QSize(61, 61));
        pushButton_T->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_T);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        lineEdit_x_min = new QLineEdit(layoutWidget);
        lineEdit_x_min->setObjectName("lineEdit_x_min");
        sizePolicy2.setHeightForWidth(lineEdit_x_min->sizePolicy().hasHeightForWidth());
        lineEdit_x_min->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(lineEdit_x_min);

        lineEdit_x_max = new QLineEdit(layoutWidget);
        lineEdit_x_max->setObjectName("lineEdit_x_max");
        sizePolicy2.setHeightForWidth(lineEdit_x_max->sizePolicy().hasHeightForWidth());
        lineEdit_x_max->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(lineEdit_x_max);


        horizontalLayout_3->addLayout(horizontalLayout_19);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setMinimumSize(QSize(61, 61));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(61, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(61, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_plus = new QPushButton(layoutWidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setMinimumSize(QSize(61, 61));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_plus);

        pushButton_v = new QPushButton(layoutWidget);
        pushButton_v->setObjectName("pushButton_v");
        pushButton_v->setMinimumSize(QSize(61, 61));
        pushButton_v->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_4->addWidget(pushButton_v);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");
        sizePolicy3.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy3);
        label_13->setFont(font1);

        verticalLayout_5->addWidget(label_13);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        horizontalLayout_17->addWidget(label_14);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");
        label_15->setFont(font);

        horizontalLayout_17->addWidget(label_15);


        verticalLayout_6->addLayout(horizontalLayout_17);


        verticalLayout_5->addLayout(verticalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_0 = new QPushButton(layoutWidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setMinimumSize(QSize(61, 61));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_5->addWidget(pushButton_0);

        pushButton_dot = new QPushButton(layoutWidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setMinimumSize(QSize(61, 61));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_5->addWidget(pushButton_dot);

        pushButton_x = new QPushButton(layoutWidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setMinimumSize(QSize(61, 61));
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color:  rgb(93, 91, 89);\n"
"	color: white;\n"
"	border: 1px rgb(134, 132, 130);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_5->addWidget(pushButton_x);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        pushButton_exp = new QPushButton(layoutWidget);
        pushButton_exp->setObjectName("pushButton_exp");
        pushButton_exp->setMinimumSize(QSize(61, 61));
        pushButton_exp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_11->addWidget(pushButton_exp);

        pushButton_L = new QPushButton(layoutWidget);
        pushButton_L->setObjectName("pushButton_L");
        pushButton_L->setMinimumSize(QSize(61, 61));
        pushButton_L->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_11->addWidget(pushButton_L);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        lineEdit_y_min = new QLineEdit(layoutWidget);
        lineEdit_y_min->setObjectName("lineEdit_y_min");
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_y_min->sizePolicy().hasHeightForWidth());
        lineEdit_y_min->setSizePolicy(sizePolicy4);

        horizontalLayout_20->addWidget(lineEdit_y_min);

        lineEdit_y_max = new QLineEdit(layoutWidget);
        lineEdit_y_max->setObjectName("lineEdit_y_max");
        sizePolicy2.setHeightForWidth(lineEdit_y_max->sizePolicy().hasHeightForWidth());
        lineEdit_y_max->setSizePolicy(sizePolicy2);

        horizontalLayout_20->addWidget(lineEdit_y_max);


        horizontalLayout_11->addLayout(horizontalLayout_20);


        horizontalLayout_5->addLayout(horizontalLayout_11);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pushButton_s = new QPushButton(layoutWidget);
        pushButton_s->setObjectName("pushButton_s");
        pushButton_s->setMinimumSize(QSize(61, 61));
        pushButton_s->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: gray;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_s);

        pushButton_c = new QPushButton(layoutWidget);
        pushButton_c->setObjectName("pushButton_c");
        pushButton_c->setMinimumSize(QSize(61, 61));
        pushButton_c->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_c);

        pushButton_t = new QPushButton(layoutWidget);
        pushButton_t->setObjectName("pushButton_t");
        pushButton_t->setMinimumSize(QSize(61, 61));
        pushButton_t->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_t);

        pushButton_l = new QPushButton(layoutWidget);
        pushButton_l->setObjectName("pushButton_l");
        pushButton_l->setMinimumSize(QSize(61, 61));
        pushButton_l->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_l);

        pushButton_clear = new QPushButton(layoutWidget);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setMinimumSize(QSize(61, 61));
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: grey;\n"
"	color: white;\n"
"	border: 1px gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_clear);

        pushButton_build = new QPushButton(layoutWidget);
        pushButton_build->setObjectName("pushButton_build");
        sizePolicy2.setHeightForWidth(pushButton_build->sizePolicy().hasHeightForWidth());
        pushButton_build->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(20);
        pushButton_build->setFont(font2);
        pushButton_build->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 151, 57);\n"
"	color: white;\n"
"	border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: qlinegradient(x1: 0, y1: 0, x2: 0, y2: 1\n"
"	stop: 0 #FF7832, stop: 1 #FF9739)\n"
"}"));

        horizontalLayout_7->addWidget(pushButton_build);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_ans->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_LBr->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_RBr->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_S->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "X = ", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "X Min:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "X Max:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_min->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_T->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        lineEdit_x_min->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        lineEdit_x_max->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_v->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\273\320\260\321\201\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Y Min:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Y Max:", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_L->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        lineEdit_y_min->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
        lineEdit_y_max->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        pushButton_s->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_c->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_t->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_l->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_build->setText(QCoreApplication::translate("MainWindow", "Build", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
