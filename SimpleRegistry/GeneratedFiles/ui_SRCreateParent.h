/********************************************************************************
** Form generated from reading UI file 'SRCreateParent.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SRCREATEPARENT_H
#define UI_SRCREATEPARENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SRCreateParent
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_firstName;
    QLineEdit *lineEdit_firstName;
    QLabel *label_lastName;
    QLineEdit *lineEdit_lastName;
    QLabel *label_gender;
    QComboBox *comboBox_gender;
    QLabel *label_dateOfBirth;
    QDateEdit *dateEdit_dateOfBirth;
    QLabel *label_homeAddress;
    QLineEdit *lineEdit_homeAddress;
    QLabel *label_homePhone;
    QLineEdit *lineEdit_homePhone;
    QLabel *label_cellPhone;
    QLineEdit *lineEdit_cellPhone;
    QLabel *label_emailAddress;
    QLineEdit *lineEdit_emailAddress;
    QLabel *label_kin;
    QLineEdit *lineEdit_parentGuardians;
    QLabel *label_allergies;
    QLineEdit *lineEdit_allergies;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_create;
    QLineEdit *lineEdit_interests;
    QLabel *label_interests;

    void setupUi(QWidget *SRCreateParent)
    {
        if (SRCreateParent->objectName().isEmpty())
            SRCreateParent->setObjectName(QString::fromUtf8("SRCreateParent"));
        SRCreateParent->resize(500, 500);
        formLayoutWidget = new QWidget(SRCreateParent);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 481, 484));
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

        lineEdit_firstName = new QLineEdit(formLayoutWidget);
        lineEdit_firstName->setObjectName(QString::fromUtf8("lineEdit_firstName"));
        lineEdit_firstName->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_firstName);

        label_lastName = new QLabel(formLayoutWidget);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));
        label_lastName->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_lastName);

        lineEdit_lastName = new QLineEdit(formLayoutWidget);
        lineEdit_lastName->setObjectName(QString::fromUtf8("lineEdit_lastName"));
        lineEdit_lastName->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_lastName);

        label_gender = new QLabel(formLayoutWidget);
        label_gender->setObjectName(QString::fromUtf8("label_gender"));
        label_gender->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_gender);

        comboBox_gender = new QComboBox(formLayoutWidget);
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_gender);

        label_dateOfBirth = new QLabel(formLayoutWidget);
        label_dateOfBirth->setObjectName(QString::fromUtf8("label_dateOfBirth"));
        label_dateOfBirth->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_dateOfBirth);

        dateEdit_dateOfBirth = new QDateEdit(formLayoutWidget);
        dateEdit_dateOfBirth->setObjectName(QString::fromUtf8("dateEdit_dateOfBirth"));
        dateEdit_dateOfBirth->setFont(font);
        dateEdit_dateOfBirth->setCurrentSection(QDateTimeEdit::MonthSection);

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit_dateOfBirth);

        label_homeAddress = new QLabel(formLayoutWidget);
        label_homeAddress->setObjectName(QString::fromUtf8("label_homeAddress"));
        label_homeAddress->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_homeAddress);

        lineEdit_homeAddress = new QLineEdit(formLayoutWidget);
        lineEdit_homeAddress->setObjectName(QString::fromUtf8("lineEdit_homeAddress"));
        lineEdit_homeAddress->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_homeAddress);

        label_homePhone = new QLabel(formLayoutWidget);
        label_homePhone->setObjectName(QString::fromUtf8("label_homePhone"));
        label_homePhone->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_homePhone);

        lineEdit_homePhone = new QLineEdit(formLayoutWidget);
        lineEdit_homePhone->setObjectName(QString::fromUtf8("lineEdit_homePhone"));
        lineEdit_homePhone->setFont(font);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_homePhone);

        label_cellPhone = new QLabel(formLayoutWidget);
        label_cellPhone->setObjectName(QString::fromUtf8("label_cellPhone"));
        label_cellPhone->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_cellPhone);

        lineEdit_cellPhone = new QLineEdit(formLayoutWidget);
        lineEdit_cellPhone->setObjectName(QString::fromUtf8("lineEdit_cellPhone"));
        lineEdit_cellPhone->setFont(font);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_cellPhone);

        label_emailAddress = new QLabel(formLayoutWidget);
        label_emailAddress->setObjectName(QString::fromUtf8("label_emailAddress"));
        label_emailAddress->setFont(font);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_emailAddress);

        lineEdit_emailAddress = new QLineEdit(formLayoutWidget);
        lineEdit_emailAddress->setObjectName(QString::fromUtf8("lineEdit_emailAddress"));
        lineEdit_emailAddress->setFont(font);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_emailAddress);

        label_kin = new QLabel(formLayoutWidget);
        label_kin->setObjectName(QString::fromUtf8("label_kin"));
        label_kin->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_kin);

        lineEdit_parentGuardians = new QLineEdit(formLayoutWidget);
        lineEdit_parentGuardians->setObjectName(QString::fromUtf8("lineEdit_parentGuardians"));
        lineEdit_parentGuardians->setFont(font);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_parentGuardians);

        label_allergies = new QLabel(formLayoutWidget);
        label_allergies->setObjectName(QString::fromUtf8("label_allergies"));
        label_allergies->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_allergies);

        lineEdit_allergies = new QLineEdit(formLayoutWidget);
        lineEdit_allergies->setObjectName(QString::fromUtf8("lineEdit_allergies"));
        lineEdit_allergies->setFont(font);

        formLayout->setWidget(9, QFormLayout::FieldRole, lineEdit_allergies);

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


        formLayout->setLayout(11, QFormLayout::FieldRole, horizontalLayout_2);

        lineEdit_interests = new QLineEdit(formLayoutWidget);
        lineEdit_interests->setObjectName(QString::fromUtf8("lineEdit_interests"));
        lineEdit_interests->setFont(font);

        formLayout->setWidget(10, QFormLayout::FieldRole, lineEdit_interests);

        label_interests = new QLabel(formLayoutWidget);
        label_interests->setObjectName(QString::fromUtf8("label_interests"));
        label_interests->setFont(font);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_interests);


        retranslateUi(SRCreateParent);

        QMetaObject::connectSlotsByName(SRCreateParent);
    } // setupUi

    void retranslateUi(QWidget *SRCreateParent)
    {
        SRCreateParent->setWindowTitle(QCoreApplication::translate("SRCreateParent", "SRCreateParent", nullptr));
        label_firstName->setText(QCoreApplication::translate("SRCreateParent", "First Name", nullptr));
        label_lastName->setText(QCoreApplication::translate("SRCreateParent", "Last Name", nullptr));
        label_gender->setText(QCoreApplication::translate("SRCreateParent", "Gender", nullptr));
        label_dateOfBirth->setText(QCoreApplication::translate("SRCreateParent", "Date Of Birth", nullptr));
        dateEdit_dateOfBirth->setDisplayFormat(QCoreApplication::translate("SRCreateParent", "M/d/yyyy", nullptr));
        label_homeAddress->setText(QCoreApplication::translate("SRCreateParent", "Home Address", nullptr));
        label_homePhone->setText(QCoreApplication::translate("SRCreateParent", "Home Phone", nullptr));
        label_cellPhone->setText(QCoreApplication::translate("SRCreateParent", "Cell Phone", nullptr));
        label_emailAddress->setText(QCoreApplication::translate("SRCreateParent", "Email Address", nullptr));
        label_kin->setText(QCoreApplication::translate("SRCreateParent", "Children", nullptr));
        label_allergies->setText(QCoreApplication::translate("SRCreateParent", "Allergies", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("SRCreateParent", "Clear", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("SRCreateParent", "Cancel", nullptr));
        pushButton_create->setText(QCoreApplication::translate("SRCreateParent", "Create", nullptr));
        label_interests->setText(QCoreApplication::translate("SRCreateParent", "Interests", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SRCreateParent: public Ui_SRCreateParent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SRCREATEPARENT_H
