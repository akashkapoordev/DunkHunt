#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include <iostream>

namespace Enemy
{
	using namespace Global;
	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}
	EnemyController::~EnemyController()
	{
		destroy();
	}
	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setPosition(getRandomInitialPosition());
		enemy_model->setMovementDirection(randomDirection());
		enemy_view->initialize(this);
	}
	void EnemyController::update()
	{
		//enemy_model->update();
		enemy_view->update();
		move();
		HandleOutOfBounds();

	}
	void EnemyController::render()
	{
		//enemy_model->render();
		enemy_view->render();
	}
	EnemyType Enemy::EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		
		return enemy_model->getPosition();
	}

	sf::Sprite EnemyController::getEnemySprite()
	{
		return enemy_view->getEnemySprite();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	void EnemyController::enemySetState(EnemyState enemy_state)
	{
		enemy_model->setEnemyState(enemy_state);
	}

	std::string movementDirectionToString(Enemy::MovementDirection direction)
	{
		switch (direction)
		{
		case Enemy::MovementDirection::UP:
			return "UP";
		case Enemy::MovementDirection::DOWN:
			return "DOWN";
		case Enemy::MovementDirection::LEFT:
			return "LEFT";
		case Enemy::MovementDirection::RIGHT:
			return "RIGHT";
		case Enemy::MovementDirection::LEFT_DIAGONAL_UP:
			return "LEFT_DIAGONAL_UP";
		case Enemy::MovementDirection::LEFT_DIAGONAL_DOWN:
			return "LEFT_DIAGONAL_DOWN";
		case Enemy::MovementDirection::RIGHT_DIAGONAL_UP:
			return "RIGHT_DIAGONAL_UP";
		case Enemy::MovementDirection::RIGHT_DIAGONAL_DOWN:
			return "RIGHT_DIAGONAL_DOWN";
		default:
			return "UNKNOWN_DIRECTION";
		}
	}

	void EnemyController::moveHorizontalOrVertical(float horizontalSpeed, float verticalSpeed)
	{
		sf::Vector2f currentPosition = enemy_model->getPosition();

	

		if (enemy_model->getEnemyState() == EnemyState::ALIVE)
		{
			// Apply horizontal and vertical movement
			currentPosition.x += horizontalSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.y += verticalSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// Check boundaries and change direction if necessary
			if (currentPosition.y >= enemy_model->BottomMostPosition ||
				currentPosition.x <= enemy_model->LeftMostPosition ||
				currentPosition.y <= enemy_model->TopMostPosition ||
				currentPosition.x >= enemy_model->RightMostPosition)
			{

				enemy_model->setMovementDirection(randomDirection());

			}
			else
			{
				enemy_model->setPosition(currentPosition);
			}
		}
		else if((enemy_model->getEnemyState() == EnemyState::DEAD))
		{
			currentPosition.y += 600 * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			enemy_model->setPosition(currentPosition);
		}

	}


	MovementDirection EnemyController::randomDirection()
	{
		int randomType = std::rand() % 8;
		Enemy::MovementDirection direction = static_cast<Enemy::MovementDirection>(randomType);

		std::string directionString = movementDirectionToString(direction);
		//std::cout << "Movement Direction: " << directionString << std::endl;;
		return static_cast<Enemy::MovementDirection>(randomType);
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->RightMostPosition - enemy_model->LeftMostPosition));
		float y_offset_distance = (std::rand() % static_cast<int>(enemy_model->RightMostPosition - enemy_model->LeftMostPosition));
		float x_position = enemy_model->LeftMostPosition + x_offset_distance;
		//float y_position = enemy_model->LeftMostPosition + y_offset_distance;

		float y_position = enemy_model->BottomMostPosition;

		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (enemyPosition.x<0 || enemyPosition.x >windowSize.x ||
			enemyPosition.y<0 || enemyPosition.y >windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);

		}

	}

	void EnemyController::destroy()
	{
		delete(enemy_model);
		delete(enemy_view);
	}



}

