/********************************************************************************
** Form generated from reading UI file 'SRCreateChild.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRCREATECHILD_H
#define UI_SRCREATECHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRCreateChild
{
public:

    void setupUi(QWidget *SRCreateChild)
    {
        if (SRCreateChild->objectName().isEmpty())
            SRCreateChild->setObjectName(QString::fromUtf8("SRCreateChild"));
        SRCreateChild->resize(400, 300);

        retranslateUi(SRCreateChild);

        QMetaObject::connectSlotsByName(SRCreateChild);
    } // setupUi

    void retranslateUi(QWidget *SRCreateChild)
    {
        SRCreateChild->setWindowTitle(QCoreApplication::translate("SRCreateChild", "SRCreateChild", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRCreateChild: public Ui_SRCreateChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRCREATECHILD_H
