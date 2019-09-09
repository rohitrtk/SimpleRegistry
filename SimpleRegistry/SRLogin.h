#ifndef SRLOGIN_H_
#define SRLOGIN_H_

#include <QWidget>

class QSqlDatabase;

namespace Ui { class SRLogin; };

constexpr auto SqlType		= "QMYSQL";
constexpr auto HostName		= "localhost";
constexpr auto DatabaseName = "test";

class SRLogin : public QWidget
{
	Q_OBJECT
private:
	Ui::SRLogin *ui;

	std::unique_ptr<QSqlDatabase> dataBase;

public:
	SRLogin(QWidget *parent = Q_NULLPTR);
	~SRLogin();

public slots:
	void Login();

protected:
	void keyPressEvent(QKeyEvent *event) override;
};

#endif
