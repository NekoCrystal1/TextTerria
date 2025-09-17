#pragma once
#include "Sence.h"
#include "MenuButton.h"
#include "VerticalWidgetList.h"
#include "Animation.h"
class MenuSence : public Sence {
public:
	MenuSence();
	~MenuSence();
	virtual void on_render() const override;
	virtual void on_update() override;
	void on_enter()override;
	void on_exit()override;
private:
	Widget* menu_background_widget;
};