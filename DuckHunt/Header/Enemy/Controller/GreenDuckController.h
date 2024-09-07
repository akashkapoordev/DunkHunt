#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class GreenDuckController :public EnemyController
		{
		public:
			GreenDuckController(EnemyType type);
			virtual ~GreenDuckController();

			void initialize() override;
			void move() override;
			float timeSinceLastDirectionChange = 0.0f; // Time since the last direction change
			const float directionChangeDelay = 1.0f;
		private:
			float vertical_movement_speed = 100.f;
			float horizontal_movement_speed = 100.f;
		};

	}
}
