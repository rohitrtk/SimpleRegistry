#ifndef SRCREATEPARENT_H_
#define SRCREATEPARENT_H_

#include "SRCreateUser.h"
#include "SimpleRegistry.h"
#include "ui_SRCreateParent.h"
#include <QWidget>
#include <QKeyEvent>

namespace Ui { class SRCreateParent; };

class SRCreateParent : public QWidget, public SRCreateUser
{
	Q_OBJECT

public:
	SRCreateParent() = delete;
	SRCreateParent(SimpleRegistry* mainWindow, QWidget* parent = Q_NULLPTR);
	~SRCreateParent();

	void MakeFirstName		(PersonBuilder<Parent>& builder);
	void MakeLastName		(PersonBuilder<Parent>& builder);
	void MakeDateOfBirth	(PersonBuilder<Parent>& builder);
	void MakeGender			(PersonBuilder<Parent>& builder);
	void MakeHomeAddress	(PersonBuilder<Parent>& builder);
	void MakePrimaryPhone	(PersonBuilder<Parent>& builder);
	void MakeSecondaryPhone	(PersonBuilder<Parent>& builder);
	void MakeEmailAddress	(PersonBuilder<Parent>& builder);
	void MakeMedical		(PersonBuilder<Parent>& builder);

public slots:
	void Create() override;
	void Cancel() override;
	void Clear()  override;

protected:

	bool eventFilter(QObject*, QEvent* event) override
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
	Ui::SRCreateParent ui;

	SimpleRegistry* mainWindow;
	std::unique_ptr<Parent> user;
};

#endif
