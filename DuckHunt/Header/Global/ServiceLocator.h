#pragma once
#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/EventService/EventService.h"
#include "../../Header/UIService/UIService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/GamePlayService/GamePlayService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Wave/Wave.h"


namespace Global
{
	class ServiceLocator
	{
	public:
		ServiceLocator();
		~ServiceLocator();

		static ServiceLocator* getInstance();

		void initilize();
		void update();
		void render();

		Graphics::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		GamePlayMain::GamePlayService* getGamePlaySevice();
		Wave::Wave* getWaveService();
		Player::PlayerService* getPlayerService();
		Enemy::EnemyService* getEnemyService();
		Time::TimeService* getTimeService();
		UI::UIService* getUIService();

	
	private:
		void createServices();
		void clearServices();

		Graphics::GraphicService* graphics_service;
		Event::EventService* event_service;
		GamePlayMain::GamePlayService* gameplay_service;
		Wave::Wave* wave_service;
		Player::PlayerService* player_service;
		Enemy::EnemyService* enemy_service;
		Time::TimeService* time_service;
		UI::UIService* ui_service;

	};
}