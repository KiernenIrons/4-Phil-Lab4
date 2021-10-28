#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL2/SDL.h>
#include <vector>
#include "Debug.h"
#include "Clock.h"

using namespace std;

class AnimatedSprite
{
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture*);
	AnimatedSprite(SDL_Texture*, SDL_Rect);
	~AnimatedSprite();
	const Clock& getClock();
	float getTime();
	const vector<SDL_Rect>& getFrames();
	void clearFrames();
	const SDL_Rect& getFrame(int);
	void addFrame(const SDL_Rect&);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool);
	const bool getPlayed();
	void setTime(float);
	void update();

	void setTextureRect(SDL_Rect);
	void setTexture(SDL_Texture*);
	SDL_Texture* getTexture(){return m_texture;}
	void render(int, int, SDL_Renderer*);
	
private:
	Clock m_clock;
	float m_time;
	vector<SDL_Rect> m_frames;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;

	SDL_Texture* m_texture;
	SDL_Rect m_rect;
	int m_textureWidth;
	int m_textureHeight;
};

#endif // !ANIMATED_SPRITE_H