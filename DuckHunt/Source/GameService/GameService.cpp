#include "../../Header/GameService/GameService.h"
#include "../../Header/GraphicService/GraphicService.h"


namespace GameService
{
	using namespace Global;
	using namespace Graphics;
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

	void GameServce::initialize()
	{
		service_locator->initilize();
		initializeVariable();
	}

	void GameServce::initializeVariable()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameServce::destroy()
	{
		//delete(service_locator);
		//delete(game_window);
	}

}
