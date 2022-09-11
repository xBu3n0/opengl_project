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

// Contem todos os dados e funcionalidades para o funcionamento.
namespace app
{
    class App
    {
        public:
            // Inicializa o `window` e a `camera`
            App();
            App(const char* screenName, int width, int height, bool fullscreen);
            // Permite ao usuário inserir dados, junto a novos shaders para serem renderizados. 
            void addMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader);
            void addMeshWIBO(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader);
            // Depois de tudo adicionado, entra no looping
            void run();
        private:
            win::Window             *window;
            camera::Camera          *camera;
            std::vector<mesh::Mesh*> meshList;
    };
}