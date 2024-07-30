#include "../../Header/Global/ServiceLocator.h"


namespace Global
{
	using namespace Graphics;
	using namespace Event;

	//Constructor
	Global::ServiceLocator::ServiceLocator()
	{
		graphics_service = nullptr;
		event_service = nullptr;
		createServices();
	}

	//destructor
	ServiceLocator::~ServiceLocator()
	{
		clearServices();
	}

	//Static Service Locator so that it has only one instance 
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	//initilize
	void ServiceLocator::initilize()
	{
		graphics_service->initialize();
		event_service->initialize();
	}
	//update
	void ServiceLocator::update()
	{
		graphics_service->update();
		event_service->update();
	}
	//render
	void ServiceLocator::render()
	{
		graphics_service->render();
	}

	//Get Graphic service
	Graphics::GraphicService* ServiceLocator::getGraphicService()
	{
		return graphics_service;
	}

	//Get Event Service
	Event::EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	// Creating services
	void ServiceLocator::createServices()
	{
		graphics_service = new GraphicService();
		event_service = new EventService();
	}

	//clearing services
	void ServiceLocator::clearServices()
	{
		delete(graphics_service);
		delete(event_service);
	}
}

