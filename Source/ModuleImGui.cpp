#include "ModuleImGui.h"
#include "Application.h"

ModuleImGui::ModuleImGui(Application * parent, bool start_enabled) : Module(parent,start_enabled)
{
}
ModuleImGui::~ModuleImGui() 
{
}
bool ModuleImGui::Init()
{
	ImGui_ImplSdlGL2_Init(App->window->window);
	return true;
}
update_status ModuleImGui::PreUpdate(float dt)
{
	ImGui_ImplSdlGL2_NewFrame(App->window->window);

	return UPDATE_CONTINUE;
}
update_status ModuleImGui::Update(float dt)
{
	
	//Create all UI items here
	//----TEST WINDOW
	
	if (DrawTopBar() != UPDATE_CONTINUE)
		return UPDATE_STOP;

	return UPDATE_CONTINUE;
}
update_status ModuleImGui::PostUpdate(float dt)
{
	//Use Panels
	console.Print();
	ImGui::Render();
	return UPDATE_CONTINUE;
}
bool ModuleImGui::CleanUp()
{
	ImGui_ImplSdlGL2_Shutdown();
	return true;
}
update_status ModuleImGui::DrawTopBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Quit", "ESC"))
			{
				return UPDATE_STOP;
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Create"))
		{
			if (ImGui::MenuItem("Sphere"))
			{
				show_sphere_creator = true;
			
			}
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Tools"))
		{
			if (ImGui::MenuItem("Random Number Generator"))
			{
				show_random_num_gen = !show_random_num_gen;
			}
			if (ImGui::MenuItem("Console"))
			{
				show_console = !show_console;
			}
			if (ImGui::MenuItem("ImGui Demo"))
			{
				show_test_window = !show_test_window;
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Other..."))
		{
			if (ImGui::MenuItem("Link To Repository"))
			{
				App->OpenWeb("https://github.com/BooLAW/Pau-Bonet-3D-Game-Engine");
			}
			ImGui::EndMenu();
		}

		if (show_random_num_gen)ShowRandomCalculatorWindow();
		if (show_test_window)ShowTestWindow();
		if (show_console)ShowConsole();
		if (show_sphere_creator)ShowSphereCreator();


		ImGui::EndMainMenuBar();
	}
	return UPDATE_CONTINUE;
}
void ModuleImGui::ShowRandomCalculatorWindow()
{
	ImGui::Begin("Random Number Generator", &show_random_num_gen);
	ImGui::Text("Random Generator tool:");
	ImGui::Text("-Random Integer between the 2 values:");
	ImGui::DragInt("Minimum", &i_min, 1, 0, 100);
	ImGui::DragInt("Maximum", &i_max, 1, 0, 100);
	if (ImGui::Button("Generate Int") == true)
	{
		i_rand = (rand() % (i_max - i_min)) + i_min;
	}
	ImGui::Text("%d", i_rand);
	ImGui::Text("Random Float Generator:");
	if (ImGui::Button("Generate float") == true)
	{
		//std function
		f_rand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}
	ImGui::Text("%f", f_rand);


	ImGui::End();
}
void ModuleImGui::ShowTestWindow()
{
	ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
	ImGui::ShowTestWindow(&show_test_window);
}
void ModuleImGui::ShowConsole()
{
	if(!console.is_active)
		console.SetActive(true);
}
void ModuleImGui::ShowSphereCreator()
{
	if (ImGui::Begin("Sphere Creator"))
	{
		ImGui::InputInt("Radius", &rad_aux);
		ImGui::InputInt("Position X", &x_aux);
		ImGui::InputInt("Position Y", &y_aux);
		ImGui::InputInt("Position Z", &z_aux);
		if (ImGui::SmallButton("Create"))
		{
			pos_aux.Set(x_aux, y_aux, z_aux);
			App->physics->CreateSphere(pos_aux, rad_aux);

		}
		if (ImGui::SmallButton("Reset"))
		{
			x_aux = y_aux = z_aux = rad_aux =0;
		}

		ImGui::End();
	}
}
void ModuleImGui::AddToConsole(const std::string text)
{
	console.Add(text);
}