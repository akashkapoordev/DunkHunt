#include "../../Header/Wave/Wave.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"

#include <iostream>



namespace Wave
{
	using namespace Player;
	using namespace Enemy;
	using namespace Global;


	Wave::Wave()
	{
	}

	Wave::~Wave()
	{
	}

	void Wave::intialize()
	{
		//WaveType = 7;
		current_wave = WaveType::FIRST;
		ServiceLocator::getInstance()->getEnemyService()->processTime();

		//number_of_enemies = 2;
	}

	void Wave::update()
	{
		if (!player_won || !game_over)
		{
			updateWaveTimer();

		}
	}

	void Wave::waveNumber(WaveType type)
	{
		switch (type)
		{
		case WaveType::FIRST:
			number_of_enemies = 4;
			wave_timer = 5;
			current_timer = 0;

			break;
		case WaveType::SECOND:
			number_of_enemies = number_of_enemies + 3;
			std::cout << number_of_enemies;
			wave_timer = 10;
			current_timer = 0;
			break;
		case WaveType::ThIRD:
			number_of_enemies = number_of_enemies + 10;
			std::cout << number_of_enemies;
			wave_timer = 15;
			current_timer = 0;
			break;
		default:
			break;
		}
	}

	WaveType Wave::getWaveType()
	{
		return current_wave;
	}

	void Wave::setWaveType(WaveType type)
	{
		current_wave = type;
	}

	void Wave::reset()
	{
		current_timer = 0;
		current_wave = WaveType::FIRST;
		ServiceLocator::getInstance()->getEnemyService()->processTime();

	}

	void Wave::updateTimer()
	{
		current_timer = current_timer + ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void Wave::updateWaveTimer()
	{
		updateTimer();
		if (current_timer <= wave_timer)
		{
			
			if (ServiceLocator::getInstance()->getEnemyService()->checkIfAllEnimiesKilled())
			{
				if (current_wave == WaveType::FIRST)
				{
					ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("Wave Number : 1 ");
					setWaveType(WaveType::SECOND);
					return;
					

				}
				else if (current_wave == WaveType::SECOND)
				{
					current_timer = 0;
					enemiesKilled = 0;
					PlayerModel::player_ammo = 10;
					ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("Wave Number : 2 ");
					waveNumber(getWaveType());
					ServiceLocator::getInstance()->getEnemyService()->processTime();
					setWaveType(WaveType::ThIRD);
					return;
				}
				else if (current_wave == WaveType::ThIRD)
				{
					current_timer = 0;
					enemiesKilled = 0;
					PlayerModel::player_ammo = 17;
					ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("Wave Number : 3 ");
					waveNumber(getWaveType());
					ServiceLocator::getInstance()->getEnemyService()->processTime();
					setWaveType(WaveType::FINSIHED);
					return;
				}
				else if (current_wave == WaveType::FINSIHED)
				{
					ServiceLocator::getInstance()->getEnemyService()->reset();
					player_won = true;
					return;
				}
			}
	
		}
		else
		{
			if (PlayerModel::player_live > 0)
			{
				decreaesePlayerLife();
				ServiceLocator::getInstance()->getEnemyService()->reset();
				ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("Wave Number : 1 ");
				current_wave = WaveType::FIRST;
				setWaveType(WaveType::FIRST);
				waveNumber(getWaveType());
				ServiceLocator::getInstance()->getEnemyService()->processTime();
				current_timer = 0;

			}
			else
			{
				game_over = true;
				ServiceLocator::getInstance()->getGamePlaySevice()->setWaveNumber("");
				ServiceLocator::getInstance()->getEnemyService()->reset();
				//ServiceLocator::getInstance()->getGamePlaySevice()->resetGame();
			}
		}
	}

	void Wave::decreaesePlayerLife()
	{
		PlayerModel::player_live--;
		std::cout << PlayerModel::player_live;
	}

}

