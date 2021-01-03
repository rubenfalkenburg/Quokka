#include "Platforms/MacOS/MacOSWindow.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include <backends/imgui_impl_opengl3.cpp>
#include <backends/imgui_impl_glfw.cpp>

namespace QuokkaEngine {

    MacOSWindow::MacOSWindow(const std::uint32_t width, const std::uint32_t height, const std::string title)
    {
        Initialize(width, height, title);
    }

    MacOSWindow::~MacOSWindow()
    {
        Dispose();
    }

    void MacOSWindow::OnUpdate()
    {
        glfwPollEvents();
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Demo Window");
        ImGui::Button("Hello!");
        ImGui::End();
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glfwSwapBuffers(m_window);
    }

    void MacOSWindow::Initialize(const std::uint32_t width, const std::uint32_t height, const std::string title)
    {
        // Glfw
        if(!glfwInit())
            exit(EXIT_FAILURE);
        
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        
        m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        
        if(!m_window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        
        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        // ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init("#version 150");
        ImGui::StyleColorsDark();
    }

    void MacOSWindow::Dispose()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        
        glfwDestroyWindow(m_window);
    }
}
