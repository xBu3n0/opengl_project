#include "Mesh.hpp"
#include "Shader.hpp"
#include <GL/gl.h>

namespace mesh
{
    Mesh::Mesh()
    {
    	VAO = 0;
    	VBO = 0;
    	IBO = 0;
    	indexCount = 0;
        useIBO = false;
    }

    void Mesh::CreateMeshWIBO(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader)
    {
    	indexCount = numOfIndices;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        useIBO = true;
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * numOfIndices, indices, GL_STATIC_DRAW);

        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * numOfVertices, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);

        shader = new shader::Shader();
        shader->CreateFromFiles(vShader, fShader);
    }

    void Mesh::CreateMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader)
    {
        useIBO = false;
        arraySize = numOfVertices;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, numOfVertices, vertices, GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        shader = new shader::Shader();
        shader->CreateFromFiles(vShader, fShader);
    }

    void Mesh::RenderMesh()
    {//Vincula os dados para fazer o desenho, depois de desenhado, desvincula eles. 
    	if(useIBO == true)
            rMeshWIBO();
        else
            rMeshWOIBO();
    }

    void Mesh::rMeshWIBO()
    {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glUseProgram(0);
    }

    void Mesh::rMeshWOIBO()
    {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, arraySize);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        glUseProgram(0);
    }

    void Mesh::ClearMesh()
    {// Descructor
    	if(IBO != 0)
    	{
    		glDeleteBuffers(1, &IBO);
    		IBO = 0;
    	}

    	if(VBO != 0)
    	{
    		glDeleteBuffers(1, &VBO);
    		VBO = 0;
    	}

    	if(VAO != 0)
    	{
    		glDeleteVertexArrays(1, &VAO);
    		VAO = 0;
    	}

        shader->ClearShader();

    	indexCount = 0;
    }


    Mesh::~Mesh()
    {
    	ClearMesh();
    }
}