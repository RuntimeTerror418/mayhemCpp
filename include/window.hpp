//
// Created by SeasonedCoder on 6/17/2023.
//

#ifndef MAYHEMCPP_WINDOW_H
#define MAYHEMCPP_WINDOW_H

#include <pch.h>

namespace mhy {

    class Window {

    public:
        Window() = delete;
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;
        Window(const int& w, const int& h, const char* t, int majorVersion = 3, int minorVersion = 3);
        [[nodiscard]] int& getWidth() const;
        [[nodiscard]] int& getHeight() const;
        [[nodiscard]] std::string getVersion() const;
        void setTimeStep(double t);
        void start();



    protected:
        virtual void onStart(GLFWwindow* win){ };
        virtual void onUpdate(float dt){ };
        virtual void onDraw(GLFWwindow* win) = 0;
        virtual void onResize(GLFWwindow* win){ };
        virtual void onClose(GLFWwindow* win){ }

    private:
        GLFWwindow* window{ };
        int size[2]{ 0 };
        int version[2]{ 0 };
        std::string title;
        float lastTime { };
        bool useFixTimeStep { false };
    };

}

#endif //MAYHEMCPP_WINDOW_H
