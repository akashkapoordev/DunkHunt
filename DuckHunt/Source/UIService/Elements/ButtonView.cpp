#include "../../Header/UIService/Elements/ButtonView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/EventService/EventService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Event;

		ButtonView::ButtonView()
		{
		}
		ButtonView::~ButtonView()
		{
		}
		void ButtonView::initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
		{
			ImageView::initialize(texture_path, button_width, button_height, position);
			button_title = title;
		}
		void ButtonView::update()
		{
			ImageView::update();
			if (ui_state == UIState::VISIBLE)
			{
				handleButtonInteraction();
			}
		}
		void ButtonView::render()
		{
			if (ui_state == UIState::VISIBLE)
			{
				ImageView::render();
			}
		}
		void ButtonView::registerCallBackFunction(CallbackFunction button_callback)
		{
			callback_function = button_callback;
		}
		void ButtonView::handleButtonInteraction()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*game_window));
			if (clickedButton(&imageSprite,mousePosition))
			{
				if (callback_function)
				{
					callback_function();
				}
			}
		}
		bool ButtonView::clickedButton(sf::Sprite* button_sprite, sf::Vector2f position)
		{
			return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(position);
		}
	}
}