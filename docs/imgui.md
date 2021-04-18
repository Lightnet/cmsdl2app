








https://stackoverflow.com/questions/58209628/function-to-move-a-sdl2-window-while-mouse-down-flickers-the-window-and-doesnt

https://gigi.nullneuron.net/gigilabs/sdl2-drag-and-drop/



https://discourse.dearimgui.org/t/layout-question-get-childsize/373/5


https://github.com/ocornut/imgui/issues/2109




```c++
ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
```


```c++
ImGuiViewport* viewport = ImGui::GetMainViewport();
ImGui::SetNextWindowPos(viewport->Pos);
ImGui::SetNextWindowSize(viewport->Size);
ImGui::SetNextWindowViewport(viewport->ID);
ImGui::SetNextWindowBgAlpha(0.0f);
```


https://github.com/ocornut/imgui/issues/3131
```
ImGui::Begin("main",nullptr, ImGuiWindowFlags_NoDecoration);
    if(ImGui::Button("my button") ){
        
    }
ImGui::End();
```


https://github.com/ocornut/imgui/issues/3032


https://github.com/ocornut/imgui/issues/261
```c++
IMGUI_API bool Tab(unsigned int index, const char* label, const char* tooltip, int* selected)
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec2 itemSpacing = style.ItemSpacing;
    ImVec4 color = style.Colors[ImGuiCol_Button];
    ImVec4 colorActive = style.Colors[ImGuiCol_ButtonActive];
    ImVec4 colorHover = style.Colors[ImGuiCol_ButtonHovered];
    style.ItemSpacing.x = 1;

    if (index > 0)
        ImGui::SameLine();

    // push the style
    if (index == *selected)
    {
        style.Colors[ImGuiCol_Button] = colorActive;
        style.Colors[ImGuiCol_ButtonActive] = colorActive;
        style.Colors[ImGuiCol_ButtonHovered] = colorActive;
    }
    else
    {
        style.Colors[ImGuiCol_Button] = color;
        style.Colors[ImGuiCol_ButtonActive] = colorActive;
        style.Colors[ImGuiCol_ButtonHovered] = colorHover;
    }

    // Draw the button
    if (ImGui::Button(label))
        *selected = index;

    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::Text("%s", tooltip);
        ImGui::EndTooltip();
    }

    // Restore the style
    style.Colors[ImGuiCol_Button] = color;
    style.Colors[ImGuiCol_ButtonActive] = colorActive;
    style.Colors[ImGuiCol_ButtonHovered] = colorHover;
    style.ItemSpacing = itemSpacing;

    return *selected == index;
}

```

https://github.com/ocornut/imgui/pull/3789

```
// Demonstrate creating a window covering the entire screen/viewport
static void ShowExampleAppFullscreen(bool* p_open)
{
    ImGuiIO& io = ImGui::GetIO();
    static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    if (ImGui::Begin("Example: Fullscreen window", p_open, flags))
    {
        ImGui::CheckboxFlags("ImGuiWindowFlags_NoBackground", &flags, ImGuiWindowFlags_NoBackground);
        ImGui::CheckboxFlags("ImGuiWindowFlags_NoDecoration", &flags, ImGuiWindowFlags_NoDecoration);
        ImGui::Indent();
        ImGui::CheckboxFlags("ImGuiWindowFlags_NoTitleBar", &flags, ImGuiWindowFlags_NoTitleBar);
        ImGui::CheckboxFlags("ImGuiWindowFlags_NoCollapse", &flags, ImGuiWindowFlags_NoCollapse);
        ImGui::CheckboxFlags("ImGuiWindowFlags_NoScrollbar", &flags, ImGuiWindowFlags_NoScrollbar);
        ImGui::Unindent();
    }
    ImGui::End();
}

```