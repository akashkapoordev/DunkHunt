#include "../../Header/Player/PlayerModel.h"
#include <iostream>


namespace Player
{
	int PlayerModel::player_ammo = 0;
	int PlayerModel::player_live = 0;
	Player::PlayerModel::PlayerModel()
	{
		player_score = 0;
	}

	PlayerModel::~PlayerModel()
	{
	}

	void PlayerModel::initialize()
	{
		player_ammo = 8;
		player_live = player_max_lives;
	}

	void PlayerModel::update()
	{
	}

	int PlayerModel::getPlayerAmmo()
	{
		return player_ammo;
	}

	void PlayerModel::setPlayerAmmo(int ammo_count)
	{
		player_ammo = ammo_count;
	}



	int PlayerModel::getPlayerScore()
	{
		return player_score;
	}


	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
		//std::cout << player_score;
	}



}
