#include "../../Header/UIService/Controller/GamePlayControllerUI.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include <iostream>

namespace UI
{
	namespace GamePlayUI
	{
		using namespace Global;
		GamePlayControllerUI::GamePlayControllerUI()
		{
			createTextView();
		}

		GamePlayControllerUI::~GamePlayControllerUI()
		{
			destroy();
		}

		void GamePlayControllerUI::initialize()
		{
			initializeText();
		}

		void GamePlayControllerUI::update()
		{
			//updateTimer();
	/*		if (current_timer > wave_text_timer)
			{
				hideWaveNumber();
				
			}*/
			updatePlayerScore();
			updatePlayerAmmo();
			updatePlayerLives();
		}

		void GamePlayControllerUI::render()
		{

			player_score->render();
			payer_ammo->render();
			player_lives->render();
			if (ServiceLocator::getInstance()->getWaveService()->player_won)
			{
				player_won->render();
			}
			if (ServiceLocator::getInstance()->getWaveService()->game_over)
			{
				game_over->render();

			}
			//wave_number->render();
		}

		void GamePlayUI::GamePlayControllerUI::show()
		{
			player_score->show();
			payer_ammo->show();
		}

		void GamePlayControllerUI::updatePlayerScore()
		{
			sf::String updated_player_score = "Player Score :  " + std::to_string(ServiceLocator::getInstance()->getPlayerService()->getPlayerScore());
			int score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
			//std::cout << score;
			player_score->setText(updated_player_score);
		}

		void GamePlayControllerUI::updatePlayerAmmo()
		{
			sf::String update_player_ammo = "Player Ammo : " + std::to_string(Player::PlayerModel::player_ammo);
			payer_ammo->setText(update_player_ammo);
		}

		void GamePlayControllerUI::updatePlayerLives()
		{
			sf::String update_player_lives = "Player Lives : " + std::to_string(Player::PlayerModel::player_live);
			player_lives->setText(update_player_lives);
		}

		//void GamePlayControllerUI::updateTimer()
		//{
		//	current_timer = current_timer + ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		//}

		void GamePlayControllerUI::createTextView()
		{
			printf("Create Text");
			player_won = new UI::UIElement::TextView();
			game_over = new UI::UIElement::TextView();
			player_score = new UI::UIElement::TextView();
			payer_ammo = new UI::UIElement::TextView();
			player_lives = new UI::UIElement::TextView();
			//wave_number = new UI::UIElement::TextView();
		}

		void GamePlayControllerUI::initializeText()
		{
			printf("initlize text");
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			player_score->initialize("Player Score : 0 ", sf::Vector2f(60,15), UI::UIElement::FontType::BUBBLE_BOBBLE, fontSize, sf::Color::Black);
			payer_ammo->initialize("Player Ammo : 0 ", sf::Vector2f(1600, 15), UI::UIElement::FontType::BUBBLE_BOBBLE, fontSize, sf::Color::Black);
			player_lives->initialize("Player Lives : 0 ", sf::Vector2f(800, 15), UI::UIElement::FontType::BUBBLE_BOBBLE, fontSize, sf::Color::Black);
			player_won->initialize("Player Won ", sf::Vector2f(800, 300), UI::UIElement::FontType::BUBBLE_BOBBLE, 100, sf::Color::Black);
			game_over->initialize("Game Over! ", sf::Vector2f(800, 300), UI::UIElement::FontType::BUBBLE_BOBBLE, 100, sf::Color::Black);


			//wave_number->initialize("Wave Number : 1 ", sf::Vector2f(800, 100), UI::UIElement::FontType::BUBBLE_BOBBLE, fontSize, sf::Color::Black);
		}

		//void GamePlayControllerUI::hideWaveNumber()
		//{
		//	//sf::String updated_Wave_Number = "";
		//	//int score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();
		//	wave_number->setText("");
		//}

		void GamePlayControllerUI::destroy()
		{
			delete(player_score);
			delete(payer_ammo);
			delete(player_lives);
			//delete(wave_number);
		}

	}
}

