#pragma once
#include "ItemManager.h"
#include "ShortcutItemButton.h"
#include "WidgetList.h"
class StorageWidget : public WidgetList{
public:
	StorageWidget(int per_row_or_colum_num, Storage* bind_storage, Widget* parent = nullptr);
	virtual ~StorageWidget();
	//void on_update() override;
	//void on_render() const override;
	void set_interval_in_row_or_col(int interval);
	void bind_elements_storage();
protected:
	Storage* bind_storage;
	//每一行或每一列
	//std::vector<WidgetList*> childs;
};