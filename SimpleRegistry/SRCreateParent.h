#ifndef SRCREATEPARENT_H_
#define SRCREATEPARENT_H_

#include <QWidget>
#include "ui_SRCreateParent.h"
#include "SRCreateUser.h"

class QKeyEvent;
class QHideEvent;
class SimpleRegistry;
class Parent;

template <class T> class PersonBuilder;

namespace Ui { class SRCreateParent; };

/* Parent creation window */
class SRCreateParent : public QWidget, public SRCreateUser
{
	Q_OBJECT

public:
	SRCreateParent() = delete;
	SRCreateParent(SimpleRegistry* mainWindow, QWidget* parent = Q_NULLPTR);
	~SRCreateParent() override;

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

	void keyPressEvent(QKeyEvent* event)	override;
	void hideEvent(QHideEvent* event)		override;

private:
	Ui::SRCreateParent ui;

	SimpleRegistry* mainWindow;
	std::unique_ptr<Parent> user;
}; // SRCreateParent

#endif
