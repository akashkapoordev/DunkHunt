#include "../../Header/UIService/Controller/MainMenuController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/GameService/GameService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace UI::UIElement;
		using namespace GameService;

		MainMenuController::MainMenuController()
		{
			createImage();
			createButtonView();
		}
		MainMenuController::~MainMenuController()
		{
			destroy();
		}
		void MainMenuController::initialize()
		{
			initializeBackgroundImage();
			initializeButtonImage();
			registerCallback();
			

		}
		void MainMenuController::update()
		{
			background_image->update();
			play_button_view->update();
			instruction_button_view->update();
			quit_button_view->update();
		}
		void MainMenuController::render()
		{
			background_image->render();
			play_button_view->render();
			instruction_button_view->render();
			quit_button_view->render();
		}
	
		void MainMenuController::createImage()
		{
			background_image = new ImageView();
		}
		void MainMenuController::createButtonView()
		{
			play_button_view = new ButtonView();
			instruction_button_view = new ButtonView();
			quit_button_view = new ButtonView();
		}
		void MainMenuController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		}
		void MainMenuController::initializeButtonImage()
		{
			play_button_view->initialize("Play Button", Config::play_texture_path, button_width, button_height, sf::Vector2f(0, play_position_y));
			instruction_button_view->initialize("Intruction Button", Config::instruction_texture_path, button_width, button_height, sf::Vector2f(0, instruction_position_y));
			quit_button_view->initialize("Quit Button", Config::quit_texture_path, button_width, button_height, sf::Vector2f(0, quit_position_y));
			play_button_view->setCentreAlinged();
			instruction_button_view->setCentreAlinged();
			quit_button_view->setCentreAlinged();
		}
		void MainMenuController::playButtonCallback()
		{
			GameServce::setState(GameState::GAMEPLAY);
		}
		void MainMenuController::instructionCallback()
		{
			GameServce::setState(GameState::INSTRUCTION);
		}
		void MainMenuController::quitButtonCallback()
		{
			//GameServce::setState(GameState::QUIT);
			//printf("Quit button Clicked");
			ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
		}
		void MainMenuController::registerCallback()
		{
			//printf("register callback");
			play_button_view->registerCallBackFunction(std::bind(&MainMenuController::playButtonCallback,this));
			instruction_button_view->registerCallBackFunction(std::bind(&MainMenuController::instructionCallback, this));
			quit_button_view->registerCallBackFunction(std::bind(&MainMenuController::quitButtonCallback, this));
		}
		void MainMenuController::show()
		{
			background_image->show();
			play_button_view->show();
			instruction_button_view->show();
			quit_button_view->show();
		}
		void MainMenuController::destroy()
		{
			delete(background_image);
			delete(play_button_view);
			delete(instruction_button_view);
			delete(quit_button_view);
		}
	}
}