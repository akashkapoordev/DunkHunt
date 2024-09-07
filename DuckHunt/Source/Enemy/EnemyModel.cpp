#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	int EnemyModel::enemy_count = 0;
	Enemy::EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::initialize()
	{
		initial_position = current_position;
		//movement_direction = MovementDirection::LEFT;
		enemy_state = EnemyState::ALIVE;

	}

	//void EnemyModel::update()
	//{
	//}

	//void EnemyModel::render()
	//{
	//}

	sf::Vector2f EnemyModel::getPosition()
	{
		return current_position;
	}

	void EnemyModel::setPosition(sf::Vector2f enemy_position)
	{
		current_position = enemy_position;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}


	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

}
