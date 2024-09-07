#include "../../Header/GamePlayService/GamePlayController.h"

namespace GamePlayMain
{
	GamePlayController::GamePlayController()
	{
		gameplay_view = new GamePlayView();
	}
	GamePlayController::~GamePlayController()
	{
		delete(gameplay_view);
	}
	void GamePlayController::intialize()
	{
		gameplay_view->initialize();
	}
	void GamePlayController::update()
	{
		gameplay_view->update();
	}
	void GamePlayController::render()
	{
		gameplay_view->render();
	}
	sf::String GamePlayController::getWaveNumber()
	{
		return gameplay_view->getWaveTextNumber();
	}
	void GamePlayController::setWaveNumber(sf::String text)
	{
		gameplay_view->setWaveNumber(text);
	}
	sf::Sprite GamePlayController::getImageApha()
	{
		return gameplay_view->getImageApha();
	}
	void GamePlayController::setImageAplha(float aplha)
	{
		gameplay_view->setImageAplha(aplha);
	}
}