#ifndef __PANEL_CONSOLE__
#define __PANEL_CONSOLE__

#include "imgui.h"
#include "Globals.h"

class PanelConsole {
public:
	void Print();
	void Add(std::string text_to_log);
	void Clear();

	void SetActive(bool active);
public:
	std::vector<std::string> console_buff;
	bool is_active = false;
};
#endif // !__PANEL_CONSOLE__

