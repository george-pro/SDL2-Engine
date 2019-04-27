#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>

class Application {
public:
	SDL_Window* window;
	SDL_Surface* canvas;

	Application(const char* title, int width, int height);

	virtual void handleInput(SDL_Event event);
	virtual void update();
	virtual void render(double lag);

	void run();

	~Application();
};

#endif