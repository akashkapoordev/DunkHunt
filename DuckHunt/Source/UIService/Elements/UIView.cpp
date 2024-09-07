#include "../../Header/UIService/Elements/UIView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		UIView::UIView()
		{
			//=game_window = nullptr;
		}
		UIView::~UIView()
		{
		}
		void UIView::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			ui_state = UIState::VISIBLE;

		}
		void UIView::update()
		{
		}
		void UIView::render()
		{
		}
		void UIView::show()
		{
			ui_state = UIState::VISIBLE;
		}
		void UIView::hide()
		{
			ui_state = UIState::HIDDEN;
		}
	}
}