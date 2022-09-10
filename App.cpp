#include "App.hpp"
#include "Shader.hpp"

namespace app
{
    App::App()
    {
        window = new win::Window("without title", 800, 600, false);
        camera = new camera::Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f);
    }

    App::App(const char* screenName, int width, int height, bool fullscreen)
    {
        window = new win::Window(screenName, width, height, fullscreen);
        camera = new camera::Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -90.0f, 0.0f, 5.0f, 0.5f);
    }

    void App::addMesh(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader)
    {
        mesh::Mesh *obj = new mesh::Mesh();
        obj->CreateMesh(vertices, indices, numOfVertices, numOfIndices, vShader, fShader);
        meshList.push_back(obj);

        return;
    }

    void App::run()
    {
        GLfloat deltaTime = 0, lastTime = 0;

        GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), ((GLfloat)window->getBufferWidth())/window->getBufferHeight(), 0.1f, 100.0f);

        while (!window->getShouldClose())
        {
            GLfloat now = glfwGetTime();
            deltaTime = now - lastTime;
            lastTime = now;
            
            // Get + Handle User Input
            glfwPollEvents();

            camera->keyControl(window->getsKeys(), deltaTime);
            camera->mouseControl(window->getXChange(), window->getYChange());

            // Limpa a janela
            glClearColor(0.1f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for(int i = 0; i < meshList.size(); ++i)
            {
                meshList[i]->shader->UseShader();

                uniformModel = meshList[i]->shader->GetModelLocation();
                uniformProjection = meshList[i]->shader->GetProjectionLocation();
                uniformView = meshList[i]->shader->GetViewLocation();
                
                glm::mat4 model(1.0f);

                glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
                glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
                glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera->calculateViewMatrix()));

                meshList[i]->RenderMesh();
            }

            window->swapBuffers();
        }
    }
}