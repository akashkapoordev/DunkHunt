#include "../../Header/GraphicService/GraphicService.h"
namespace Graphics
{
	Graphics::GraphicService::GraphicService()
	{
		video_mode = nullptr;
		game_window = nullptr;
	}
	GraphicService::~GraphicService()
	{
		//destroy();
	}
	sf::RenderWindow* GraphicService::createWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_title);
	}
	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}
	void GraphicService::initialize()
	{
		game_window = createWindow();
	}
	void GraphicService::update()
	{

	}
	void GraphicService::render()
	{
	}
	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}
	sf::Color GraphicService::getWindowColor()
	{
		return window_color;
	}

	void GraphicService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::destroy()
	{
		delete(video_mode);
		delete(game_window);
	}
}


