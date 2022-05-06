#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Macros.h"

class ResourcesManager
{
public:
	static ResourcesManager& instance();

	const sf::Font* getFont() const;
	const sf::Texture* getCatIcon() const;
	const sf::Texture* getWinImg() const;
	const sf::Texture* getLoseImg() const;
	const sf::Texture* getButton() const;
	const sf::Texture* getBackground() const;
	const sf::SoundBuffer* getSoundBuffer() const;

	void playSound();
	
private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager&) = delete;

	sf::Font m_font;
	sf::Texture m_catTexture;

	sf::Texture m_winTexture;
	sf::Texture m_loseTexture;

	sf::Texture m_background;
	sf::Texture m_button;

	sf::Sound m_Sound;
	sf::SoundBuffer m_soundBuffer;
};