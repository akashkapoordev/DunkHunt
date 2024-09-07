#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED
	};
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
		//bool leftMouseButton();
		bool pressedLeftMouseButton();


	private:

		ButtonState left_mouse_button;
		void updateMouseButtonState(ButtonState& current_state, sf::Mouse::Button mouse_button);
		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuietGame();
	};


}