#include "../../Header/GameService/GameService.h"
#include "../../Header/GraphicService/GraphicService.h"


namespace GameService
{
	using namespace Global;
	using namespace Graphics;


	GameState GameService::GameServce::current_game_state = GameState::BOOT;
	GameServce::GameServce()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameServce::~GameServce()
	{
		destroy();
	}

	void GameServce::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameServce::update()
	{
		service_locator->update();
		service_locator->getInstance()->getEventService()->processEvent();
		//
	}

	void GameServce::render()
	{
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameServce::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	GameState GameServce::getState()
	{
		return current_game_state;
	}

	void GameServce::setState(GameState current_state)
	{
		current_game_state = current_state;
	}

	void GameServce::showSplashScreen()
	{
		setState(GameState::SPLASHSCREEN);
		ServiceLocator::getInstance()->getUIService()->showController();
	}

	void GameServce::initialize()
	{
		service_locator->initilize();
		initializeVariable();
		showSplashScreen();
		//current_game_state = GameState::MAINMENU;
	}

	void GameServce::initializeVariable()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameServce::destroy()
	{
		delete(game_window);
		delete(service_locator);
		service_locator = nullptr;
		game_window = nullptr;
	}

}
