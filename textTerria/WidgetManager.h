//#pragma once
//#include <vector>
//#include "MenuButton.h"
//#include "VerticalWidgetList.h"
//#include "HorizontalWidgetList.h"
//#include "ShortcutItemButton.h"
//#include "StorageWidget.h"
//class WidgetManger {
//public:
//	static WidgetManger* instance();
//public:
//	void on_update();
//	void on_render()const;
//	Widget* create_widget(const Vector2& size = Vector2(), const Vector2& position = Vector2());
//	Label* create_label(const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool is_handle_scale = false);
//	Button* create_button(const Vector2& size = Vector2(), const Vector2& position = Vector2());
//	Menu_Button* create_menu_button(const Vector2& size = Vector2(), const Vector2& position = Vector2());
//	ShortcutItemButton* create_shortcutItem_button(const Vector2& size = Vector2(), const Vector2& position = Vector2());
//	StorageWidget* create_storage_widget(int per_row_or_colum_num, Storage* bind_storage);
//	VerticalWidgetList* create_vertical_list(const Vector2& size = Vector2(), const Vector2& position = Vector2(), int interval = 0, int original_interval = 0);
//	HorizontalWidgetList* create_horizontal_list(const Vector2& size = Vector2(), const Vector2& position = Vector2(), int interval = 0, int original_interval = 0);
//private:
//	WidgetManger();
//	~WidgetManger();
//	
//private:
//	static WidgetManger* manager;
//private:
//	std::vector<Widget*> widgets;
//};