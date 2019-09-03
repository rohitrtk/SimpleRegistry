#include "SRLogin.h"
#include "ui_SRLogin.h"

SRLogin::SRLogin(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::SRLogin();
	ui->setupUi(this);
}

SRLogin::~SRLogin()
{
	delete ui;
}
