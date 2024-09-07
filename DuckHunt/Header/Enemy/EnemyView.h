#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UIService/Elements/ImageView.h"

namespace Enemy
{
	class EnemyController;
	class  EnemyView
	{
	public:
		 EnemyView();
		~ EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		sf::Sprite getEnemySprite();

	private:
		EnemyController* enemy_controller;
		const float enemy_width = 100.f;
		const float enemy_height = 100.f;
		UI::UIElement::ImageView* enemy_image;
		void createImage();
		void initializeImage();
		sf::String getEnemyTexturePath();
		void destroy();
	};


}