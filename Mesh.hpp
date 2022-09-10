#pragma once

#include "Shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace mesh
{
    class Mesh
    {
        public:
            Mesh();
            shader::Shader *shader;
            // Cria a mesh + shader que será utilizado para essa mesh.
            void CreateMesh(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader);
            
            // Desenha a mesh
            void RenderMesh();
            void ClearMesh();

            ~Mesh();

        private:
            GLuint VAO, VBO, IBO;
            GLsizei indexCount;
    };
}