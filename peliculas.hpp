#pragma once
#include "video.hpp"

class peliculas:public video
{
public:
    peliculas();
    peliculas(int id, string titulo, int duracion, string genero, int calificacion);
    void mostrarCali() override;
};