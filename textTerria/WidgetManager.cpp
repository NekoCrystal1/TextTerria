//#include "WidgetManager.h"
//WidgetManger* WidgetManger::manager = nullptr;
//WidgetManger* WidgetManger::instance()
//{
//    if (!manager)
//        manager = new WidgetManger();
//    return manager;
//}
//
//WidgetManger::WidgetManger() {
//}
//
//WidgetManger::~WidgetManger()
//{
//    delete manager;
//}
//
//void WidgetManger::on_update()
//{
//    for (Widget* i : widgets)
//        i->on_update();
//}
//
//void WidgetManger::on_render() const
//{
//    for (Widget* i : widgets)
//        i->on_render();
//}
//
//Widget* WidgetManger::create_widget(const Vector2& size, const Vector2& position)
//{
//    widgets.push_back(new Widget(size, position));
//    return widgets.back();
//}
//
//Label* WidgetManger::create_label(const Vector2& size, const Vector2& position, bool is_handle_scale)
//{
//    Label* label = new Label(size, position, is_handle_scale);
//    widgets.push_back(label);
//    return label;
//}
//
//Button* WidgetManger::create_button(const Vector2& size, const Vector2& position)
//{
//    Button* button = new Menu_Button(size, position);
//    widgets.push_back(button);
//    return button;
//}
//
//Menu_Button* WidgetManger::create_menu_button(const Vector2& size, const Vector2& position)
//{
//    Menu_Button* button = new Menu_Button(size, position);
//    widgets.push_back(button);
//    return button;
//}
//
//ShortcutItemButton* WidgetManger::create_shortcutItem_button(const Vector2& size, const Vector2& position)
//{
//    ShortcutItemButton* btn = new ShortcutItemButton(size, position);
//    widgets.push_back(btn);
//    return btn;
//}
//
//StorageWidget* WidgetManger::create_storage_widget(int per_row_or_colum_num, Storage* bind_storage)
//{
//    StorageWidget* storage_w = new StorageWidget(per_row_or_colum_num,bind_storage);
//    widgets.push_back(storage_w);
//    return storage_w;
//}
//
//VerticalWidgetList* WidgetManger::create_vertical_list(const Vector2& size, const Vector2& position, int interval, int original_interval)
//{
//    VerticalWidgetList* vertical_widget_list = new VerticalWidgetList(size, position, interval, original_interval);
//    widgets.push_back(vertical_widget_list);
//    return vertical_widget_list;
//}
//
//HorizontalWidgetList* WidgetManger::create_horizontal_list(const Vector2& size, const Vector2& position, int interval, int original_interval)
//{
//    HorizontalWidgetList* horizontal_widget_list = new HorizontalWidgetList(size, position, interval, original_interval);
//    widgets.push_back(horizontal_widget_list);
//    return horizontal_widget_list;
//}
//
