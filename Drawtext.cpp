#include <SFML/Graphics.hpp>

#include "DrawText.hpp"

void draw_text(unsigned short i_x, unsigned short i_y, const std::string& i_text, sf::RenderWindow& i_window)
{
	short character_x = i_x;
	short character_y = i_y;

	unsigned char character_width;

	sf::Sprite character_sprite;

	sf::Texture font_texture;
	font_texture.loadFromFile("C:\\Users\\User\\OneDrive\\바탕 화면\\lib\\cmake\\SFML\\Resources\\Images\\Font.png");

	character_width = font_texture.getSize().x / 91;

	character_sprite.setTexture(font_texture);

	for (const char a : i_text)
	{
		if ('\n' == a)
		{
			character_x = i_x;
			character_y += font_texture.getSize().y;

			continue;
		}

		character_sprite.setPosition(character_x, character_y);
		character_sprite.setTextureRect(sf::IntRect(character_width * (a - 32), 0, character_width, font_texture.getSize().y));

		character_x += character_width;

		i_window.draw(character_sprite);
	}
}
