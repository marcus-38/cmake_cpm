

#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H
#include "imgui.h"


namespace gui {
    void simpleWindow(ImGuiIO& io, bool& show_demo_window, bool& show_another_window, ImVec4& clear_color);
    void anotherWindow(bool& show_another_window);
}



#endif //SIMPLEWINDOW_H
