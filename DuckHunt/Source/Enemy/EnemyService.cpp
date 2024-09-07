#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/RedDuckController.h"
#include "../../Header/Enemy/Controller/GreenDuckController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Wave/Wave.h"
#include "../../Header/Player/PlayerModel.h"
#include <iostream>


namespace Enemy
{
	using namespace Controller;
	using namespace Global;
	using namespace Wave;

	Enemy::EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
	}

	void EnemyService::initialize()
	{
		spwan_timer = spwan_delay;
	}

	void EnemyService::update()
	{
		//updateTimer();
		//processTime();
		//checkforPlayerState();
		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->update();
		}
		destroyFlaggedList();
		
	}

	void EnemyService::render()
	{
		for (int i = 0;i < enemy_list.size();i++)
		{
			enemy_list[i]->render();
		}
		
	}

	EnemyController* EnemyService::createEnemy(EnemyType type)
	{
		switch (type)
		{
		case Enemy::EnemyType::GREEN:
			printf("Green");
			return new GreenDuckController(EnemyType::GREEN);
			break;
		case Enemy::EnemyType::RED:
			printf("Blue");
			return new RedDuckController(EnemyType::RED);
			break;
		}
	}

	EnemyController* EnemyService::spwanEnemy()
	{
		enemy_controller = createEnemy(getRandomEnemy());
		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);
		return enemy_controller;
	}

	void EnemyService::destroyEnemyAtClick(sf::Vector2f mouse_position)
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			if (enemy_list[i]->getEnemySprite().getGlobalBounds().contains(mouse_position) &&
				enemy_list[i]->getEnemyState() != EnemyState::DEAD)
			{
				enemy_list[i]->enemySetState(EnemyState::DEAD);
				ServiceLocator::getInstance()->getWaveService()->enemiesKilled++;
				ServiceLocator::getInstance()->getPlayerService()->setPlayerScore(1);
				printf("Enemy killed\n");
				break;
			}
		
		}
	}


	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		flagged_enemy.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}

	void EnemyService::reset()
	{

		destroy();
	}

	bool EnemyService::checkIfAllEnimiesKilled()
	{
		return ServiceLocator::getInstance()->getWaveService()->enemiesKilled == ServiceLocator::getInstance()->getWaveService()->number_of_enemies;
	
	
	}

	//void EnemyService::checkforPlayerState()
	//{
	//	if (spwan_timer > spwan_delay)
	//	{
	//		if (ServiceLocator::getInstance()->getWaveService()->timerCheck())
	//		{
	//			if (Enemy::EnemyModel::enemy_count >= ServiceLocator::getInstance()->getWaveService()->enemies_to_killed)
	//			{
	//				ServiceLocator::getInstance()->getPlayerService()->setPlayerState(Player::PlayerState::WON);
	//				ServiceLocator::getInstance()->getWaveService()->ResetTimer();
	//				reset();
	//				spwan_timer = 0;
	//			}
	//			/*		else if (Enemy::EnemyModel::enemy_count <= ServiceLocator::getInstance()->getWaveService()->enemies_to_killed)
	//					{
	//						printf("Defeat");
	//						ServiceLocator::getInstance()->getPlayerService()->setPlayerState(Player::PlayerState::DEFEAT);
	//						reset();
	//						spwan_timer = 0;

	//			}*/

	//		}
	//		processTime();
	//	}

	//
	//}



	EnemyType EnemyService::getRandomEnemy()
	{
		int random_enemy = std::rand() % 2;
		return static_cast<Enemy::EnemyType>(random_enemy);
	}

	void EnemyService::processTime()
	{
		std::cout << ServiceLocator::getInstance()->getWaveService()->number_of_enemies;
		for (int i = 0;i < ServiceLocator::getInstance()->getWaveService()->number_of_enemies;i++)
		{

			spwanEnemy();
		}
	}

	void EnemyService::updateTimer()
	{
		spwan_timer  = spwan_timer +  ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::destroyFlaggedList()
	{
		for (int i = 0;i < flagged_enemy.size();i++)
		{
			delete(flagged_enemy[i]);
		}
		flagged_enemy.clear();
	}

	void EnemyService::destroy()
	{
		for(int i = 0; i < enemy_list.size();i++)
		{
			delete(enemy_list[i]);
		}
		enemy_list.clear();
	}

}
