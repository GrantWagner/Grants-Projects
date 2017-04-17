#include "Peripherals/VideoDevice.hpp"

void VideoDevice::init() {

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  }

  //Create window
  window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if( window == NULL ) {
    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  texture = SDL_CreateTexture(renderer,
                              SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
  pixels = new Uint32[640 * 480];

//draw
  memset( pixels, 255, 640 * 480 * sizeof(Uint32) );
  SDL_UpdateTexture( texture, NULL, pixels, 640 * sizeof(Uint32) );
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  //Wait two seconds
  SDL_Delay( 2000 );

} // init

void VideoDevice::cleanup() {

  delete[] pixels;
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

} // cleanup
