#include "SRLogin.h"
#include "ui_SRLogin.h"
#include <QDialog>
#include <QMessageBox>
#include <QSqlError>
#include <sstream>
#include <QDebug>
#include <QKeyEvent>
#include "SimpleRegistry.h"

SRLogin::SRLogin(QWidget *parent)
	: QWidget(parent), 
	ui(new Ui::SRLogin()), 
	dataBase(std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QMYSQL")))
{
	ui->setupUi(this);

	this->ui->lineEdit_username	->installEventFilter(this);
	this->ui->lineEdit_password	->installEventFilter(this);
	this->ui->pushButton_login	->installEventFilter(this);

	this->ui->lineEdit_password	->setEchoMode(QLineEdit::Password);

	dataBase->setHostName("localhost");
	dataBase->setDatabaseName("test");

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
	}
	else
	{
		const QSqlError& err = dataBase->lastError();
		std::stringstream ss;

		ss << "Unable to connect to database!\n" << err.databaseText().toStdString() << "\n" << err.driverText().toStdString();
		QMessageBox::information(this, "Connection Error", QString::fromStdString(ss.str()));
	}
}

bool SRLogin::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);

		if (keyEvent->key() == Qt::Key_Tab)
		{
			QWidget::focusNextChild();
			return true;
		}
	}

	return false;
}
