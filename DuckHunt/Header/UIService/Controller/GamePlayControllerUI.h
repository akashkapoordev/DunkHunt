#pragma once
#include "../../Header/UIService/Elements/ImageView.h"
#include "../../Header/UIService/Elements/TextView.h"
#include "../../Header/UIService/Interface/IUIController.h"

namespace UI
{
	namespace GamePlayUI
	{
		class GamePlayControllerUI:public interface::IUIController
		{
		public:
			GamePlayControllerUI();
			~GamePlayControllerUI();


			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void updatePlayerScore();
			void updatePlayerAmmo();
			void updatePlayerLives();

			//float wave_text_timer = 2;
			//float current_timer;
			//void updateTimer();

		private:
			UI::UIElement::ImageView* gameplay_background;
	/*		UI::UIElement::ImageView* player_won;
			UI::UIElement::ImageView* game_over;*/
			UI::UIElement::TextView* player_won;
			UI::UIElement::TextView* game_over;
			UI::UIElement::TextView* player_score;
			UI::UIElement::TextView* payer_ammo;
			UI::UIElement::TextView* player_lives;
			//UI::UIElement::TextView* wave_number;

			const float fontSize = 40.f;

			const sf::Color textColor = sf::Color::White;

			void createTextView();
			void initializeText();
			//void hideWaveNumber();
			void destroy();
		};
	}
}