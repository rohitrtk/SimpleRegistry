#ifndef SRCREATECHILD_H_
#define SRCREATECHILD_H_

#include <QWidget>
#include "ui_SRCreateChild.h"
#include "SRCreateUser.h"

class QKeyEvent;
class QHideEvent;
class SimpleRegistry;
class Child;

template <class T> class PersonBuilder;

namespace Ui { class SRCreateChild; };

/* Child creation window */
class SRCreateChild : public QWidget, public SRCreateUser
{
	Q_OBJECT

public:
	SRCreateChild() = delete;
	SRCreateChild(SimpleRegistry* mainWindow, QWidget* parent = Q_NULLPTR);
	~SRCreateChild() override;

	void MakeFirstName		(PersonBuilder<Child>& builder);
	void MakeLastName		(PersonBuilder<Child>& builder);
	void MakeDateOfBirth	(PersonBuilder<Child>& builder);
	void MakeGender			(PersonBuilder<Child>& builder);
	void MakeHomeAddress	(PersonBuilder<Child>& builder);
	void MakePrimaryPhone	(PersonBuilder<Child>& builder);
	void MakeSecondaryPhone	(PersonBuilder<Child>& builder);
	void MakeEmailAddress	(PersonBuilder<Child>& builder);
	void MakePrevAttended	(PersonBuilder<Child>& builder);
	void MakeMedical		(PersonBuilder<Child>& builder);
	void MakeInterests		(PersonBuilder<Child>& builder);
	void MakeParents		(PersonBuilder<Child>& builder);
	void MakeRelation		(PersonBuilder<Child>& builder);

public slots:
	void Create() override;
	void Cancel() override;
	void Clear()  override;

protected:
	void keyPressEvent(QKeyEvent* event)	override;
	void hideEvent(QHideEvent* event)		override;

private:
	Ui::SRCreateChild ui;

	SimpleRegistry* mainWindow;
	std::unique_ptr<Child> user;
}; // SRCreateChild

#endif
