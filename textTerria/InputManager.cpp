#include "InputManager.h"

void InputManager::on_input(const ExMessage& msg)
{
	//按键虚拟键码即位映射表索引，且由枚举确定状态
	switch (msg.message)
	{
	case WM_KEYDOWN:
		key_status[msg.vkcode] = KeyStatus::down;
		break;
	case WM_KEYUP:
		key_status[msg.vkcode] = KeyStatus::up;
		break;
	default:
		mouse_msg = msg;
		break;
	}
}

void InputManager::on_update()
{
	//每次使用完后清空输入
	clear();
}

void InputManager::clear()
{
	for (InputManager::KeyStatus& i : key_status)
		//只有抬起的按键输入会被清空
		if(i == KeyStatus::up)
			i = KeyStatus::null;
	mouse_msg = ExMessage();
}

//读取时直接读取键码值表项
InputManager::KeyStatus InputManager::at(short vk_code)
{
	return key_status[vk_code];
}

bool InputManager::is_key_down(short vk_code)
{
	return key_status[vk_code] == KeyStatus::down;
}

bool InputManager::is_key_up(short vk_code)
{
	return key_status[vk_code] == KeyStatus::up;
}

const ExMessage& InputManager::get_mouse_msg()
{
	return mouse_msg;
}

//一共有255个虚拟键码值，列表大小为255
InputManager::InputManager() : key_status(0xFF),mouse_msg()
{
}
