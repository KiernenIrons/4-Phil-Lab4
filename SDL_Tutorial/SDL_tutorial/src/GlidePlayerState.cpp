#include "../include/Events.h"

#include "../include/GlidePlayerState.h"

#include "../include/DiedPlayerState.h"
#include "../include/IdlePlayerState.h"

PlayerState* GlidePlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::HIT_GROUND_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT)
	{
		DEBUG_MSG("GlidePlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void GlidePlayerState::update(Player& player) {
	DEBUG_MSG("GlidePlayerState -> IdlePlayerState");
	if (m_clock.getElapsedTimeAsSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void GlidePlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RevivedPlayerState");

	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{0, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 1992, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 2446, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{443, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{886, 2900, 443, 454});
	player.getAnimatedSprite().addFrame(SDL_Rect{0, 3354, 443, 454});

	player.getAnimatedSprite().setTime(0.03f);
}
void GlidePlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting RevivedPlayerState");
}