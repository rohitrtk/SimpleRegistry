/********************************************************************************
** Form generated from reading UI file 'SimpleRegistry.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLEREGISTRY_H
#define UI_SIMPLEREGISTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleRegistryClass
{
public:
    QAction *actionCreate_Parent;
    QAction *actionCreate_Child;
    QAction *actionSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimpleRegistryClass)
    {
        if (SimpleRegistryClass->objectName().isEmpty())
            SimpleRegistryClass->setObjectName(QString::fromUtf8("SimpleRegistryClass"));
        SimpleRegistryClass->resize(1280, 720);
        actionCreate_Parent = new QAction(SimpleRegistryClass);
        actionCreate_Parent->setObjectName(QString::fromUtf8("actionCreate_Parent"));
        actionCreate_Child = new QAction(SimpleRegistryClass);
        actionCreate_Child->setObjectName(QString::fromUtf8("actionCreate_Child"));
        actionSave = new QAction(SimpleRegistryClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralWidget = new QWidget(SimpleRegistryClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font;
        font.setPointSize(12);
        tableView->setFont(font);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);

        verticalLayout->addWidget(tableView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        SimpleRegistryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimpleRegistryClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        SimpleRegistryClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimpleRegistryClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SimpleRegistryClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SimpleRegistryClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SimpleRegistryClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionCreate_Parent);
        menuFile->addAction(actionCreate_Child);

        retranslateUi(SimpleRegistryClass);

        QMetaObject::connectSlotsByName(SimpleRegistryClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimpleRegistryClass)
    {
        SimpleRegistryClass->setWindowTitle(QCoreApplication::translate("SimpleRegistryClass", "SimpleRegistry", nullptr));
        actionCreate_Parent->setText(QCoreApplication::translate("SimpleRegistryClass", "Create Parent", nullptr));
        actionCreate_Child->setText(QCoreApplication::translate("SimpleRegistryClass", "Create Child", nullptr));
        actionSave->setText(QCoreApplication::translate("SimpleRegistryClass", "Save", nullptr));
        menuFile->setTitle(QCoreApplication::translate("SimpleRegistryClass", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("SimpleRegistryClass", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimpleRegistryClass: public Ui_SimpleRegistryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEREGISTRY_H
