#include "../include/Events.h"

#include "../include/JumpPlayerState.h"

#include "../include/DiedPlayerState.h"
#include "../include/JumpAttackPlayerState.h"
#include "../include/JumpThrowAttackPlayerState.h"
#include "../include/GlidePlayerState.h"

PlayerState* JumpPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpAttackPlayerState");
		return new JumpAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerState -> JumpThrowAttackPlayerState");
		return new JumpThrowAttackPlayerState();
	}
	return nullptr;
}
void JumpPlayerState::update(Player& player) {
	DEBUG_MSG("JumpPlayerState -> GlidePlayerState");
	if (m_clock.getElapsedTimeAsSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new GlidePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void JumpPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering JumpPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 1756, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 2239, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4262, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{4624, 2722, 362, 483});
	player.getAnimatedSprite().addFrame(SDL_Rect{3900, 3205, 362, 483});

	player.getAnimatedSpriteFrame().setTime(0.03f);
}
void JumpPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpPlayerState");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}