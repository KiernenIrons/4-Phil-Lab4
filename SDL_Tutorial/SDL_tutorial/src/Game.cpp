#include "../include/Game.h"

Game::Game() :
	m_gameIsRunning{ false }
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow("FSM",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	m_rect.x = 100;
	m_rect.y = 100;
	m_rect.w = 200;
	m_rect.h = 50;

	m_texture = loadFromFile(PLAYER_SPRITES, m_renderer);
	if(m_texture == nullptr)
	{
		m_texture = loadFromFile(ERROR_SPRITES, m_renderer);
	}

	player_animated_sprite = AnimatedSprite(m_texture);
	player = Player(player_animated_sprite);
}

Game::~Game()
{
	cleanUp();
}

void Game::run()
{
	gpp::Events input;

	m_gameIsRunning = true;
	SDL_Event e{};

	while (m_gameIsRunning)
	{
		
		processEvents(e);
		update();
		player.update();
		render();
		if (e.type == SDL_KEYDOWN)
	{
		switch (e.type)
		{
			// Deal with KeyPressed
		case SDL_KEYDOWN:
			// Died Event
			if (e.key.keysym.sym == SDLK_d) {
				DEBUG_MSG("gpp::Events::Event::DIED_EVENT");
				input.setCurrent(gpp::Events::Event::DIED_EVENT);
			}
			// Revieved Event
			else if (e.key.keysym.sym == SDLK_r) {
				DEBUG_MSG("gpp::Events::Event::REVIVED_EVENT");
				input.setCurrent(gpp::Events::Event::REVIVED_EVENT);
			}
			// Running attack
			else if (e.key.keysym.sym == SDLK_z 
				&& 
				e.key.keysym.sym == SDLK_RIGHT
				||
				e.key.keysym.sym == SDLK_RIGHT
				&& 
				e.key.keysym.sym == SDLK_z
				)
			{
				DEBUG_MSG("gpp::Events::Event::ATTACK_START");
				input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
			}
			// Attack
			else if (e.key.keysym.sym == SDLK_z)
			{
				DEBUG_MSG("gpp::Events::Event::ATTACK_START_EVENT");
				input.setCurrent(gpp::Events::Event::ATTACK_START_EVENT);
			}
			// Throw attack
			else if (e.key.keysym.sym == SDLK_x
				&& 
				e.key.keysym.sym == SDLK_RIGHT
				||
				e.key.keysym.sym == SDLK_RIGHT 
				&& 
				e.key.keysym.sym == SDLK_x
				)
			{
				DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
				input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
			}
			// Throw Attack
			else if (e.key.keysym.sym == SDLK_x)
			{
				DEBUG_MSG("gpp::Events::Event::THROW_START_EVENT");
				input.setCurrent(gpp::Events::Event::THROW_START_EVENT);
			}
			// Run Right
			else if (e.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
			}
			// Climb Up
			else if (e.key.keysym.sym == SDLK_UP)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_UP_START_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_UP_START_EVENT);
			}
			// Climb Down
			else if (e.key.keysym.sym == SDLK_DOWN)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_START_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_DOWN_START_EVENT);
			}
			// Hit Bottom of Ladder Event
			else if (e.key.keysym.sym == SDLK_c)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT);
			}
			// Hit Top of Ladder Event
			else if (e.key.keysym.sym == SDLK_t)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_LADDER_TOP_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_LADDER_TOP_EVENT);
			}
			// Jump Run
			if (e.key.keysym.sym == SDLK_SPACE 
				&& 
				e.key.keysym.sym == SDLK_RIGHT
				||
				e.key.keysym.sym == SDLK_RIGHT 
				&& 
				e.key.keysym.sym == SDLK_SPACE
				)
			{
				DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
				input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
			}
			// Jump Event
			else if (e.key.keysym.sym == SDLK_SPACE)
			{
				DEBUG_MSG("gpp::Events::Event::JUMP_UP_EVENT");
				input.setCurrent(gpp::Events::Event::JUMP_UP_EVENT);
			}
			// Running Slide
			else if (e.key.keysym.sym == SDLK_DOWN
				&& 
				e.key.keysym.sym == SDLK_RIGHT
				||
				e.key.keysym.sym == SDLK_RIGHT
				&& 
				e.key.keysym.sym == SDLK_DOWN
				)
			{
				DEBUG_MSG("gpp::Events::Event::SLIDE_EVENT");
				input.setCurrent(gpp::Events::Event::SLIDE_EVENT);
			}
			// Hit Ground Event
			else if (e.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
				// Jump Attack Event
			else if (e.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
				// Jump Throw Attack Event
			else if (e.key.keysym.sym == SDLK_h)
			{
				DEBUG_MSG("gpp::Events::Event::HIT_GROUND_EVENT");
				input.setCurrent(gpp::Events::Event::HIT_GROUND_EVENT);
			}
			break;
				// Deal with KeyReleased
		case SDL_KEYUP:
			// Run and Stop Attack
			if (e.key.keysym.sym == SDLK_z
				&& 
				e.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
			}
			// Stop Attack
			else if(e.key.keysym.sym == SDLK_z)
			{
				DEBUG_MSG("gpp::Events::Event::ATTACK_STOP_EVENT");
				input.setCurrent(gpp::Events::Event::ATTACK_STOP_EVENT);
			}
			// Run and Stop Throw Attack
			else if (e.key.keysym.sym == SDLK_x
				&&
				e.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
			}
			// Stop Throw Attack
			else if (e.key.keysym.sym == SDLK_x)
			{
				DEBUG_MSG("gpp::Events::Event::THROW_STOP_EVENT");
				input.setCurrent(gpp::Events::Event::THROW_STOP_EVENT);
			}
			// Stop Running Right
			else if (e.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_STOP_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_STOP_EVENT);
			}
			// Stop Slide
			else if (e.key.keysym.sym == SDLK_DOWN 
				&&
				e.key.keysym.sym == SDLK_RIGHT)
			{
				DEBUG_MSG("gpp::Events::Event::RUN_RIGHT_START_EVENT");
				input.setCurrent(gpp::Events::Event::RUN_RIGHT_START_EVENT);
			}
			// Stop Moving Up
			else if (e.key.keysym.sym == SDLK_UP)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_UP_STOP_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_UP_STOP_EVENT);
			}
			// Stop Moving Down
			else if (e.key.keysym.sym == SDLK_DOWN)
			{
				DEBUG_MSG("gpp::Events::Event::MOVE_DOWN_STOP_EVENT");
				input.setCurrent(gpp::Events::Event::MOVE_DOWN_STOP_EVENT);
			}
			break;
		default:
			DEBUG_MSG("gpp::Events::Event::NONE");
			input.setCurrent(gpp::Events::Event::NONE);
			break;
		}

		// Handle input to Player
		player.handleInput(input);
	}
	}

	cleanUp();
}

void Game::processEvents(SDL_Event t_e)
{
	// simple event loop
	while (SDL_PollEvent(&t_e) != 0)
	{
		if (t_e.type == SDL_QUIT)
		{
			m_gameIsRunning = false;
		}

		// checks if the escape key is pressed down
		if (t_e.type == SDL_KEYDOWN && t_e.key.keysym.sym == SDLK_ESCAPE)
		{
			m_gameIsRunning = false;
		}

	}
}

void Game::update()
{
	
}

void Game::render()
{
	rendererDraw();
}

void Game::rendererDraw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0);
	SDL_RenderClear(m_renderer);

	SDL_FRect renderSrc{ 0, 0, 0, 0 };
	SDL_FRect renderDest{ 5, 5, 200, 100 };

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
	player.getAnimatedSpriteFrame().render(0, 0, m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Game::cleanUp()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	m_renderer = nullptr;

	SDL_DestroyTexture(m_texture);

	IMG_Quit();
	SDL_Quit();
}