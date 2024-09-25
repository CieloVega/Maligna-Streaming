#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdio_ext.h>
#include "consola.hpp"

//Limpia la consola
void consola::cls()
{
    system("clear");
}

//Pausa la ejecucion hasta presionar <ENTER>
void consola::pausa()
{
    std::cout << "Presiona <ENTER> para continuar...\n";
    // getchar esperara a que el usuario pulse una tecla para continuar
    __fpurge(stdin);
    getchar();
}
