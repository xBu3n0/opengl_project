#pragma once

#include <vector>
#include <stdint.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

namespace app
{
    class App
    {
        public:
            App();
            App(const char* screenName, int width, int height, bool fullscreen);
            void addMesh(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader);
            void run();
        private:
            win::Window             *window;
            camera::Camera          *camera;
            std::vector<mesh::Mesh*> meshList;
    };
}