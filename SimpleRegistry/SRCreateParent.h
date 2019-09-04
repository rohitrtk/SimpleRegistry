#ifndef SRCREATEPARENT_H_
#define SRCREATEPARENT_H_

#include <QWidget>
#include <QKeyEvent>
#include "SRCreateUser.h"
#include "SimpleRegistry.h"

namespace Ui { class SRCreateParent; };

class SRCreateParent : public QWidget, public SRCreateUser
{
	Q_OBJECT

public:
	SRCreateParent() {}
	SRCreateParent(SimpleRegistry* mainWindow, QWidget* parent = Q_NULLPTR);
	~SRCreateParent();

	void MakeFirstName		(PersonBuilder<Parent>& builder);
	void MakeLastName		(PersonBuilder<Parent>& builder);
	void MakeDateOfBirth	(PersonBuilder<Parent>& builder);
	void MakeGender			(PersonBuilder<Parent>& builder);
	void MakeHomeAddress	(PersonBuilder<Parent>& builder);
	void MakeHomePhone		(PersonBuilder<Parent>& builder);
	void MakeCellPhone		(PersonBuilder<Parent>& builder);
	void MakeEmailAddress	(PersonBuilder<Parent>& builder);
	void MakeAllergies		(PersonBuilder<Parent>& builder);

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
	Ui::SRCreateParent* ui;

	SimpleRegistry* mainWindow;
	std::unique_ptr<Parent> user;
};

#endif