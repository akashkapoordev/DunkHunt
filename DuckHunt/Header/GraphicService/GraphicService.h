#pragma once
#include <SFML/Graphics.hpp>
namespace Graphics
{
	class GraphicService
	{
	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* createWindow();
		bool isGameWindowOpen();

		void initialize();
		void update();
		void render();

		sf::RenderWindow* getGameWindow();
		sf::Color getWindowColor();



	private:
		const std::string game_title = "Duck Hunt";
		int game_window_width = 1920;
		int game_window_height = 1080;

		sf::Color window_color = sf::Color::Blue;
		sf::VideoMode* video_mode;
		sf::RenderWindow* game_window;

		void setVideoMode();
		void destroy();
	};


}