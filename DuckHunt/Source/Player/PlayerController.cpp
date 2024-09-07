#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/EventService/EventService.h"


namespace Player
{
	using namespace Global;
	using namespace Event;

	Player::PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
	}

	void PlayerController::update()
	{
		//if (PlayerModel::player_ammo <= 0)
		//{
		//	//printf("reset");
		//	PlayerModel::player_live--;
		//	reset();
		//}
		playerInput();
	}

	int PlayerController::getPlayerScore()
	{
		return player_model->getPlayerScore();
	}

	void PlayerController::setScore(int score)
	{
		player_model->setPlayerScore(score);
	}



	void PlayerController::playerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		if (event_service->pressedLeftMouseButton())
		{
			if (PlayerModel::player_ammo > 0)
			{
				PlayerModel::player_ammo--;
				sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));
				ServiceLocator::getInstance()->getEnemyService()->destroyEnemyAtClick(mouse_position);
			}
			else
			{
				ServiceLocator::getInstance()->getWaveService()->game_over = true;
				ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("");
				//ServiceLocator::getInstance()->getEnemyService()->reset();
			}
			

			
		}

	}

	void PlayerController::reset()
	{
		PlayerModel::player_ammo = 4;
		PlayerModel::player_live = 3;
		player_model->setPlayerScore(0);
	}

	void PlayerController::resetGame()
	{
		PlayerModel::player_ammo = 4;
		
		ServiceLocator::getInstance()->getEnemyService()->reset();
	}

}
