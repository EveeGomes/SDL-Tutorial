#include "SDL.h"
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
   //Initialization flag
   bool success = true;

   //Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
      success = false;
   }
   else
   {
      //Create window
      gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
      if (gWindow == NULL)
      {
         printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
         success = false;
      }
      else
      {
         //Get window surface
         gScreenSurface = SDL_GetWindowSurface(gWindow);
      }
   }
}

int main(int argc, char* argv[])
{
   //The window we'll be rendering to
   SDL_Window* window = NULL;

   //The surface contained by the window
   SDL_Surface* screenSurface = NULL;

   //Initialize SDL
   if (SDL_Init(SDL_INIT_VIDEO) < 0)
   {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
   }
   else
   {
      //Create window
      window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
      if (window == NULL)
      {
         printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      }
      else {
         //Get window surface
         screenSurface = SDL_GetWindowSurface(window);

         //Fill the surface white
         SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

         //Update the surface
         SDL_UpdateWindowSurface(window);

         //Hack to get window to stay up
         SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
      }
   }

   //Destroy window
   SDL_DestroyWindow(window);

   //Quit SDL subsystems
   SDL_Quit();

   return 0;
}