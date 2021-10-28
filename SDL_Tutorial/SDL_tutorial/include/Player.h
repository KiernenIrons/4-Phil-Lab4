#ifndef PLAYER_H
#define PLAYER_H
#include "Events.h"
#include "PlayerState.h"
#include "AnimatedSprite.h"

class Player
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;

public:
	Player() = default;
	Player(const AnimatedSprite&);
	virtual void handleInput(gpp::Events);
	virtual void update();
	AnimatedSprite& getAnimatedSprite();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite&);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState*);
};
#endif

