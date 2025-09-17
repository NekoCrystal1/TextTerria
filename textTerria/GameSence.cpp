#include "CollisionManager.h"
#include "GameSence.h"
#include "PlatformFactory.h"
#include "ShortcutItemButton.h"
#include "StorageWidget.h"
#include "TObjectManager.h"
#include "UI_Button.h"
#include "WidgetManager.h"

GameSence::GameSence() : player(nullptr)
{
	game_background_widget = new Widget(nullptr, Vector2(getwidth(), getheight()));
	sence_objects.push_back(game_background_widget);
	game_background_widget->set_all_visiable();
}

GameSence::~GameSence()
{
}

void GameSence::on_update()
{
	Sence::on_update();
	CollisionManager::instance()->on_update();
	Camera::instance()->set_centre_position(player->getTransform()->get_centre_position());
}

void GameSence::on_enter()
{
	TObjectManager::instance()->set_output_sence(this);
	player = TObjectManager::instance()->create_player();

	ItemButton* game_ui_widget = new UI_Button(game_background_widget, game_background_widget->getTransform()->get_size());
	game_ui_widget->set_bind_storage(player->get_storage());
	game_ui_widget->set_item_id(0);
	game_ui_widget->set_left_click_callback([game_ui_widget]() {
		//printf("ui ");
		Item* item = game_ui_widget->get_item();
		if (item)
			item->on_use();
		});

	StorageWidget* player_storage_btn_list = new StorageWidget(9, player->get_storage(), game_ui_widget);
	for (int i = 0; i < 9; i++) {
		ShortcutItemButton* btn = new ShortcutItemButton(player_storage_btn_list->get_childs()[0], Vector2(48, 48));
		btn->set_background_color(0xFFEEEE);
		btn->set_background_frame_line_color(BLACK);
		btn->set_all_visiable();
		btn->set_item_id(i);
		btn->set_left_click_callback([game_ui_widget,btn,i]() {
			printf("%d ", i);
			game_ui_widget->set_item_id(btn->get_item_id());
			});
	}
	player_storage_btn_list->bind_elements_storage();
	player_storage_btn_list->set_interval(5);
	player_storage_btn_list->setLocalPosition(game_ui_widget->get_layout(0, player_storage_btn_list->getTransform()->get_size()) + Vector2(5, 5));

	load_map();
}

void GameSence::on_exit()
{
	TObjectManager::instance()->set_output_sence(nullptr);
}

void GameSence::load_map()
{
	//32像素为1格
	for (int i = 96; i < 720; i += 192)
		for (int j = -3200; j < 16000; j += 32) {
			//printf("%d,%d ",i, j);
			if (j == 32) {
				int k = 0;
				printf("%d",k);
			}
			NormalPlatform* pPlatform = PlatformFactory::instance()->tryCreateNormalPlatform(BlockId::BLOCK_TEST_PLATFORM, Vector2(j, i));
		}
	long long platform_n = sence_objects.size() - 2;
	printf("平台数量：%llu\t", platform_n);
	for (int i = -3200; i < 16000; i += 32) {
		Block* block = TObjectManager::instance()->create_block(Vector2(32,32), Vector2(i, 864));
	}
	printf("方块数量：%llu\n", sence_objects.size() - 2 - platform_n);
}
