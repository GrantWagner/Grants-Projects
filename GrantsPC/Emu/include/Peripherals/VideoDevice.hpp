//file header

//header safeguards
#ifndef _VIDEO_DEVICE_HPP_
#define _VIDEO_DEVICE_HPP_

//needed includes
#include <SDL.h>

using namespace std;

class VideoDevice {
public:
  void init();
  void  cleanup();

private:
  int SCREEN_WIDTH = 640;
  int SCREEN_HEIGHT = 480;

  //The window we'll be rendering to
  SDL_Window* window = NULL;

  Uint32 * pixels;
  SDL_Renderer * renderer;
  SDL_Texture * texture;

};

//more headersafeguards
#endif
