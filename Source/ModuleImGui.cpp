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
	if (close_app)
	{
		return UPDATE_STOP;
	}
	//Create all UI items here
	DrawTopBar();
	//----TEST WINDOW
	ImGui::SetNextWindowPos(ImVec2(650, 20),ImGuiCond_Always);
	ImGui::ShowTestWindow(&show_test_window);

	return UPDATE_CONTINUE;
}
update_status ModuleImGui::PostUpdate(float dt)
{
	ImGui::Render();
	return UPDATE_CONTINUE;
}
bool ModuleImGui::CleanUp()
{
	ImGui_ImplSdlGL2_Shutdown();

	return true;
}
void ModuleImGui::DrawTopBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Quit","ESC"))
			{
				close_app = true;
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
		ImGui::EndMainMenuBar();
	}
	
}
void DrawRandomCalculatorWindow()
{

}
