#include "Include.hpp"
#include "circulo.hpp"
#include <stdlib.h>

int main()
{
	const char* title = "Um simples terreno utilizando de Perlin Noise";
    app::App firstApp(title, 800, 600, false);

    // createMontain(firstApp);
    createCircle(firstApp, 7, 5, 5, 5);

    firstApp.run();

    return 0;
}