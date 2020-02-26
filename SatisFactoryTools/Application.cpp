#include "Application.h"

#include <iostream>

Application::Application(int argc, char** argv)
{
	InitSDL();
	while (1)
	{
		Update();
		if (!Input())
		{
			std::cout << "Quit" << std::endl;
			break;
		}
		Draw();
	}
	CloseSDL();
}

Application::~Application()
{

}


bool Application::InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	if (TTF_Init() < 0)
	{
		std::cout << "SDL_TTF did not initialise. Error: " << SDL_GetError();
		return false;
	}
	window = SDL_CreateWindow("Basic Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1440, 810, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Window was not created. Error: " << SDL_GetError();
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Renderer was not created. Error: " << SDL_GetError();
		return false;
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	{
		std::cout << "Mixer WAV Initialization Error: " << SDL_GetError();
		return false;
	}
	if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3) == 0)
	{
		std::cout << "Mixer OTHER Initialization Error: " << SDL_GetError();
		return false;
	}
	Mix_AllocateChannels(16);
	std::cout << "SDL Initialized" << std::endl;
	return true;
}

void Application::CloseSDL()
{
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

	std::cout << "SDL Closed" << std::endl;
}


bool Application::Input()
{
	SDL_GetMouseState(&mousePos.x, &mousePos.y);

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		return false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			return false;
		}
		break;
	case SDL_KEYUP:
		/*switch (event.key.keysym.sym)
		{
		}*/
		break;
	}
	return true;
}

void Application::Update()
{

}

void Application::Draw()
{
	SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);
	SDL_RenderClear(renderer);


	SDL_RenderPresent(renderer);
}