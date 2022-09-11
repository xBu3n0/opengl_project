#pragma once

/*
Source das tabelas:
http://paulbourke.net/geometry/polygonise/

Código NÃO está 100% funcional ainda.
*/

#include "App.hpp"
#include <glm/fwd.hpp>
#include <math.h>

typedef struct
{
   glm::vec3 p[8];
   double val[8];
} GRIDCELL;

glm::vec3 vertexInterp(double isolevel, glm::vec3 u, glm::vec3 v, GLfloat u_val, GLfloat v_val);

void evalGrid(GRIDCELL grid, std::vector<GLfloat> &triangles);

void createMCubes(app::App &fapp, GLfloat (*function)(glm::vec3 pos),
                glm::vec3 startPoint, glm::vec3 endPoint, uint n_partitions);