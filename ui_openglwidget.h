/********************************************************************************
** Form generated from reading UI file 'openglwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLWIDGET_H
#define UI_OPENGLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openglwidget
{
public:

    void setupUi(QWidget *openglwidget)
    {
        if (openglwidget->objectName().isEmpty())
            openglwidget->setObjectName(QStringLiteral("openglwidget"));
        openglwidget->resize(1198, 605);

        retranslateUi(openglwidget);

        QMetaObject::connectSlotsByName(openglwidget);
    } // setupUi

    void retranslateUi(QWidget *openglwidget)
    {
        openglwidget->setWindowTitle(QApplication::translate("openglwidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class openglwidget: public Ui_openglwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLWIDGET_H
