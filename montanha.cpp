#include "montanha.hpp"

// Vertex Shader
const char* vShader = "Shaders/shader.vert";

// Fragment Shader
const char* fShader = "Shaders/shader.frag";

/*
	Um código simples para criar uma grade de triangulos, e utilizando de um Perlin noise
	para gerar elevações do terreno.
*/

void createMontain(app::App &fapp)
{
    int height = 1000;
	int width = 1000;
	// descrevo todos os vertices da montanha
	GLfloat *montanhaVertices = (GLfloat*) malloc(sizeof(GLfloat) * 3 * height * width); // 10 x 10

	// dou a altura da montanha
	for(int j = 0; j < width; ++j)
	{
		for(int i = 0; i < height; ++i)
		{
			// Isso é os dados de um ponto.
			montanhaVertices[3*(i+width * j) + 0] = ((GLfloat) i)/((GLfloat) 10); 	// x coord
			montanhaVertices[3*(i+width * j) + 1] =	exp(((GLfloat) perlin2d(i/5.0, j/5.0, 0.4, 1)));	// y coord
			montanhaVertices[3*(i+width * j) + 2] = ((GLfloat) j)/((GLfloat) 10);	// z coord
		}
	}

	unsigned int *montanhaIndices = (uint*) malloc(sizeof(GLfloat) * 6 * (height-1) * (width-1));

	// ordem de como será realizado os desenhos dos triangulos.
	for(int i = 0; i < height-1; ++i)
	{
		for(int j = 0; j < width-1; ++j)
		{
			montanhaIndices[6*(i+(width-1) * j) + 0] = i + width * j;
			montanhaIndices[6*(i+(width-1) * j) + 1] = i + width * (j+1);
			montanhaIndices[6*(i+(width-1) * j) + 2] = i+1 + width * j;

			montanhaIndices[6*(i+(width-1) * j) + 3] = i + width * (j+1);
			montanhaIndices[6*(i+(width-1) * j) + 4] = i+1 + width * j;
			montanhaIndices[6*(i+(width-1) * j) + 5] = i + width * (j+1) + 1;
		}
	}

    fapp.addMesh(montanhaVertices, montanhaIndices, 3 * height * width, 6 * (height-1) * (width-1), vShader, fShader);
}