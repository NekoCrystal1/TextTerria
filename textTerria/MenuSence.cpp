#include "MenuSence.h"
#include "WidgetManager.h"
#include "SenceManager.h"
#include "WidgetList.h"
//extern bool is_game_runing;
extern bool is_game_runing;
MenuSence::MenuSence()
{
	//设置背景需要与窗口大小相同，设置其颜色、可见
	//menu_background_widget = WidgetManger::instance()->create_widget(Vector2(getwidth(), getheight()));
	menu_background_widget = new Widget(nullptr,Vector2(getwidth(), getheight()));
	sence_objects.push_back(menu_background_widget);
	menu_background_widget->set_background_color(0xEEEEEE);
	menu_background_widget->set_all_visiable();

	//button_list = WidgetManger::instance()->create_vertical_list();
	WidgetList* button_list = new WidgetList(menu_background_widget, WidgetList::ListMode::vertical);
	button_list->set_interval(30);
	button_list->set_visiable();

	//设置窗口标题，需要填写标题内容、设置位置
	//game_title = WidgetManger::instance()->create_label();
	Label* game_title = new Label(button_list);
	game_title->set_text(_T("Terria"));
	game_title->set_text_height(200);
	game_title->set_text_color(0x11EE11);
	game_title->set_visiable();

	//Menu_Button* btn = WidgetManger::instance()->create_menu_button();
	Menu_Button* btn = new Menu_Button(button_list);
	btn->set_left_click_callback([]() {
		SenceManager::instance()->switch_to("game"); });
	btn->set_text(_T("开始游戏"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	//btn = WidgetManger::instance()->create_menu_button();
	btn = new Menu_Button(button_list);
	btn->set_text(_T("图形"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	//btn = WidgetManger::instance()->create_menu_button();
	btn = new Menu_Button(button_list);
	btn->set_text(_T("控件"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	btn = new Menu_Button(button_list);
	btn->set_text(_T("设置"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	btn = new Menu_Button(button_list);
	btn->set_text(_T("语言"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	btn = new Menu_Button(button_list);
	btn->set_left_click_callback([]() {
		is_game_runing = false; });
	btn->set_text(_T("退出游戏"));
	btn->set_visiable();
	btn->set_text_color(0x666666);
	btn->set_text_handle_color(0x11EEEE);

	//修改列表后应重新设置位置
	button_list->set_position(menu_background_widget->get_layout(1, button_list->get_transform()->get_size()));
}

MenuSence::~MenuSence()
{
}

void MenuSence::on_enter()
{
}

void MenuSence::on_exit()
{
}
