#pragma once
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Wave/Wave.h"
namespace Player
{
	class PlayerService
	{
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();

		int getPlayerScore();
		void setPlayerScore(int score);
		void reset();

	private:
		PlayerController* player_controller;
	};


}