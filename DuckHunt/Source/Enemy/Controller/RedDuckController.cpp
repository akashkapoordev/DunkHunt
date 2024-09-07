#include "../../Header/Enemy/Controller/RedDuckController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		Enemy::Controller::RedDuckController::RedDuckController(EnemyType type):EnemyController(type)
		{
		}

		RedDuckController::~RedDuckController()
		{
		}

		void RedDuckController::initialize()
		{
			EnemyController::initialize();
			printf("Initialize BlueDuck");

		}

		void RedDuckController::move()
		{
				switch (enemy_model->getMovementDirection())
				{
				case MovementDirection::UP:
					moveHorizontalOrVertical(0.0f, -vertical_movement_speed);  // Move up
					break;
				case MovementDirection::DOWN:
					moveHorizontalOrVertical(0.0f, vertical_movement_speed);  // Move down
					break;
				case MovementDirection::LEFT:
					moveHorizontalOrVertical(-horizontal_movement_speed, 0.0f);  // Move left
					break;
				case MovementDirection::RIGHT:
					moveHorizontalOrVertical(horizontal_movement_speed, 0.0f);  // Move right
					break;
				case MovementDirection::LEFT_DIAGONAL_UP:
					moveHorizontalOrVertical(-horizontal_movement_speed, -vertical_movement_speed);  // Move left-diagonal up
					break;
				case MovementDirection::LEFT_DIAGONAL_DOWN:
					moveHorizontalOrVertical(-horizontal_movement_speed, vertical_movement_speed);  // Move left-diagonal down
					break;
				case MovementDirection::RIGHT_DIAGONAL_UP:
					moveHorizontalOrVertical(horizontal_movement_speed, -vertical_movement_speed);  // Move right-diagonal up
					break;
				case MovementDirection::RIGHT_DIAGONAL_DOWN:
					moveHorizontalOrVertical(horizontal_movement_speed, vertical_movement_speed);  // Move right-diagonal down
					break;
				default:
					break;
				}
			
		}

	}
}

 