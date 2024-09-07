#pragma once
#include "../../Header/UIService/Interface/IUIController.h"
#include "../../Header/UIService/Elements/ImageView.h"
#include "../../Header/UIService/Elements/ButtonView.h"
namespace UI
{
	namespace MainMenu
	{
		class MainMenuController:public interface::IUIController
		{
		public:
			MainMenuController();
			~MainMenuController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			const float background_alpha = 85.f;
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float play_position_y = 470.f;
			const float instruction_position_y = 640.f;
			const float quit_position_y = 810.f;

			UI::UIElement::ImageView* background_image;
			UI::UIElement::ButtonView* play_button_view;
			UI::UIElement::ButtonView* instruction_button_view;
			UI::UIElement::ButtonView* quit_button_view;

			void createImage();
			void createButtonView();
			void initializeBackgroundImage();
			void initializeButtonImage();

			void playButtonCallback();
			void instructionCallback();
			void quitButtonCallback();

			void registerCallback();
			void destroy();
		};
	}
}