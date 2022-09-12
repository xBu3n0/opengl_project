#pragma once

#include "App.hpp"
#include "Perlin.hpp"

// Falta adicionar uma função para dar a altura, posição inicial, comprimento e largura.
void createMontain(app::App &fapp, GLfloat (*f)(GLfloat x, GLfloat y), glm::vec3 startPos);