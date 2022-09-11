#include "circulo.hpp"
#include <math.h>
#define PI 3.1415926

// Vertex Shader
const char* vShaderCircle = "Shaders/shader.vert";

// Fragment Shader
const char* fShaderCircle = "Shaders/shader.frag";

void createCircle(app::App &fapp, GLfloat radius, GLfloat xpos, GLfloat ypos, GLfloat zpos, int split)
{
	GLfloat *circuloVertices = (GLfloat*) malloc(sizeof(GLfloat) * 3 * (split+1) * (split+1));

    GLfloat theta   = PI/((GLfloat) split);
    GLfloat phi     = 2 * PI/((GLfloat) split);

	for(int j = 0; j < split+1; ++j)
	{
		for(int i = 0; i < split+1; ++i)
		{
			// Isso é os dados de um ponto. (Equações certas)
			circuloVertices[3*(i+(split+1) * j) + 0] = xpos - radius * sin(theta * j) * cos(phi * i);	// x coord
			circuloVertices[3*(i+(split+1) * j) + 1] = ypos - radius * cos(theta * j);					// y coord
			circuloVertices[3*(i+(split+1) * j) + 2] = zpos - radius * sin(theta * j) * sin(phi * i);	// z coord
		}
	}

	for(int i = 0; i < (split+1)*(split+1); ++i)
		printf("%lf %lf %lf\n", circuloVertices[3*i], circuloVertices[3*i+1], circuloVertices[3*i+2]);

	unsigned int *circuloIndices = (uint*) malloc(sizeof(GLfloat) * 6 * (split) * (split));


	for(int j = 0; j < split; ++j)
	{
		for(int i = 0; i < split; ++i)
		{
			circuloIndices[6*(i+(split) * j) + 0] = i + (split+1) * j;
			circuloIndices[6*(i+(split) * j) + 1] = i + (split+1) * (j+1);
			circuloIndices[6*(i+(split) * j) + 2] = i+1 + (split+1) * j;

			circuloIndices[6*(i+(split) * j) + 3] = i + (split+1) * (j+1);
			circuloIndices[6*(i+(split) * j) + 4] = i+1 + (split+1) * j;
			circuloIndices[6*(i+(split) * j) + 5] = i + (split+1) * (j+1) + 1;
		}
	}

    fapp.addMesh(circuloVertices, 			 circuloIndices,
				 3 * (split+1) * (split+1), 6 * (split) * (split),
				 vShaderCircle, fShaderCircle);
}