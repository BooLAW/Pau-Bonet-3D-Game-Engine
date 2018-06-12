#ifndef __MODULE_IMGUI_H__
#define __MODULE_IMGUI_H__
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
	//--DRAWING
	update_status DrawTopBar();
	void ShowRandomCalculatorWindow();
	void ShowTestWindow();
	void ShowConsole();
	void ShowSphereCreator();
	//variables

private:
	//functions
	//variables
	bool show_test_window = true;
	bool close_app = false;
	bool show_console = false;
	bool show_random_num_gen = false;
	bool show_sphere_creator = false;
	int i_min = 0;
	int i_max = 100;
	int i_rand = 0;
	float f_rand = 0.0f;
	//Geometrycreator
	int rad_aux = 0;
	int x_aux = 0, y_aux = 0, z_aux = 0;
	vec pos_aux;
};
#endif