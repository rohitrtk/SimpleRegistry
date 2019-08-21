/********************************************************************************
** Form generated from reading UI file 'SRPopUp.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRPOPUP_H
#define UI_SRPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRPopUp
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *SRPopUp)
    {
        if (SRPopUp->objectName().isEmpty())
            SRPopUp->setObjectName(QString::fromUtf8("SRPopUp"));
        SRPopUp->resize(270, 170);
        verticalLayoutWidget = new QWidget(SRPopUp);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 251, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);

        verticalLayout_2->addWidget(label);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(SRPopUp);

        QMetaObject::connectSlotsByName(SRPopUp);
    } // setupUi

    void retranslateUi(QWidget *SRPopUp)
    {
        SRPopUp->setWindowTitle(QCoreApplication::translate("SRPopUp", "SRPopUp", nullptr));
        label->setText(QCoreApplication::translate("SRPopUp", "Warning Message", nullptr));
        pushButton->setText(QCoreApplication::translate("SRPopUp", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRPopUp: public Ui_SRPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRPOPUP_H
