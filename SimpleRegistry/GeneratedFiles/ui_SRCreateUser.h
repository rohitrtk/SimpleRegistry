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
    QLabel *label_firstName;
    QLabel *label_lastName;
    QLabel *label_age;
    QLabel *label_homeAddress;
    QLabel *label_homePhone;
    QLabel *label_cellPhone;
    QLabel *label_emailAddress;
    QLabel *label_dateOfBirth;
    QTextEdit *textEdit_firstName;
    QTextEdit *textEdit_lastName;
    QTextEdit *textEdit_age;
    QTextEdit *textEdit_dateOfBirth;
    QTextEdit *textEdit_homeAddress;
    QTextEdit *textEdit_homePhone;
    QTextEdit *textEdit_cellPhone;
    QTextEdit *textEdit_emailAddress;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_create;

    void setupUi(QWidget *SRCreateUser)
    {
        if (SRCreateUser->objectName().isEmpty())
            SRCreateUser->setObjectName(QString::fromUtf8("SRCreateUser"));
        SRCreateUser->resize(464, 394);
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
        label_firstName = new QLabel(formLayoutWidget);
        label_firstName->setObjectName(QString::fromUtf8("label_firstName"));
        QFont font;
        font.setPointSize(14);
        label_firstName->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_firstName);

        label_lastName = new QLabel(formLayoutWidget);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));
        label_lastName->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_lastName);

        label_age = new QLabel(formLayoutWidget);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_age);

        label_homeAddress = new QLabel(formLayoutWidget);
        label_homeAddress->setObjectName(QString::fromUtf8("label_homeAddress"));
        label_homeAddress->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_homeAddress);

        label_homePhone = new QLabel(formLayoutWidget);
        label_homePhone->setObjectName(QString::fromUtf8("label_homePhone"));
        label_homePhone->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_homePhone);

        label_cellPhone = new QLabel(formLayoutWidget);
        label_cellPhone->setObjectName(QString::fromUtf8("label_cellPhone"));
        label_cellPhone->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_cellPhone);

        label_emailAddress = new QLabel(formLayoutWidget);
        label_emailAddress->setObjectName(QString::fromUtf8("label_emailAddress"));
        label_emailAddress->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_emailAddress);

        label_dateOfBirth = new QLabel(formLayoutWidget);
        label_dateOfBirth->setObjectName(QString::fromUtf8("label_dateOfBirth"));
        label_dateOfBirth->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_dateOfBirth);

        textEdit_firstName = new QTextEdit(formLayoutWidget);
        textEdit_firstName->setObjectName(QString::fromUtf8("textEdit_firstName"));
        textEdit_firstName->setFont(font);
        textEdit_firstName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit_firstName);

        textEdit_lastName = new QTextEdit(formLayoutWidget);
        textEdit_lastName->setObjectName(QString::fromUtf8("textEdit_lastName"));
        textEdit_lastName->setFont(font);
        textEdit_lastName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_lastName);

        textEdit_age = new QTextEdit(formLayoutWidget);
        textEdit_age->setObjectName(QString::fromUtf8("textEdit_age"));
        textEdit_age->setFont(font);
        textEdit_age->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit_age);

        textEdit_dateOfBirth = new QTextEdit(formLayoutWidget);
        textEdit_dateOfBirth->setObjectName(QString::fromUtf8("textEdit_dateOfBirth"));
        textEdit_dateOfBirth->setFont(font);
        textEdit_dateOfBirth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit_dateOfBirth);

        textEdit_homeAddress = new QTextEdit(formLayoutWidget);
        textEdit_homeAddress->setObjectName(QString::fromUtf8("textEdit_homeAddress"));
        textEdit_homeAddress->setFont(font);
        textEdit_homeAddress->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_homeAddress);

        textEdit_homePhone = new QTextEdit(formLayoutWidget);
        textEdit_homePhone->setObjectName(QString::fromUtf8("textEdit_homePhone"));
        textEdit_homePhone->setFont(font);
        textEdit_homePhone->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit_homePhone);

        textEdit_cellPhone = new QTextEdit(formLayoutWidget);
        textEdit_cellPhone->setObjectName(QString::fromUtf8("textEdit_cellPhone"));
        textEdit_cellPhone->setFont(font);
        textEdit_cellPhone->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(6, QFormLayout::FieldRole, textEdit_cellPhone);

        textEdit_emailAddress = new QTextEdit(formLayoutWidget);
        textEdit_emailAddress->setObjectName(QString::fromUtf8("textEdit_emailAddress"));
        textEdit_emailAddress->setFont(font);
        textEdit_emailAddress->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit_emailAddress);

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
        label_firstName->setText(QCoreApplication::translate("SRCreateUser", "First Name", nullptr));
        label_lastName->setText(QCoreApplication::translate("SRCreateUser", "Last Name", nullptr));
        label_age->setText(QCoreApplication::translate("SRCreateUser", "Age", nullptr));
        label_homeAddress->setText(QCoreApplication::translate("SRCreateUser", "Home Address", nullptr));
        label_homePhone->setText(QCoreApplication::translate("SRCreateUser", "Home Phone", nullptr));
        label_cellPhone->setText(QCoreApplication::translate("SRCreateUser", "Cell Phone", nullptr));
        label_emailAddress->setText(QCoreApplication::translate("SRCreateUser", "Email Address", nullptr));
        label_dateOfBirth->setText(QCoreApplication::translate("SRCreateUser", "Date Of Birth", nullptr));
#if QT_CONFIG(tooltip)
        textEdit_dateOfBirth->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
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
