#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Event
{
	class EventService
	{
	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvent();
		bool pressEscKey();
		bool keyBoardEvent();

	private:

		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuietGame();
	};


}