#include "PanelConsole.h"

void PanelConsole::Add(std::string text_to_log)
{
	console_buff.push_back(text_to_log);
}

void PanelConsole::SetActive(bool active)
{
	is_active = active;
}
void PanelConsole::Print() {
	ImGui::Begin("Console");
	for (int i = 0; i<console_buff.size();i++)
		ImGui::Text(console_buff[i].c_str());

	ImGui::End();
}
void PanelConsole::Clear() {
	console_buff.clear();
}

