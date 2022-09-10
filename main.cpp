#include "Include.hpp"
#include <stdlib.h>

int main()
{
	const char* title = "Corrigindo bugs.";
    app::App firstApp(title, 800, 600, false);

    createMontain(firstApp);

    firstApp.run();

    return 0;
}