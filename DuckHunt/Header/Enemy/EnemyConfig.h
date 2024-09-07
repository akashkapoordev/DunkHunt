#pragma once
namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
		LEFT_DIAGONAL_DOWN,
		LEFT_DIAGONAL_UP,
		RIGHT_DIAGONAL_DOWN,
		RIGHT_DIAGONAL_UP,
		UP
	};

	enum class EnemyState
	{
		ALIVE,
		DEAD
	};

	enum  class EnemyType
	{
		GREEN,
		RED
	};
}