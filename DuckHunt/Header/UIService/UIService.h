#pragma once
#include "../../Header/UIService/Interface/IUIController.h"
#include "../../Header/UIService/Controller/MainMenuController.h"
#include "../../Header/UIService/Controller/GamePlayControllerUI.h"
#include "../../Header/UIService/Controller/SplashScreenUIController.h"

namespace UI
{
	class UIService
	{
	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showController();

		UI::interface::IUIController* getCurrentController();


	private:
		UI::MainMenu::MainMenuController* mainmenu_controller;
		UI::GamePlayUI::GamePlayControllerUI* gameplay_controller;
		UI::SplashScreen::SplashScreenUIController* splashscreen_controller;
		void createController();
		void initializeController();
		void destroy();
	};
}