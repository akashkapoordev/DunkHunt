#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();
	
		EnemyController* spwanEnemy();
		void destroyEnemyAtClick(sf::Vector2f mouse_position);

		void destroyEnemy(EnemyController* enemy_controller);
		void reset();
		//void checkforPlayerState();
		bool checkIfAllEnimiesKilled();
		void processTime();

	private:
		float spwan_timer;
		const float spwan_delay = 2;
		std::vector<EnemyController*> enemy_list;
		std::vector<EnemyController*> flagged_enemy;
		EnemyController* enemy_controller;
		EnemyController* createEnemy(EnemyType type);
		EnemyType getRandomEnemy();
		void updateTimer();
		void destroyFlaggedList();
		void destroy();
	};


}