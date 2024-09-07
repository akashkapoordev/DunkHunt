#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"
namespace GameService
{
	enum class GameState
	{
		BOOT,
		SPLASHSCREEN,
		MAINMENU,
		GAMEPLAY,
		INSTRUCTION
	};

	class GameServce
	{
	public:
		GameServce();
		~GameServce();

		void ignite();
		void update();
		void render();

		bool isRunning();
		static GameState getState();
		static void setState(GameState current_state);
		void showSplashScreen();

	private:
		sf::RenderWindow* game_window;
		Global::ServiceLocator* service_locator;

		static GameState current_game_state;

		void initialize();
		void initializeVariable();
		void destroy();
	};

}
