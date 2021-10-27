#ifndef SLIDE_PLAYER_STATE_H
#define SLIDE_PLAYER_STATE_H

#include "../include/Player.h"
#include "../include/PlayerState.h"
#include "../include/Clock.h"

class SlidePlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	Clock m_clock;
};

#endif