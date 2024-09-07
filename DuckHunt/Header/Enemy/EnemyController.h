#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
	class EnemyView;
	class EnemyModel;
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;
	class EnemyController
	{
	
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		virtual void move() = 0;
		EnemyType getEnemyType();
		sf::Vector2f getEnemyPosition();
		sf::Sprite getEnemySprite();
		EnemyState getEnemyState();
		void enemySetState(EnemyState enemy_state);
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;
		sf::Vector2f getRandomInitialPosition();
		MovementDirection randomDirection();
		void moveHorizontalOrVertical(float horizontalSpeed, float verticalSpeed);
		void HandleOutOfBounds();
		void destroy();
		
	};


}