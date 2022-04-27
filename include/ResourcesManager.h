#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"

class ResourcesManager
{
public:
	static ResourcesManager& instance();
	const sf::Font* getFont() const;
	const sf::Texture* getCatIcon() const;

	const sf::Texture* getWinImg() const;

	const sf::Texture* getLoseImg() const;
	
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;

	sf::Font m_font;
	sf::Texture m_catTexture;
	sf::Texture m_winTexture;
	sf::Texture m_loseTexture;
};