#include <stdio.h>
#include "SDL2/SDL.h"


SDL_Window* window = 0;
SDL_Renderer* render = 0;
typedef enum { false, true } bool;
SDL_Texture* m_pTexture; // the new SDL_Texture variable
SDL_Rect m_sourceRectangle; // the first rectangle
SDL_Rect m_destinationRectangle; // another rectangle



int init(const char* title, int xpos, int ypos, int height, int width, int flags){
  window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);




    if(window != 0)
  {
       render = SDL_CreateRenderer(window, -1, 0);


  }
     else
  {
      return 1;}

  }


void renderize()
{

 SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
 SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
 m_pTexture = SDL_CreateTextureFromSurface(render, pTempSurface);
 SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
 m_destinationRectangle.x = m_sourceRectangle.x = 0;
 m_destinationRectangle.y = m_sourceRectangle.y = 0;
 m_destinationRectangle.w = m_sourceRectangle.w;
 m_destinationRectangle.h = m_sourceRectangle.h;
 SDL_RenderClear(render);
 SDL_RenderCopy(render, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
 SDL_RenderPresent(render);
}

void clean(){

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(render);
  SDL_Quit();

}

int main(int argc, char *argv[]){
  init("SDL game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

  renderize();
  SDL_Delay(1000);
  clean();

  return 0;
}
