#include "SDL.h"
#undef main

#include "imgui.h"
//#include "imgui_sdl.h"
#include "imgui_impl_sdl.h"

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("SDL2 ImGui Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  io.Fonts->AddFontDefault();

  ImGui_ImplSDL2_InitForMetal(window);
  //ImGui_ImplSDL2_NewFrame(window);

	//ImGui::CreateContext();
	//ImGuiSDL::Initialize(renderer, 800, 600);
  //ImGui_ImplSDL2_Init(window);
  //ImGui_ImplSDL2_NewFrame(window);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 100, 100);
	{
		SDL_SetRenderTarget(renderer, texture);
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderTarget(renderer, nullptr);
	}

	bool run = true;
	while (run)
	{
		//ImGuiIO& io = ImGui::GetIO();

		int wheel = 0;

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
      ImGui_ImplSDL2_ProcessEvent(&e);
			if (e.type == SDL_QUIT) run = false;
      /*
			else if (e.type == SDL_WINDOWEVENT)
			{
				if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					io.DisplaySize.x = static_cast<float>(e.window.data1);
					io.DisplaySize.y = static_cast<float>(e.window.data2);
				}
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				wheel = e.wheel.y;
			}
      */
		}



    ImGui_ImplSDL2_NewFrame(window);
		ImGui::NewFrame();

		//ImGui::ShowDemoWindow();

		//ImGui::Begin("Image");
		//ImGui::Image(texture, ImVec2(100, 100));
		//ImGui::End();

		SDL_SetRenderDrawColor(renderer, 114, 144, 154, 255);
		SDL_RenderClear(renderer);

		//ImGui::Render();
		//ImGuiSDL::Render(ImGui::GetDrawData());

		SDL_RenderPresent(renderer);
	}

	//ImGuiSDL::Deinitialize();
  ImGui_ImplSDL2_Shutdown();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	ImGui::DestroyContext();

	return 0;
}