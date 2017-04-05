#include "rtv1.h"

void open_window(t_global *g)
{
  SDL_Window *window;
  SDL_Renderer *render;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("RTV1", 100, 100, 800, 800,
           SDL_WINDOW_OPENGL);
  if (window == NULL)
  {
    printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
    exit(0);
  }
  render = SDL_CreateRenderer(window, -1,
			     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_Delay(3000);
}
