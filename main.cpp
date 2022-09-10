#include "Include.hpp"
#include <stdlib.h>

int main()
{
	const char* title = "Um simples terreno utilizando de Perlin Noise";
    app::App firstApp(title, 800, 600, false);

    createMontain(firstApp);

    firstApp.run();

    return 0;
}