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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
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
    QTextEdit *textEdit_firstName;
    QLabel *label_lastName;
    QTextEdit *textEdit_lastName;
    QLabel *label_dateOfBirth;
    QDateEdit *dateEdit_dateOfBirth;
    QLabel *label_homeAddress;
    QTextEdit *textEdit_homeAddress;
    QLabel *label_homePhone;
    QTextEdit *textEdit_homePhone;
    QLabel *label_cellPhone;
    QTextEdit *textEdit_cellPhone;
    QLabel *label_emailAddress;
    QTextEdit *textEdit_emailAddress;
    QLabel *label_prevLocation;
    QLabel *label_YearsAttended;
    QCheckBox *checkBox_prevAttended;
    QTextEdit *textEdit_prevLocation;
    QTextEdit *textEdit_yearsAttended;
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
        formLayoutWidget->setGeometry(QRect(0, 0, 461, 391));
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

        textEdit_firstName = new QTextEdit(formLayoutWidget);
        textEdit_firstName->setObjectName(QString::fromUtf8("textEdit_firstName"));
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

        label_dateOfBirth = new QLabel(formLayoutWidget);
        label_dateOfBirth->setObjectName(QString::fromUtf8("label_dateOfBirth"));
        label_dateOfBirth->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_dateOfBirth);

        dateEdit_dateOfBirth = new QDateEdit(formLayoutWidget);
        dateEdit_dateOfBirth->setObjectName(QString::fromUtf8("dateEdit_dateOfBirth"));
        dateEdit_dateOfBirth->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit_dateOfBirth);

        label_homeAddress = new QLabel(formLayoutWidget);
        label_homeAddress->setObjectName(QString::fromUtf8("label_homeAddress"));
        label_homeAddress->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_homeAddress);

        textEdit_homeAddress = new QTextEdit(formLayoutWidget);
        textEdit_homeAddress->setObjectName(QString::fromUtf8("textEdit_homeAddress"));
        textEdit_homeAddress->setFont(font);
        textEdit_homeAddress->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit_homeAddress);

        label_homePhone = new QLabel(formLayoutWidget);
        label_homePhone->setObjectName(QString::fromUtf8("label_homePhone"));
        label_homePhone->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_homePhone);

        textEdit_homePhone = new QTextEdit(formLayoutWidget);
        textEdit_homePhone->setObjectName(QString::fromUtf8("textEdit_homePhone"));
        textEdit_homePhone->setFont(font);
        textEdit_homePhone->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_homePhone);

        label_cellPhone = new QLabel(formLayoutWidget);
        label_cellPhone->setObjectName(QString::fromUtf8("label_cellPhone"));
        label_cellPhone->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_cellPhone);

        textEdit_cellPhone = new QTextEdit(formLayoutWidget);
        textEdit_cellPhone->setObjectName(QString::fromUtf8("textEdit_cellPhone"));
        textEdit_cellPhone->setFont(font);
        textEdit_cellPhone->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit_cellPhone);

        label_emailAddress = new QLabel(formLayoutWidget);
        label_emailAddress->setObjectName(QString::fromUtf8("label_emailAddress"));
        label_emailAddress->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_emailAddress);

        textEdit_emailAddress = new QTextEdit(formLayoutWidget);
        textEdit_emailAddress->setObjectName(QString::fromUtf8("textEdit_emailAddress"));
        textEdit_emailAddress->setFont(font);
        textEdit_emailAddress->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(6, QFormLayout::FieldRole, textEdit_emailAddress);

        label_prevLocation = new QLabel(formLayoutWidget);
        label_prevLocation->setObjectName(QString::fromUtf8("label_prevLocation"));
        label_prevLocation->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_prevLocation);

        label_YearsAttended = new QLabel(formLayoutWidget);
        label_YearsAttended->setObjectName(QString::fromUtf8("label_YearsAttended"));
        label_YearsAttended->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_YearsAttended);

        checkBox_prevAttended = new QCheckBox(formLayoutWidget);
        checkBox_prevAttended->setObjectName(QString::fromUtf8("checkBox_prevAttended"));
        checkBox_prevAttended->setFont(font);

        formLayout->setWidget(7, QFormLayout::FieldRole, checkBox_prevAttended);

        textEdit_prevLocation = new QTextEdit(formLayoutWidget);
        textEdit_prevLocation->setObjectName(QString::fromUtf8("textEdit_prevLocation"));
        textEdit_prevLocation->setFont(font);
        textEdit_prevLocation->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_prevLocation->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(8, QFormLayout::FieldRole, textEdit_prevLocation);

        textEdit_yearsAttended = new QTextEdit(formLayoutWidget);
        textEdit_yearsAttended->setObjectName(QString::fromUtf8("textEdit_yearsAttended"));
        textEdit_yearsAttended->setFont(font);
        textEdit_yearsAttended->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_yearsAttended->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(9, QFormLayout::FieldRole, textEdit_yearsAttended);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_clear = new QPushButton(formLayoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setFont(font);

        horizontalLayout_2->addWidget(pushButton_clear);

        pushButton_cancel = new QPushButton(formLayoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setFont(font);

        horizontalLayout_2->addWidget(pushButton_cancel);

        pushButton_create = new QPushButton(formLayoutWidget);
        pushButton_create->setObjectName(QString::fromUtf8("pushButton_create"));
        pushButton_create->setFont(font);

        horizontalLayout_2->addWidget(pushButton_create);


        formLayout->setLayout(10, QFormLayout::FieldRole, horizontalLayout_2);


        retranslateUi(SRCreateUser);

        QMetaObject::connectSlotsByName(SRCreateUser);
    } // setupUi

    void retranslateUi(QWidget *SRCreateUser)
    {
        SRCreateUser->setWindowTitle(QCoreApplication::translate("SRCreateUser", "Create New User", nullptr));
        label_firstName->setText(QCoreApplication::translate("SRCreateUser", "First Name", nullptr));
        label_lastName->setText(QCoreApplication::translate("SRCreateUser", "Last Name", nullptr));
        label_dateOfBirth->setText(QCoreApplication::translate("SRCreateUser", "Date Of Birth", nullptr));
        label_homeAddress->setText(QCoreApplication::translate("SRCreateUser", "Home Address", nullptr));
        label_homePhone->setText(QCoreApplication::translate("SRCreateUser", "Home Phone", nullptr));
        label_cellPhone->setText(QCoreApplication::translate("SRCreateUser", "Cell Phone", nullptr));
        label_emailAddress->setText(QCoreApplication::translate("SRCreateUser", "Email Address", nullptr));
        label_prevLocation->setText(QCoreApplication::translate("SRCreateUser", "Previous Location", nullptr));
        label_YearsAttended->setText(QCoreApplication::translate("SRCreateUser", "Years Attended", nullptr));
        checkBox_prevAttended->setText(QCoreApplication::translate("SRCreateUser", "Previously Attended?", nullptr));
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
