#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class RedDuckController:public EnemyController
		{
		public:
			RedDuckController(EnemyType type);
			virtual ~RedDuckController();

			void initialize() override;
			void move() override;

		private:
			float vertical_movement_speed = 200.f;
			float horizontal_movement_speed = 200.f;


		};

	}
}