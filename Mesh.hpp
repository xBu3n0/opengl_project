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
            void CreateMeshWIBO(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader);
            void CreateMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader);
            // Desenha a mesh
            void RenderMesh();
            void rMeshWIBO();
            void rMeshWOIBO();
            void ClearMesh();

            ~Mesh();

        private:
            bool useIBO;
            GLuint VAO, VBO, IBO;
            GLsizei indexCount, arraySize;
    };
}