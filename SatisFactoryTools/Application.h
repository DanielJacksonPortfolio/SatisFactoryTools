#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>
#include <unordered_map>
class Application
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Point mousePos = { 0, 0 };
	SDL_Window* window = nullptr;
public:
	Application(int argc, char** argv);
	~Application();
	bool Input();
	void Update();
	void Draw();
	bool InitSDL();
	void CloseSDL();
};

