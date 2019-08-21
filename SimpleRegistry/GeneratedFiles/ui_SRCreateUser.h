/********************************************************************************
** Form generated from reading UI file 'SRCreateUser.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRCREATEUSER_H
#define UI_SRCREATEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRCreateUser
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QTextEdit *textEdit_firstName;
    QLabel *label_lastName;
    QTextEdit *textEdit_lastName;
    QLabel *label_age;
    QTextEdit *textEdit_age;
    QLabel *label_dateOfBirth;
    QTextEdit *textEdit_dateOfBirth;
    QLabel *label_var1;
    QTextEdit *textEdit_var1;
    QLabel *label_var2;
    QTextEdit *textEdit_var2;
    QLabel *label_var3;
    QTextEdit *textEdit_var3;
    QLabel *label_var4;
    QTextEdit *textEdit_var4;
    QLabel *label_firstName;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_create;

    void setupUi(QWidget *SRCreateUser)
    {
        if (SRCreateUser->objectName().isEmpty())
            SRCreateUser->setObjectName(QString::fromUtf8("SRCreateUser"));
        SRCreateUser->resize(465, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SRCreateUser->sizePolicy().hasHeightForWidth());
        SRCreateUser->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(SRCreateUser);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 461, 331));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_firstName = new QTextEdit(formLayoutWidget);
        textEdit_firstName->setObjectName(QString::fromUtf8("textEdit_firstName"));
        QFont font;
        font.setPointSize(14);
        textEdit_firstName->setFont(font);
        textEdit_firstName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit_firstName);

        label_lastName = new QLabel(formLayoutWidget);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));
        label_lastName->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_lastName);

        textEdit_lastName = new QTextEdit(formLayoutWidget);
        textEdit_lastName->setObjectName(QString::fromUtf8("textEdit_lastName"));
        textEdit_lastName->setFont(font);
        textEdit_lastName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_lastName);

        label_age = new QLabel(formLayoutWidget);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_age);

        textEdit_age = new QTextEdit(formLayoutWidget);
        textEdit_age->setObjectName(QString::fromUtf8("textEdit_age"));
        textEdit_age->setFont(font);
        textEdit_age->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit_age);

        label_dateOfBirth = new QLabel(formLayoutWidget);
        label_dateOfBirth->setObjectName(QString::fromUtf8("label_dateOfBirth"));
        label_dateOfBirth->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_dateOfBirth);

        textEdit_dateOfBirth = new QTextEdit(formLayoutWidget);
        textEdit_dateOfBirth->setObjectName(QString::fromUtf8("textEdit_dateOfBirth"));
        textEdit_dateOfBirth->setFont(font);
        textEdit_dateOfBirth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit_dateOfBirth);

        label_var1 = new QLabel(formLayoutWidget);
        label_var1->setObjectName(QString::fromUtf8("label_var1"));
        label_var1->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_var1);

        textEdit_var1 = new QTextEdit(formLayoutWidget);
        textEdit_var1->setObjectName(QString::fromUtf8("textEdit_var1"));
        textEdit_var1->setFont(font);
        textEdit_var1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_var1);

        label_var2 = new QLabel(formLayoutWidget);
        label_var2->setObjectName(QString::fromUtf8("label_var2"));
        label_var2->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_var2);

        textEdit_var2 = new QTextEdit(formLayoutWidget);
        textEdit_var2->setObjectName(QString::fromUtf8("textEdit_var2"));
        textEdit_var2->setFont(font);
        textEdit_var2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit_var2);

        label_var3 = new QLabel(formLayoutWidget);
        label_var3->setObjectName(QString::fromUtf8("label_var3"));
        label_var3->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_var3);

        textEdit_var3 = new QTextEdit(formLayoutWidget);
        textEdit_var3->setObjectName(QString::fromUtf8("textEdit_var3"));
        textEdit_var3->setFont(font);
        textEdit_var3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(6, QFormLayout::FieldRole, textEdit_var3);

        label_var4 = new QLabel(formLayoutWidget);
        label_var4->setObjectName(QString::fromUtf8("label_var4"));
        label_var4->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_var4);

        textEdit_var4 = new QTextEdit(formLayoutWidget);
        textEdit_var4->setObjectName(QString::fromUtf8("textEdit_var4"));
        textEdit_var4->setFont(font);
        textEdit_var4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit_var4);

        label_firstName = new QLabel(formLayoutWidget);
        label_firstName->setObjectName(QString::fromUtf8("label_firstName"));
        label_firstName->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_firstName);

        horizontalLayoutWidget = new QWidget(SRCreateUser);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 340, 267, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_clear = new QPushButton(horizontalLayoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setFont(font);

        horizontalLayout_2->addWidget(pushButton_clear);

        pushButton_cancel = new QPushButton(horizontalLayoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setFont(font);

        horizontalLayout_2->addWidget(pushButton_cancel);

        pushButton_create = new QPushButton(horizontalLayoutWidget);
        pushButton_create->setObjectName(QString::fromUtf8("pushButton_create"));
        pushButton_create->setFont(font);

        horizontalLayout_2->addWidget(pushButton_create);


        retranslateUi(SRCreateUser);

        QMetaObject::connectSlotsByName(SRCreateUser);
    } // setupUi

    void retranslateUi(QWidget *SRCreateUser)
    {
        SRCreateUser->setWindowTitle(QCoreApplication::translate("SRCreateUser", "Create New Parent", nullptr));
        label_lastName->setText(QCoreApplication::translate("SRCreateUser", "Last Name", nullptr));
        label_age->setText(QCoreApplication::translate("SRCreateUser", "Age", nullptr));
        label_dateOfBirth->setText(QCoreApplication::translate("SRCreateUser", "Date Of Birth", nullptr));
#if QT_CONFIG(tooltip)
        textEdit_dateOfBirth->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_var1->setText(QCoreApplication::translate("SRCreateUser", "Home Address", nullptr));
        label_var2->setText(QCoreApplication::translate("SRCreateUser", "Home Phone", nullptr));
        label_var3->setText(QCoreApplication::translate("SRCreateUser", "Cell Phone", nullptr));
        label_var4->setText(QCoreApplication::translate("SRCreateUser", "Email Address", nullptr));
        label_firstName->setText(QCoreApplication::translate("SRCreateUser", "First Name", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("SRCreateUser", "Clear", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("SRCreateUser", "Cancel", nullptr));
        pushButton_create->setText(QCoreApplication::translate("SRCreateUser", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRCreateUser: public Ui_SRCreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRCREATEUSER_H
