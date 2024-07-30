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
