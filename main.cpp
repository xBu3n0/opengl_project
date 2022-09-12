#include "Include.hpp"
#include "marchingCubes.hpp"

#include <stdlib.h>

GLfloat surface(glm::vec3 pos)
{
    return pos.x * pos.x + pos.y * pos.y + pos.z * pos.z - 100;
}

int main()
{
	const char* title = "Marching Cubes.";
    app::App firstApp(title, 800, 600, false);

    createMontain(firstApp, noise2d, glm::vec3(6, 6, 6));
    
    createCircle(firstApp, 7, glm::vec3 (0, 0, 0), 25);
    
    createMCubes(firstApp, surface,
            glm::vec3(-10, -10, -10),
            glm::vec3(10, 10, 10),
            400);

    firstApp.run();

    return 0;
}