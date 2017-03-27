
#include "SDL.h"

/* Function Prototypes */
void PrintKeyInfo(SDL_KeyboardEvent * key);
void PrintModifiers(SDL_Keymod mod);

/* main */
int main(int argc, char *argv[])
{

    SDL_Event event;
    int quit = 0;

    /* Initialise SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialise SDL: %s\n", SDL_GetError());
        exit(-1);
    }

    /* Set a video mode */
    SDL_Window *window;
    if (!(window = SDL_CreateWindow("An SDL2 window",   // window title
                                    SDL_WINDOWPOS_UNDEFINED,    // initial x position
                                    SDL_WINDOWPOS_UNDEFINED,    // initial y position
                                    640,        // width, in pixels
                                    480,        // height, in pixels
                                    SDL_WINDOW_RESIZABLE        // flags - see below
          ))) {
        fprintf(stderr, "Could not set video mode: %s\n", SDL_GetError());
        SDL_Quit();
        exit(-1);
    }

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.key.repeat == 0) {
                switch (event.type) {
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    PrintKeyInfo(&event.key);
                    break;

                case SDL_QUIT:
                    quit = 1;
                    break;

                default:
                    break;
                }
            }
        }
    }

    SDL_Quit();
    exit(0);
}

/* Print all information about a key event */
void PrintKeyInfo(SDL_KeyboardEvent * key)
{
    if (key->type == SDL_KEYUP)
        printf("Release:- ");
    else
        printf("Press:- ");

    printf("Scancode: 0x%02X", key->keysym.scancode);
    printf(", Name: %s", SDL_GetKeyName(key->keysym.sym));
    printf("\n");
    PrintModifiers(key->keysym.mod);
}

/* Print modifier info */
void PrintModifiers(SDL_Keymod mod)
{
    printf("Modifers: ");
    if (mod == KMOD_NONE) {
        printf("None\n");
        return;
    }
    if (mod & KMOD_NUM)
        printf("NUMLOCK ");
    if (mod & KMOD_CAPS)
        printf("CAPSLOCK ");
    if (mod & KMOD_LCTRL)
        printf("LCTRL ");
    if (mod & KMOD_RCTRL)
        printf("RCTRL ");
    if (mod & KMOD_RSHIFT)
        printf("RSHIFT ");
    if (mod & KMOD_LSHIFT)
        printf("LSHIFT ");
    if (mod & KMOD_RALT)
        printf("RALT ");
    if (mod & KMOD_LALT)
        printf("LALT ");
    if (mod & KMOD_CTRL)
        printf("CTRL ");
    if (mod & KMOD_SHIFT)
        printf("SHIFT ");
    if (mod & KMOD_ALT)
        printf("ALT ");
    printf("\n");
}
