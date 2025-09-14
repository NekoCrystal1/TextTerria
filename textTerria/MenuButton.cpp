#include "MenuButton.h"
Menu_Button::Menu_Button(Widget* parent, const Vector2& size, const Vector2& position):
	Button(parent,size, position),label(new Label(this,position,size,true))
{
	label->set_visiable();
}

Menu_Button::~Menu_Button()
{
	delete label;
}

void Menu_Button::set_text(const std::wstring& new_text)
{
	label->set_text(new_text);
	*this->m_pLocalTransform = *label->getTransform();
}

void Menu_Button::set_text_height(int height)
{
	label->set_text_height(height);
}

void Menu_Button::set_text_color(const COLORREF color)
{
	label->set_text_color(color);
}

void Menu_Button::set_text_handle_color(const COLORREF color)
{
	label->set_text_handle_color(color);
}

void Menu_Button::set_text_visiable(bool visiable)
{
	this->label->set_visiable(visiable);
}

void Menu_Button::set_position(const Vector2& vec)
{
	TObject::set_position(vec);
	this->label->set_position(vec);
}

void Menu_Button::on_update()
{
	label->on_update();
	*this->m_pLocalTransform = *label->getTransform();
	Button::on_update();
}

void Menu_Button::on_render()const
{
	if (!m_bIsVisible)
		return
	Button::on_render();
	//äÖÈ¾°´Å¥ÎÄ±¾
	label->on_render();
}

void Menu_Button::set_pushed_callback(std::function<void()> on_pushed_callback)
{
	this->on_left_click_callback = on_pushed_callback;
}
