#include "../include/Events.h"

#include "../include/DiedPlayerState.h"

#include "../include/RevivedPlayerState.h"

PlayerState* DiedPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::REVIVED_EVENT)
	{
		DEBUG_MSG("DiedPlayerState -> RevivedPlayerState");
		return new RevivedPlayerState();
	}
	return nullptr;
}
void DiedPlayerState::update(Player& player) {}
void DiedPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering DiedPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	player.getAnimatedSprite().addFrame(SDL_Rect{2454, 0, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2936, 0, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{3418, 0, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2454, 498, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2936, 498, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{3418, 498, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2454, 996, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2936, 996, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{3418, 996, 482, 498});
	player.getAnimatedSprite().addFrame(SDL_Rect{2454, 1494, 482, 498});

	player.getAnimatedSprite().setTime(0.03f);
}
void DiedPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting DiedPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}