#include <RedHammer.h>

#include "imgui/imgui.h"

class DebugLayer : public Hammer::Layer
{
public:
    DebugLayer()
        : Layer("Debug") { }

    void OnUpdate() override
    {
        if (Hammer::Input::IsKeyPressed(RH_KEY_TAB))
        {
            RH_TRACE("Tab key is pressed!");
        }
    }

    void OnEvent(Hammer::Event& event) override
    {
    }

    void OnImGuiRender() override
    {
        bool toolbarActive = true;

        ImGui::Begin("Elevate Engine", &toolbarActive, ImGuiWindowFlags_MenuBar);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Exit")) { exit(0); }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Debug"))
            {
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::Text("Elevate Engine - Debugging");
        ImGui::End();
    }
};

class Sandbox : public Hammer::Application
{
public:
    Sandbox() 
    {   
        PushLayer(new DebugLayer());
    }

    ~Sandbox()
    {

    }
};

Hammer::Application* Hammer::CreateApplication() {
    return new Sandbox();
}