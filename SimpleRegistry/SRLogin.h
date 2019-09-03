#ifndef SRLOGIN_H_
#define SRLOGIN_H_

#include <QWidget>
#include <QSqlDatabase>

namespace Ui { class SRLogin; };

class SRLogin : public QWidget
{
	Q_OBJECT

public:
	SRLogin(QWidget *parent = Q_NULLPTR);
	~SRLogin();

public slots:
	void Login();

protected:
	bool eventFilter(QObject *watched, QEvent *event) override;

private:
	Ui::SRLogin *ui;

	std::unique_ptr<QSqlDatabase> dataBase;
};

#endif
