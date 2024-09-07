#pragma once
#include "../../Header/UIService/Elements/ImageView.h"
#include "../../Header/UIService/Elements/TextView.h"
namespace GamePlayMain
{
	class GamePlayView
	{
	public:
		GamePlayView();
		~GamePlayView();

		void initialize();
		void update();
		void render();
		sf::String wave_number_text;
		sf::String getWaveTextNumber();
		void setWaveNumber(sf::String text);
		sf::Sprite getImageApha();
		void setImageAplha(float aplha);

	private:
		UI::UIElement::ImageView* gameplay_image;
		UI::UIElement::TextView* wave_number;
		void createImage();
		void initializeImage();
		void updateWaveNumber();
		void destroy();
	};


}