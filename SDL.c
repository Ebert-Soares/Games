#include <stdio.h>
#include "SDL2/SDL.h"


SDL_Window* window = 0;
SDL_Renderer* render = 0;
typedef enum { false, true } bool;
SDL_Texture* texture;
SDL_Rect fRetangle;
SDL_Rect dRetangle;


int textureDef(){
  SDL_Surface* surface = SDL_LoadBMP("assets/tiger.bmp");
  texture = SDL_CreateTextureFromSurface(render, surface);
  SDL_FreeSurface(surface);
  SDL_QueryTexture(texture, NULL, NULL, &fRetangle.w, &fRetangle.h);

  dRetangle.x = fRetangle.x = 0;
  dRetangle.y = fRetangle.y = 0;
  dRetangle.w = fRetangle.w;
  dRetangle.h = fRetangle.h;

}

int init(const char* title, int xpos, int ypos, int height, int width, int flags){
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
  window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if(window != 0)
  {
       render = SDL_CreateRenderer(window, -1, 0);

  }
     else
  {
      return 1;}

  }
}

void renderize()
{

 SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
 SDL_RenderClear(render);
 SDL_RenderCopy(render, texture, &fRetangle, &dRetangle);
 SDL_RenderPresent(render);
}

void clean(){

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(render);
  SDL_Quit();

}

int main(int argc, char *argv[]){

  textureDef();


  init("SDL game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, fRetangle.h, fRetangle.w, SDL_WINDOW_SHOWN);
  renderize();
  SDL_Delay(1000);
  clean();

  return 0;
}
