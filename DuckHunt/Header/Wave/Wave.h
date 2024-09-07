#pragma once
#include "../../Header/Player/PlayerModel.h"
namespace Wave
{

	enum class WaveType
	{
		FIRST,
		SECOND,
		ThIRD,
		FINSIHED
	};
	class  Wave
	{
	public:
		 Wave();
		~ Wave();

		void intialize();
		void update();
		void waveNumber(WaveType type);
		int number_of_enemies = 5;
		int enemiesKilled = 0;

		WaveType getWaveType();
		void setWaveType(WaveType type);
		void reset();
		bool player_won = false;
		bool game_over = false;


	private:
		bool is_wave_started = false;
		float pLayer_decrease_timer;
		float wave_timer = 10;
		float current_timer = 0;
		float current_wave_timer = 0;
		float next_wave_timer = 3;
		void updateTimer();
		WaveType current_wave;
		void updateWaveTimer();
		void decreaesePlayerLife();

	};
}
