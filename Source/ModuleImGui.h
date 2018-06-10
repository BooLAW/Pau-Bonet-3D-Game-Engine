#pragma once
#include "Module.h"
#include "Globals.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"

class ModuleImGui : public Module
{
public:
	//functions
	//--CORE--
	ModuleImGui(Application* parent, bool start_enabled = true);
	~ModuleImGui();

	bool Init();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();
	//-----------
	//--DRAWI
	void DrawTopBar();
	void DrawRandomCalculatorWindow();
	//variables

private:
	//functions
	//variables
	bool show_test_window = true;
	bool close_app = false;
	bool show_random_num_gen = true;
};