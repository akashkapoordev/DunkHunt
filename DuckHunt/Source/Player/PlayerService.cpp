#include "../../Header/Player/PlayerService.h"
#include "../../Header/Wave/Wave.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"
#include <stdio.h>
#include <iostream>


namespace Player
{
	using namespace Wave;
	using namespace Global;
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}
	Player::PlayerService::~PlayerService()
	{
		delete(player_controller);
	}
	void PlayerService::initialize()
	{
		player_controller->initialize();
	}
	void PlayerService::update()
	{
		player_controller->update();
		//waveChangeState();
	}
	int PlayerService::getPlayerScore()
	{
		return player_controller->getPlayerScore();
	}
	void PlayerService::setPlayerScore(int score)
	{
		//std::cout << score;
		//printf("Score");
		player_controller->setScore(getPlayerScore() + score);
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}


	

}

