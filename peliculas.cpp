#include "peliculas.hpp"

peliculas::peliculas():video{}
{
}

peliculas::peliculas(int id, std::string titulo, int duracion, std::string genero, int calificacion)
{
    this->ID=id;
    this->nombre=titulo;
    this->duracion=duracion;
    this->genero=genero;
    this->calificacion=calificacion;
}

void peliculas::mostrarCali(){
    std::cout<<"La calificacion de la pelicula: "<<nombre<<" es de: "<<calificacion;
}