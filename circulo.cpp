/*
    O código atual ainda não está 100% funcional

Desenhando triangulos que não deveria
Possivelmente usando mais espaço que deveria
*/

#include "circulo.hpp"
#include <math.h>
#define PI 3.1415926

// Vertex Shader
const char* vShaderCircle = "Shaders/shader.vert";

// Fragment Shader
const char* fShaderCircle = "Shaders/shader.frag";

void createCircle(app::App &fapp, GLfloat radius, GLfloat xpos, GLfloat ypos, GLfloat zpos)
{
    int split = 20;

	GLfloat *circuloVertices = (GLfloat*) malloc(sizeof(GLfloat) * 3 * ((split) * (split) + 3));

    GLfloat theta   = 2 * PI/((GLfloat) split-1);
    GLfloat phi     = PI/((GLfloat) split-1);

	for(int j = 0; j < split; ++j)
	{
		for(int i = 0; i < split; ++i)
		{
			// Isso é os dados de um ponto.
			circuloVertices[3*(i+(split) * j) + 0] = xpos - radius * sin(theta * j) * cos(phi * i); // x coord
			circuloVertices[3*(i+(split) * j) + 1] = ypos - radius * cos(theta * j);	            // y coord
			circuloVertices[3*(i+(split) * j) + 2] = zpos - radius * sin(theta * j) * sin(phi * i); // z coord
		}
	}

	unsigned int *circuloIndices = (uint*) malloc(sizeof(GLfloat) * 6 * ((split+1) * (split) + 6));


	for(int j = 0; j < split+1; ++j)
	{
		for(int i = 0; i < split; ++i)
		{
			circuloIndices[6*(i+(split) * j) + 0] = i + split * j;
			circuloIndices[6*(i+(split) * j) + 1] = i + split * (j+1);
			circuloIndices[6*(i+(split) * j) + 2] = i+1 + split * j;

			circuloIndices[6*(i+(split) * j) + 3] = i + split * (j+1);
			circuloIndices[6*(i+(split) * j) + 4] = i+1 + split * j;
			circuloIndices[6*(i+(split) * j) + 5] = i + split * (j+1) + 1;
		}
	}

    for(int i = 0; i < 2 * (split) * split; ++i)
        printf("%d %d %d\n", circuloIndices[3*i], circuloIndices[3*i+1], circuloIndices[3*i+2]);

    fapp.addMesh(circuloVertices, circuloIndices, 3 * (split) * (split)+3, 6 * (split+1) * (split)+6, vShaderCircle, fShaderCircle);
}