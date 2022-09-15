#include "Include.hpp"
#include "marchingCubes.hpp"

#include <glm/common.hpp>
#include <stdlib.h>

GLfloat surface(glm::vec3 pos)
{// F(x, y, z) = 0
    return cosh(1/pos.x) + log(abs(pos.y)) + exp(pos.z) - 2;
}

GLfloat p2d(float x, float y)
{
    return perlin2d(x, y, 0.4, 1);
}

int main()
{
	const char* title = "Marching Cubes.";
    app::App firstApp(title, 800, 600, false);

    // createMontain(firstApp, p2d, glm::vec3(6, 6, 6));
    
    // createCircle(firstApp, 7, glm::vec3 (0, 0, 0), 25);
    
    createMCubes(firstApp, surface,
            glm::vec3(-20, -20, -20),
            glm::vec3(20, 20, 20),
            80);

    firstApp.run();

    return 0;
}