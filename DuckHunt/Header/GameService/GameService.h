#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"
namespace GameService
{
	class GameServce
	{
	public:
		GameServce();
		~GameServce();

		void ignite();
		void update();
		void render();

		bool isRunning();

	private:
		sf::RenderWindow* game_window;
		Global::ServiceLocator* service_locator;


		void initialize();
		void initializeVariable();
		void destroy();
	};

}
