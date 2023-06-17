//
// Created by SeasonedCoder on 6/17/2023.
// add error return and break function
// resize function
//

#include <window.hpp>

mhy::Window::Window(const int& w, const int& h, const char* t, int majorVersion, int minorVersion) {
    size[0] = w;
    size[1] = h;
    title = t;
    version[0] = majorVersion;
    version[1] = minorVersion;

    if(!glfwInit()) {
        std::cerr << "Unable to initialize glfw" << std::flush;
        throw std::exception();
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(w, h, t, nullptr, nullptr);

    if(!window) {
        std::cerr << "GLFW unable to create window" << std::flush;
        throw std::exception();
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGL()) {
        std::cerr << "Glad unable to load opengl for version: " << majorVersion << ":" << minorVersion << std::flush;
        throw std::exception();
    }

}


void mhy::Window::start() {
    glClearColor(0, 0, 1, 1);
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
}
