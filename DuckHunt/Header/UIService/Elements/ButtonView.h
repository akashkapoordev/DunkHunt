#pragma once
#include "../../Header/UIService/Elements/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		class ButtonView :public ImageView
		{
		private:
			using CallbackFunction = std::function<void()>;

			CallbackFunction callback_function = nullptr;
		public:
			ButtonView();
			virtual ~ButtonView();

			virtual void initialize(sf::String title,sf::String texture_path,float button_width,float button_height,sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			void registerCallBackFunction(CallbackFunction button_callback);

		protected:
			sf::String button_title;
			virtual void handleButtonInteraction();
			virtual bool clickedButton(sf::Sprite* button_sprite, sf::Vector2f position);


	
		};
	}
}



