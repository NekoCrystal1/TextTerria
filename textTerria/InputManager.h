#pragma once
#include <vector>
#include <easyx.h>
#include "Singleton.hpp"
class InputManager : public Singleton<InputManager>
{
	friend Singleton<InputManager>;
public:
	//枚举按键状态
	enum class KeyStatus
	{
		ITEM_NULL,
		down,
		up,
	};
	//枚举记录鼠标状态
	enum class MouseStatus
	{
		move,
		wheel,
		l_btn_down,
		l_btn_up,
		l_btn_doubleclick,
		m_btn_down,
		m_btn_up,
		m_btn_doubleclick,
		r_btn_down,
		r_btn_up,
		r_btn_doubleclick,
	};
public:
	void on_input(const ExMessage& msg);
	void on_update();
	void clear();
	InputManager::KeyStatus at(short vk_code);
	bool is_key_down(short vk_code);
	bool is_key_up(short vk_code);
	const ExMessage& get_mouse_msg();
private:
	InputManager();
	~InputManager() = default;
private:
	//按键映射列表记录按键状态
	std::vector<InputManager::KeyStatus> key_status;
	//记录鼠标消息
	ExMessage mouse_msg;
};