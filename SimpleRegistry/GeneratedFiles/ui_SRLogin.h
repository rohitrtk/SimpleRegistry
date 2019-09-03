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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRLogin
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPlainTextEdit *textEdit_username;
    QLabel *label_password;
    QPlainTextEdit *textEdit_password;
    QLabel *label_username;
    QPushButton *pushButton_login;

    void setupUi(QWidget *SRLogin)
    {
        if (SRLogin->objectName().isEmpty())
            SRLogin->setObjectName(QString::fromUtf8("SRLogin"));
        SRLogin->resize(360, 160);
        formLayoutWidget = new QWidget(SRLogin);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 301, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_username = new QPlainTextEdit(formLayoutWidget);
        textEdit_username->setObjectName(QString::fromUtf8("textEdit_username"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit_username);

        label_password = new QLabel(formLayoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        QFont font;
        font.setPointSize(14);
        label_password->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_password);

        textEdit_password = new QPlainTextEdit(formLayoutWidget);
        textEdit_password->setObjectName(QString::fromUtf8("textEdit_password"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_password);

        label_username = new QLabel(formLayoutWidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_username);

        pushButton_login = new QPushButton(SRLogin);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(230, 110, 91, 31));
        pushButton_login->setFont(font);

        retranslateUi(SRLogin);

        QMetaObject::connectSlotsByName(SRLogin);
    } // setupUi

    void retranslateUi(QWidget *SRLogin)
    {
        SRLogin->setWindowTitle(QCoreApplication::translate("SRLogin", "SRLogin", nullptr));
        label_password->setText(QCoreApplication::translate("SRLogin", "Password", nullptr));
        label_username->setText(QCoreApplication::translate("SRLogin", "Username", nullptr));
        pushButton_login->setText(QCoreApplication::translate("SRLogin", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRLogin: public Ui_SRLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRLOGIN_H
