#include "Include.hpp"
#include "marchingCubes.hpp"

#include <glm/common.hpp>
#include <stdlib.h>

GLfloat surface(glm::vec3 pos)
{// F(x, y, z) = 0
    return pos.x*pos.x + pos.y*pos.y + pos.z*pos.z - 25;
}

GLfloat p2d(float x, float y)
{
    float value = exp((perlin2d(x, y, 0.4, 4)+
    perlin2d(y, x, 0.4, 3)+
    perlin2d(2*x, y, 0.6, 2)+perlin2d(3*y, 5*x, 0.2, 5))/4.0+1.0);

    return exp(value/2.6)/2.0;
}

int main()
{
	const char* title = "Marching Cubes.";
    app::App firstApp(title, 800, 600, false);

    createMontain(firstApp, p2d, glm::vec3(0, 0, 0));
    
    // createCircle(firstApp, 7, glm::vec3 (0, 0, 0), 25);
    
    /*createMCubes(firstApp, surface,
            glm::vec3(-20, -20, -20),
            glm::vec3(20, 20, 20),
            80);*/

    firstApp.run();

    return 0;
}