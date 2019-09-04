#ifndef SRCREATECHILD_H_
#define SRCREATECHILD_H_

#include <QWidget>
#include <QKeyEvent>
#include "SRCreateUser.h"
#include "SimpleRegistry.h"

namespace Ui { class SRCreateChild; };

class SRCreateChild : public QWidget, public SRCreateUser
{
	Q_OBJECT

public:
	SRCreateChild() {}
	SRCreateChild(SimpleRegistry* mainWindow, QWidget* parent = Q_NULLPTR);
	~SRCreateChild();

	void MakeFirstName		(PersonBuilder<Child>& builder);
	void MakeLastName		(PersonBuilder<Child>& builder);
	void MakeDateOfBirth	(PersonBuilder<Child>& builder);
	void MakeGender			(PersonBuilder<Child>& builder);
	void MakeHomeAddress	(PersonBuilder<Child>& builder);
	void MakeHomePhone		(PersonBuilder<Child>& builder);
	void MakeCellPhone		(PersonBuilder<Child>& builder);
	void MakeEmailAddress	(PersonBuilder<Child>& builder);
	void MakePrevAttended	(PersonBuilder<Child>& builder);
	void MakePrevLocation	(PersonBuilder<Child>& builder);
	void MakeYearsAttended	(PersonBuilder<Child>& builder);
	void MakeAllergies		(PersonBuilder<Child>& builder);

public slots:
	void Create() override;
	void Cancel() override;
	void Clear()  override;

protected:

	bool eventFilter(QObject* object, QEvent* event) override
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
		else if (event->type() == QEvent::Hide)
		{
			this->Clear();
		}

		return false;
	}

private:
	Ui::SRCreateChild* ui;

	SimpleRegistry* mainWindow;
	std::unique_ptr<Child> user;
};

#endif