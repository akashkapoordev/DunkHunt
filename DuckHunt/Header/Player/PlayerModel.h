#pragma once
#include "../../Header/UIService/Controller/GamePlayControllerUI.h"

namespace Player
{
	class PlayerModel
	{
	public:
		PlayerModel();
		~PlayerModel();

		void initialize();
		void update();

		int getPlayerAmmo();
		void setPlayerAmmo(int ammo_count);

		int getPlayerScore();
		void setPlayerScore(int score);

		
		int player_max_lives = 3;
		static int  player_live;
		static int player_ammo;
	private:
		friend class PlayerController;
		friend void UI::GamePlayUI::GamePlayControllerUI::updatePlayerAmmo();
		friend void UI::GamePlayUI::GamePlayControllerUI::updatePlayerLives();
		int max_ammo = 4;
		int player_score;

	};
}

