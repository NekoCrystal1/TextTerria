#include "StorageWidget.h"

StorageWidget::StorageWidget(int per_row_or_colum_num, Storage* bind_storage, Widget* parent) : 
	WidgetList(parent, ListMode::vertical, 0),bind_storage(bind_storage)
{
	//childs = std::vector<Widget*>
	//	(bind_storage->get_size() / per_row_or_colum_num + (bind_storage->get_size() % per_row_or_colum_num ? 1 : 0), new WidgetList(this));
	int n = bind_storage->get_size() / per_row_or_colum_num + (bind_storage->get_size() % per_row_or_colum_num ? 1 : 0);
	childs.reserve(n);
	for (int i = 0; i < n; i++)
		new WidgetList(this, ListMode::horizontal, 0);
}

StorageWidget::~StorageWidget()
{
}

void StorageWidget::set_interval_in_row_or_col(int interval)
{
	for (Widget* i : childs) {
		WidgetList* i_list = dynamic_cast<WidgetList*>(i);
		if(i_list)
			i_list->set_interval(interval);
	}
}

void StorageWidget::bind_elements_storage()
{
	for (Widget* i : childs)
	{
		WidgetList* i_list = dynamic_cast<WidgetList*>(i);
		if (i_list) {
			i_list->set_interval(interval);
			for (Widget* j : i->get_childs()) {
				ItemButton* i_btn = dynamic_cast<ItemButton*>(j);
				if (i_btn)
					i_btn->set_bind_storage(this->bind_storage);
			}
		}
	}
}
