#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Defines.h"
#include "AnimatedSprite.h"
#include "Player.h"
#include "Command.h"

class Game
{
public:

	Game();
	~Game();
	void run();

private:

	void processEvents(SDL_Event t_e);
	void update();
	void render();
	void rendererDraw();

	void cleanUp();

	bool m_gameIsRunning;

	const int WINDOW_WIDTH{ 640 };
	const int WINDOW_HEIGHT{ 480 };

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_FRect m_rect;

	AnimatedSprite player_animated_sprite;
	Player player;

	SDL_Texture* m_texture{ nullptr };
	Command command;

	inline SDL_Texture* loadFromFile(const char* const t_path, SDL_Renderer* t_renderer)
	{
		SDL_Texture* m_texture{NULL};

		SDL_Surface* m_loadedSurface = IMG_Load(t_path);

		if(m_loadedSurface == NULL)
		{
			std::cout << "Unable to load image %s! SDL_image Error: %s\n" << t_path << IMG_GetError() << std::endl;
		}
		else
		{
			m_texture = SDL_CreateTextureFromSurface(t_renderer, m_loadedSurface);
			if(m_texture == NULL)
			{
				std::cout << "Unable to create texture from %s! SDL Error: %s\n" << t_path << SDL_GetError() << std::endl;
			}

			SDL_FreeSurface(m_loadedSurface);
		}

		return m_texture;
	}

};