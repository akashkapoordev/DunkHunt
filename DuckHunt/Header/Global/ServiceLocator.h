#pragma once
#include "../../Header/GraphicService/GraphicService.h"
#include "../../Header/EventService/EventService.h"
namespace Global
{
	class ServiceLocator
	{
	public:
		ServiceLocator();
		~ServiceLocator();

		static ServiceLocator* getInstance();

		void initilize();
		void update();
		void render();

		Graphics::GraphicService* getGraphicService();
		Event::EventService* getEventService();
	
	private:
		void createServices();
		void clearServices();

		Graphics::GraphicService* graphics_service;
		Event::EventService* event_service;
	};
}