#pragma once

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
//
namespace win
{
    class Window
    {
        public:
            GLFWwindow *mainWindow;
            Window(const char* screenName, int width, int height, bool fullscreen);

            int initialise();

            GLint getBufferWidth();
            GLint getBufferHeight();

            bool getShouldClose();

            bool* getsKeys();
            GLfloat getXChange();
            GLfloat getYChange();

            void swapBuffers();

            ~Window();
        private:
            const char* screenName;
            GLint width, height;
            GLint bufferWidth, bufferHeight;
            bool fullscreen = false;

            bool keys[1024];

            GLfloat lastX;
            GLfloat lastY;
            GLfloat xChange;
            GLfloat yChange;
            bool mouseFirstMoved;
            
            void createCallbacks();
            static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
            static void handleMouse(GLFWwindow* window, double xPos, double yPos);
    };
}