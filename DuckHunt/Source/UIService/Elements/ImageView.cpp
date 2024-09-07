#include "../../Header/UIService/Elements/ImageView.h"

namespace UI
{
	namespace UIElement
	{
		ImageView::ImageView()
		{
		}
		ImageView::~ImageView()
		{
		}
		void ImageView::initialize(sf::String texture_path, float width, float height, sf::Vector2f position)
		{
			UIView::initialize();
			setTexture(texture_path);
			setScale(width,height);
			setPosition(position);
			
		}
		void ImageView::update()
		{
			UIView::update();
		}
		void ImageView::render()
		{
			if (ui_state == UIState::VISIBLE)
			{
				game_window->draw(imageSprite);

			}
		}
		sf::Sprite ImageView::getSprite()
		{
			return imageSprite;
		}
		void ImageView::setTexture(sf::String texture_path)
		{
			if (imageTexture.loadFromFile(texture_path))
			{
				imageSprite.setTexture(imageTexture);
			}
		}
		void ImageView::setScale(float width, float height)
		{
			float scale_x = width / imageSprite.getTexture()->getSize().x;
			float scale_y = height / imageSprite.getTexture()->getSize().y;

			imageSprite.setScale(scale_x, scale_y);
		}
		void ImageView::setPosition(sf::Vector2f position)
		{
			imageSprite.setPosition(position);
		}
		void ImageView::setRotation(float rotation_angle)
		{
			imageSprite.setRotation(rotation_angle);
		}
		void ImageView::setOriginAtCentre()
		{
			imageSprite.setOrigin(imageSprite.getLocalBounds().width / 2, imageSprite.getLocalBounds().height / 2);
		}
		void ImageView::setImageAlpha(float alpha)
		{
			sf::Color color = imageSprite.getColor();
			color.a = alpha;
			imageSprite.setColor(color);
		}
		void ImageView::setCentreAlinged()
		{
			float x_position = (game_window->getSize().x / 2) - (imageSprite.getGlobalBounds().width / 2);
			float y_position = imageSprite.getGlobalBounds().getPosition().y;

			imageSprite.setPosition(x_position, y_position);
		}
		void ImageView::setRectTexture(sf::IntRect rect_texture)
		{
			imageSprite.setTextureRect(rect_texture);
		}
	}
}