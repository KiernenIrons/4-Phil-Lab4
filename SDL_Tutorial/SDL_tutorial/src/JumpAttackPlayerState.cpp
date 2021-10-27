#include "../include/Events.h"

#include "../include/JumpAttackPlayerState.h"

#include "../include/RunRightPlayerState.h"
#include "../include/GlidePlayerState.h"
#include "../include/DiedPlayerState.h"

PlayerState* JumpAttackPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpAttackPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
	{
		DEBUG_MSG("JumpAttackPlayerState -> GlidePlayerState");
		return new GlidePlayerState();
	}
	return nullptr;
}
void JumpAttackPlayerState::update(Player& player) {}
void JumpAttackPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpAttackPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{1329, 1992, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1851, 1992, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{2373, 1992, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1329, 2514, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1851, 2514, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{2373, 2514, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1329, 3036, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1851, 3036, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{2373, 3036, 504, 522});
	player.getAnimatedSprite().addFrame(SDL_Rect{1329, 3558, 504, 522});

	player.getAnimatedSprite().setTime(0.03f);
}
void JumpAttackPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpAttackPlayerState");
}