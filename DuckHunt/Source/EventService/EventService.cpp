#include "../../Header/EventService/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event
{
	using namespace Global;
	Event::EventService::EventService()
	{
		game_window = nullptr;
	}

	EventService::~EventService()
	{
	}

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	}

	void EventService::update()
	{
		updateMouseButtonState(left_mouse_button, sf::Mouse::Left);
	}

	void EventService::processEvent()
	{
		if (isGameWindowOpen())
		{
			while (game_window->pollEvent(game_event))
			{
				if (gameWindowWasClosed() || hasQuietGame())
				{
					game_window->close();
				}
			}
		}
	}

	bool EventService::pressEscKey()
	{
		return game_event.key.code == sf::Keyboard::Escape;
	}

	bool EventService::keyBoardEvent()
	{
		return game_event.type == sf::Event::KeyPressed;;

	}

	//bool EventService::leftMouseButton()
	//{
	//	return game_event.mouseButton.button == sf::Mouse::Left;
	//}
	
	bool EventService::pressedLeftMouseButton()
	{
		return left_mouse_button == ButtonState::PRESSED;
	}

	void EventService::updateMouseButtonState(ButtonState& current_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			switch (current_state)
			{
			case Event::ButtonState::RELEASED:
				current_state = ButtonState::PRESSED;
				break;
			case Event::ButtonState::PRESSED:
				current_state = ButtonState::HELD;
				break;
			default:
				break;
			}
		}
		else
		{
			current_state = ButtonState::RELEASED;
		}

	}

	bool EventService::isGameWindowOpen()
	{
		return game_window != nullptr;
	}

	bool EventService::gameWindowWasClosed()
	{
		return game_event.type == sf::Event::Closed;
	}

	bool EventService::hasQuietGame()
	{
		return (keyBoardEvent() && pressEscKey());
	}

}
