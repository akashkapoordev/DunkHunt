#include "../../Header/GamePlayService/GamePlayView.h"
#include "../../Header/Global/Config.h";
#include "../../Header/Global/ServiceLocator.h"

namespace GamePlayMain
{
	using namespace Global;
	GamePlayView::GamePlayView()
	{
		createImage();
	}
	GamePlayView::~GamePlayView()
	{
		destroy();
	}
	void GamePlayView::initialize()
	{
		wave_number_text = "Wave Number : 1 ";
		initializeImage();
		//gameplay_image->setImageAlpha(100);
	}
	void GamePlayView::update()
	{
		gameplay_image->update();
		wave_number->update();
	}
	void GamePlayView::render()
	{
		gameplay_image->render();
		wave_number->render();
	}
	sf::String GamePlayView::getWaveTextNumber()
	{
		return wave_number_text;
	}
	void GamePlayView::setWaveNumber(sf::String text)
	{
		wave_number->setText(text);
	}
	sf::Sprite GamePlayView::getImageApha()
	{
		return gameplay_image->getSprite();
	}
	void GamePlayView::setImageAplha(float aplha)
	{
		gameplay_image->setImageAlpha(aplha);
	}
	void GamePlayView::createImage()
	{
		gameplay_image = new UI::UIElement::ImageView();
		wave_number = new UI::UIElement::TextView();
	}
	void GamePlayView::initializeImage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		gameplay_image->initialize(Config::gameplay_background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		wave_number->initialize(wave_number_text, sf::Vector2f(800, 100), UI::UIElement::FontType::BUBBLE_BOBBLE, 40, sf::Color::Black);

	}
	void GamePlayView::updateWaveNumber()
	{
		wave_number->setText(getWaveTextNumber());
	}
	void GamePlayView::destroy()
	{
		delete(wave_number);
		delete(gameplay_image);
	}
}