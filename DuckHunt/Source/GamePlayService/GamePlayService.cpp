#include "../../Header/GamePlayService/GamePlayService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace GamePlayMain
{
	using namespace Global;
	GamePlayService::GamePlayService()
	{
		gameplay_controller = new GamePlayController();
	}
	GamePlayService::~GamePlayService()
	{
		delete(gameplay_controller);
	}
	void GamePlayService::initialize()
	{
		gameplay_controller->intialize();
	}
	void GamePlayService::update()
	{
		gameplay_controller->update();
	}
	void GamePlayService::render()
	{
		gameplay_controller->render();
	}
	sf::String GamePlayService::getWaveNumber()
	{
		return gameplay_controller->getWaveNumber();
	}
	void GamePlayService::setWaveNumber(sf::String text)
	{
		gameplay_controller->setWaveNumber(text);
	}
	sf::Sprite GamePlayService::getImageApha()
	{
		return gameplay_controller->getImageApha();
	}
	void GamePlayService::setImageAplha(float aplha)
	{
		gameplay_controller->setImageAplha(aplha);
	}
	void GamePlayService::resetGame()
	{
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getEnemyService()->reset();
		ServiceLocator::getInstance()->getWaveService()->reset();
	}
}