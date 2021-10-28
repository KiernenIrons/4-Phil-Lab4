#include "Events.h"

#include "DecendLadderPlayerState.h"

#include "ClimbDownPlayerState.h"
#include "RunRightPlayerState.h"
#include "DiedPlayerState.h"

PlayerState* DecendLadderPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::MOVE_DOWN_START_EVENT)
	{
		DEBUG_MSG("DecendLadderPlayerState -> ClimbDownPlayerState");
		return new ClimbDownPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::RUN_RIGHT_START_EVENT)
	{
		DEBUG_MSG("DecendLadderPlayerState -> RunRightPlayerState");
		return new RunRightPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("DecendLadderPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void DecendLadderPlayerState::update(Player& player) {}
void DecendLadderPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering DecendLadderPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(SDL_Rect{1608, 464, 282, 464});

	player.getAnimatedSprite().setTime(0.05f);
}
void DecendLadderPlayerState::exit(Player& player)
{
	DEBUG_MSG("Exiting DecendLadderPlayerState");
}