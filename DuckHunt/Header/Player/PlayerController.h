#pragma once
#include "../../Header/Player/PlayerModel.h"
namespace Player
{
	class PlayerController
	{
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();

		int getPlayerScore();
		void setScore(int score);
		void reset();
		void resetGame();
		//PlayerState getPlayerState();
		//void setPlayerState(PlayerState state);

	private:
		PlayerModel* player_model;
		void playerInput();
	}; 
}