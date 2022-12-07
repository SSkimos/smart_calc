/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graph
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *widget;

    void setupUi(QWidget *graph)
    {
        if (graph->objectName().isEmpty())
            graph->setObjectName("graph");
        graph->resize(400, 300);
        gridLayout = new QGridLayout(graph);
        gridLayout->setObjectName("gridLayout");
        widget = new QCustomPlot(graph);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(graph);

        QMetaObject::connectSlotsByName(graph);
    } // setupUi

    void retranslateUi(QWidget *graph)
    {
        graph->setWindowTitle(QCoreApplication::translate("graph", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph: public Ui_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
