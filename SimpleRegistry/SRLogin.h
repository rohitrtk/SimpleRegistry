#pragma once

#include <QWidget>
namespace Ui { class SRLogin; };

class SRLogin : public QWidget
{
	Q_OBJECT

public:
	SRLogin(QWidget *parent = Q_NULLPTR);
	~SRLogin();

private:
	Ui::SRLogin *ui;
};
