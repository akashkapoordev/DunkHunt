#pragma once
#include "../../Header/GamePlayService/GamePlayView.h"
namespace GamePlayMain
{
	class GamePlayController
	{
	public:
		GamePlayController();
		~GamePlayController();

		void intialize();
		void update();
		void render();
		sf::String getWaveNumber();
		void setWaveNumber(sf::String text);
		sf::Sprite getImageApha();
		void setImageAplha(float aplha);

	private:
		GamePlayView* gameplay_view;
	};
}