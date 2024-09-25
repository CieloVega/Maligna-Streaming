#include "menu.hpp"
#include "consola.hpp"
#include "video.hpp"
#include "peliculas.hpp"
#include "episodio.hpp"
#include "series.hpp"
#include "ExceptionInvalidOption.hpp"
#include <fstream>
#include <iostream>
#include "consola.hpp"

int main(){
    
    try{
        menu m;
        int opcion;

        do{
            opcion=m.menuPrincipal();
        } while(opcion!=6);
    
    }
    catch(const ExceptionInvalidOption& e){
        std::cerr << "Se ha producido una excepcion: " << e.what() << "\n";
        return 1;
    }
return 0;
}
