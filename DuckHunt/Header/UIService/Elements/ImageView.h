#pragma once
#include "../../Header/UIService/Elements/UIView.h"
namespace UI
{
	namespace UIElement
	{
		class ImageView:public UIView
		{
		public:
			ImageView();
			virtual ~ImageView();
			
			virtual void initialize(sf::String texture_path,float width,float height,sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;
			virtual sf::Sprite getSprite();
			virtual void setTexture(sf::String texture_path);
			virtual void setScale(float width, float height);
			virtual void setPosition(sf::Vector2f position);
			virtual void setRotation(float rotation_angle);
			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged();
			virtual void setRectTexture(sf::IntRect rect_texture);

		protected:
			sf::Texture imageTexture;
			sf::Sprite imageSprite;

			

		};
	}
}