#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
	enum class EnemyState;
	enum class EnemyType;
	enum class MovementDirection;
	class  EnemyModel
	{
	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		float LeftMostPosition = 50.f;
		float RightMostPosition = 1800.f;
		float TopMostPosition = 0.f;
		float BottomMostPosition = 880.f;

		float move_speed = 250.f;
		void initialize();

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f enemy_position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		int static number_of_eneimes;
		int static enemy_count;
		//int static enemie_li

	private:
		sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f current_position;
		MovementDirection movement_direction;
		EnemyState enemy_state;
		EnemyType enemy_type;
		
		
	};


}