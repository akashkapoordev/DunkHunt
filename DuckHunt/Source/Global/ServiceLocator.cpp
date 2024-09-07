#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/GameService/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace UI;
	using namespace Enemy;
	using namespace Time;
	using namespace GameService;
	using namespace GamePlayMain;
	using namespace Player;

	//Constructor
	Global::ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;
		gameplay_service = nullptr;
		wave_service = nullptr;
		player_service = nullptr;
		enemy_service = nullptr;

		ui_service = nullptr;
		createServices();
	}

	//destructor
	ServiceLocator::~ServiceLocator()
	{
		clearServices();
	}

	//Static Service Locator so that it has only one instance 
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	//initilize
	void ServiceLocator::initilize()
	{
		graphics_service->initialize();
		event_service->initialize();
		time_service->initialize();
		gameplay_service->initialize();
		wave_service->intialize();
		player_service->initialize();
		enemy_service->initialize();
		ui_service->initialize();
	}
	//update
	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
		time_service->update();

		if (GameServce::getState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			wave_service->update();
			player_service->update();
			enemy_service->update();

		}

		ui_service->update();
	}
	//render
	void ServiceLocator::render()
	{
		graphics_service->render();
		if (GameServce::getState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			enemy_service->render();

		}

		ui_service->render();
	}

	//Get Graphic service
	Graphics::GraphicService* ServiceLocator::getGraphicService()
	{
		return graphics_service;
	}

	//Get Event Service
	Event::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	GamePlayMain::GamePlayService* ServiceLocator::getGamePlaySevice()
	{
		return gameplay_service;
	}

	Wave::Wave* ServiceLocator::getWaveService()
	{
		return wave_service;
	}

	Player::PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}





	UI::UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	Enemy::EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	Time::TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	// Creating services
	void ServiceLocator::createServices()
	{
		graphics_service = new GraphicService();
		event_service = new EventService();
		time_service = new TimeService();
		gameplay_service = new GamePlayService();
		wave_service = new Wave::Wave();
		player_service = new PlayerService();
		enemy_service = new EnemyService();
		ui_service = new UIService();

	}

	//clearing services
	void ServiceLocator::clearServices()
	{
		delete(graphics_service);
		delete(time_service);
		delete(event_service);
		delete(gameplay_service);
		delete(wave_service);
		delete(player_service);
		delete(enemy_service);
		delete(ui_service);
	}
}

