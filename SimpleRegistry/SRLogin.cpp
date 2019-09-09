#include "SRLogin.h"
#include "ui_SRLogin.h"

#include "SimpleRegistry.h"

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QKeyEvent>
#include <QString>

SRLogin::SRLogin(QWidget *parent)
	: QWidget(parent), 
	ui(new Ui::SRLogin()), 
	dataBase(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase(SqlType)))
{
	ui->setupUi(this);
	ui->lineEdit_password->setEchoMode(QLineEdit::Password);

	dataBase->setHostName(HostName);
	dataBase->setDatabaseName(DatabaseName);

	connect(ui->pushButton_login, SIGNAL(clicked()), this, SLOT(Login()));
}

SRLogin::~SRLogin()
{
	delete ui;
}

void SRLogin::Login()
{
	dataBase->setUserName(ui->lineEdit_username->text());
	dataBase->setPassword(ui->lineEdit_password->text());

	if (dataBase->open())
	{
		SimpleRegistry* sr = new SimpleRegistry(std::move(dataBase));
		sr->setAttribute(Qt::WA_DeleteOnClose);
		sr->show();
		this->close();
		return;
	}
	
	const QSqlError& err = dataBase->lastError();

	QString s = "Unable to connect to database\n";

	s += err.databaseText() + "\n" + err.driverText();
	
	QMessageBox::information(this, "Connection Error", s);
}

void SRLogin::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Tab)
	{
		QWidget::focusNextChild();
	}
	else if (event->key() == Qt::Key_Return)
	{
		Login();
	}

	QWidget::keyPressEvent(event);
}
