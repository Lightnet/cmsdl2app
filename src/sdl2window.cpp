#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>

#include <string.h>
#include <SDL.h>

#include <flecs.h>

using namespace std;

struct Position {
  float x;
  float y;
};

struct Velocity {
  float x;
  float y;
};

/* Component type */
struct Message {
  const char *text;
};

void UpdateRender();

#undef main
int main(int argc, char** argv)
{
  //https://flecs.docsforge.com/master/quickstart/#components
  flecs::world ecs(argc, argv);
  //flecs::world ecs;
  ecs.set_target_fps(60.0f);

  printf("Initialize the SDL2...\n");
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
    printf("Failed to initialize the SDL2 library\n");
    printf("SDL2 Error: ", SDL_GetError(), "\n");
    return -1;
  }

	SDL_Window* window = SDL_CreateWindow("SDL with Premake", 150, 150, 800, 600, SDL_WINDOW_SHOWN);

  // Check that the window was successfully created
  if (window == NULL) {
    // In the case that the window could not be made...
    printf("Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  //SDL_Surface *window_surface = SDL_GetWindowSurface(window);
  //The surface contained by the window
  SDL_Surface* screenSurface = NULL;
  //if(!window_surface){
    //printf("Failed to get the surface from the window\n");
    //return -1;
  //}

  ecs.component<Position>();
  ecs.component<Velocity>();
  //ecs.component<Physics>();

  ecs.system<Position, const Velocity>()
    .each([](flecs::entity e, Position& p, const Velocity& v) {    
      p.x += v.x;
      p.y += v.y;
      //std::cout << "Moved " << e.name() << " to {" << p.x << ", " << p.y << "}" << std::endl;
    });

  ecs.system<Message>()
    .each([](flecs::entity, Message& messages) {
        std::cout << messages.text << std::endl;
    });

  //ecs.entity().set<Message>({"Hello Flecs!"});

  ecs.entity("MyEntity")
    .set<Position>({0, 0})
    .set<Velocity>({1, 1});

  //std::cout << "Application simple_system is running..." << std::endl;

  printf("init window render loop \n");

  // https://discourse.libsdl.org/t/delta-time/14895
  // https://stackoverflow.com/questions/29302203/sdl-delta-time-reset/29306509
  // https://thenumbat.github.io/cpp-course/sdl2/08/08.html
  // https://www.cplusplus.com/reference/cstdio/printf/
  const float FRAME_TIME = 1.0f / 60.0f;  // delta time for 60 FPS

  unsigned int startTicks;
  unsigned int endTicks;
  float delta_time = 0.0f;
  printf("FRAME_TIME: %f \n", FRAME_TIME);

  bool keep_window_open = true;
  SDL_Event e;
  //bool render = false;
  Uint64 start_fps;
  Uint64 end_fps;
  float elapsed_fps;

  Uint32 totalFrameTicks = 0;
	Uint32 totalFrames = 0;
  
  while(keep_window_open)
  {
    //===========================================
    // START FRAME TIMING
    //===========================================
    totalFrames++;
    startTicks = SDL_GetTicks();
    start_fps = SDL_GetPerformanceCounter();

    //===========================================
    // update ecs component
    //===========================================
    //ecs.progress();
    //ecs.progress(0.1f);
    //ecs.progress(0.001f);
    ecs.progress(delta_time);
    //===========================================
    // POLL EVENT
    //===========================================
    while(SDL_PollEvent(&e) > 0)
    {
      switch(e.type)
      {
        case SDL_QUIT:
          keep_window_open = false;
          break;
      }
    }
    //===========================================
    // UPDATE
    //===========================================
    //


    //===========================================
    // RENDER LOOP
    //===========================================
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );
    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    SDL_UpdateWindowSurface(window);
    
    //===========================================
    // END FRAME TIMING
    //===========================================
    endTicks = SDL_GetTicks();
    //printf("startTicks: %d \n", startTicks);
    //printf("endTicks: %d \n", endTicks);
    //delta_time = (startTicks - endTicks) / 1000.0f;
    //delta_time = (float)(endTicks - startTicks);
    delta_time = (float)(endTicks - startTicks) / 1000.0f;
    totalFrameTicks += endTicks - startTicks;
    //printf("delta_time: %f \n", delta_time);
    //string fps = "Current FPS: " + to_string(1.0f / delta_time);
    //float fps = 1.0f / delta_time;
    //printf(" %f \n", fps);

    end_fps = SDL_GetPerformanceCounter();
    elapsed_fps = (end_fps - start_fps) / (float)SDL_GetPerformanceFrequency();
    //cout << "Current FPS: " << to_string(1.0f / elapsed_fps) << endl;

  }
  // CLEAN UP VARS
	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}


void UpdateRender(){
  //Get window surface
  //screenSurface = SDL_GetWindowSurface( window );
  //Fill the surface white
  //SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
  //SDL_FillRect( window_surface, NULL, SDL_MapRGB( window_surface->format, 0xFF, 0xFF, 0xFF ) );
  //SDL_BlitSurface(image, NULL, window_surface, NULL);
  //SDL_UpdateWindowSurface(window);
  //last_update_time = current_time;
}