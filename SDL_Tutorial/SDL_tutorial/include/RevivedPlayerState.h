#ifndef REVIVED_PLAYER_STATE_H
#define REVIVED_PLAYER_STATE_H

#include "Player.h"
#include "PlayerState.h"
#include "Clock.h"

class RevivedPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	Clock m_clock;
};

#endif