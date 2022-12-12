#include <stdio.h>
#include <SDL2/SDL.h>

#ifdef main
#undef main
#endif

int main(int argc, char *argv[]) {
//	SDL_Renderer *renderer;
//	SDL_Window *window;
//	int rendererFlags, windowFlags;

//	rendererFlags = SDL_RENDERER_ACCELERATED;
//	windowFlags = 0;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("mametchi couldn't initialize SDL2 video!\n");
	} else {
		printf("mametchi got SDL2 video working! yaaa!!!\n");
	}
	
	SDL_Quit();
	
	
	return 1;
}