#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy
{
	using namespace UI::UIElement;
	using namespace Global;
	Enemy::EnemyView::EnemyView()
	{
		createImage();
	}

	EnemyView::~EnemyView()
	{
		destroy();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		initializeImage();
	}

	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
		enemy_image->update();

	}

	void EnemyView::render()
	{

		enemy_image->render();
	}

	sf::Sprite EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	void EnemyView::createImage()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_width, enemy_height, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case EnemyType::RED:
			printf("Blue_texture");
			return Config::red_duck_texture;
		case EnemyType::GREEN:
			printf("Green _texture");
			return Config::green_duck_texture;
		}
	}

	void EnemyView::destroy()
	{
		delete(enemy_image);
	}

}
