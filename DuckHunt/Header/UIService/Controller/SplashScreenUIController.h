#pragma once
#include "../../Header/UIService/Interface/IUIController.h"
#include "../../Header/UIService/Elements/AnimatedImageView.h"
#include "../../Header/UIService/Elements/ImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController :public interface::IUIController
		{
		public:
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		private:
			const float splash_screen_duration = 2.0f;
			//float elsacped_duration = 0.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;;
			UIElement::AnimatedImageView* animation_view;
			UIElement::ImageView* image_view;
			void createUIElements();
			void initializeImage();
			void fadeInAnimationCallback();
			void fadeOutAnimationCallback();
			sf::Vector2f getLogoPosition();
			void destroy();
		};


	}
}