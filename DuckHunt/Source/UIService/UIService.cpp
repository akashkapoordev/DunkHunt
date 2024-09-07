#include "../../Header/UIService/UIService.h"
#include "../../Header/GameService/GameService.h"
#include "../../Header/Global/ServiceLocator.h";


namespace UI
{
	using namespace UI::MainMenu;
	using namespace UI::GamePlayUI;
	using namespace interface;
	using namespace GameService;
	using namespace Global;
	UIService::UIService()
	{
		splashscreen_controller = nullptr;
		mainmenu_controller = nullptr;
		gameplay_controller = nullptr;
	
		createController();
	}
	UIService::~UIService()
	{
		destroy();
	}
	void UIService::initialize()
	{
		initializeController();
	}
	void UIService::update()
	{

		IUIController* ui_controller = getCurrentController();
		if (ui_controller) ui_controller->update();
	}
	void UIService::render()
	{

		IUIController* ui_controller = getCurrentController();
		if (ui_controller) ui_controller->render();
	}
	UI::interface::IUIController* UIService::getCurrentController()
	{
		switch (GameServce::getState())
		{
		case GameState::SPLASHSCREEN:
			return splashscreen_controller;
		case GameState::MAINMENU:
			return mainmenu_controller;
		case GameState::GAMEPLAY:
			//printf("Gameplay service");
			return gameplay_controller;
		 default:
			return nullptr;
		}
	}
	void UIService::createController()
	{
		splashscreen_controller = new SplashScreen::SplashScreenUIController();
		mainmenu_controller = new MainMenuController();
		gameplay_controller = new GamePlayControllerUI();
	}
	void UIService::initializeController()
	{
		splashscreen_controller->initialize();
		mainmenu_controller->initialize();
		gameplay_controller->initialize();
	}
	void UIService::showController()
	{
		IUIController* ui_controller = getCurrentController();
		if (ui_controller) ui_controller->show();
	}
	void UIService::destroy()
	{
		delete(splashscreen_controller);
		delete(mainmenu_controller);
		delete(gameplay_controller);
	}
}