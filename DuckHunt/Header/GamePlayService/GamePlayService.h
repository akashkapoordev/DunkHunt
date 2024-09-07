#pragma once
#include "../../Header/GamePlayService/GamePlayController.h"
namespace GamePlayMain
{
	class GamePlayService
	{
	public:
		GamePlayService();
		~GamePlayService();

		void initialize();
		void update();
		void render();

		sf::String getWaveNumber();
		void setWaveNumber(sf::String text);
		sf::Sprite getImageApha();
		void setImageAplha(float aplha);

		void resetGame();

	private:
		GamePlayController* gameplay_controller;
	};
}