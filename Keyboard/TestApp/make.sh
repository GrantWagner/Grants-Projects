#!/bin/sh
reset
gcc keyboard.c $(pkg-config --cflags --libs sdl2)
./a.out 
