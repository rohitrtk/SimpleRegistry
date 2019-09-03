/********************************************************************************
** Form generated from reading UI file 'SRLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRLOGIN_H
#define UI_SRLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRLogin
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_username;
    QLabel *label_password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;

    void setupUi(QWidget *SRLogin)
    {
        if (SRLogin->objectName().isEmpty())
            SRLogin->setObjectName(QString::fromUtf8("SRLogin"));
        SRLogin->resize(342, 140);
        formLayoutWidget = new QWidget(SRLogin);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 321, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_username = new QLabel(formLayoutWidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        QFont font;
        font.setPointSize(14);
        label_username->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_username);

        label_password = new QLabel(formLayoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_password);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_login = new QPushButton(formLayoutWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setFont(font);

        horizontalLayout->addWidget(pushButton_login);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        lineEdit_username = new QLineEdit(formLayoutWidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        lineEdit_password = new QLineEdit(formLayoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        retranslateUi(SRLogin);

        QMetaObject::connectSlotsByName(SRLogin);
    } // setupUi

    void retranslateUi(QWidget *SRLogin)
    {
        SRLogin->setWindowTitle(QCoreApplication::translate("SRLogin", "SRLogin", nullptr));
        label_username->setText(QCoreApplication::translate("SRLogin", "Username", nullptr));
        label_password->setText(QCoreApplication::translate("SRLogin", "Password", nullptr));
        pushButton_login->setText(QCoreApplication::translate("SRLogin", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRLogin: public Ui_SRLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRLOGIN_H
