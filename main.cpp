#include "Include.hpp"
#include "marchingCubes.hpp"

#include <stdlib.h>

GLfloat f(glm::vec3 pos)
{
    return pos.x * pos.x + pos.y * pos.y + pos.z * pos.z - 25;
}

int main()
{
	const char* title = "Marching Cubes.";
    app::App firstApp(title, 800, 600, false);

    // createMontain(firstApp);
    // createCircle(firstApp, 7, glm::vec3 (0, 0, 0), 25);
    createMCubes(firstApp, f,
            glm::vec3(-10, -10, -10),
            glm::vec3(10, 10, 10),
            80);

    firstApp.run();

    return 0;
}