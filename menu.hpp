#pragma once

#include "series.hpp"
#include "peliculas.hpp"
#include "video.hpp"
#include "episodio.hpp"
#include "consola.hpp"
#include <iostream>
#include <vector>
using namespace std;

class menu{
private:
    std::vector<peliculas> peliculas_vector;
    std::vector<series> series_vector;
    std::vector<episodio> episodio_vector;
protected:
    consola c;
    video* v;
public:
    int menuPrincipal();
    void cargaArchivo(string f);
    int verCatalogo();
    void calificarTitulo();
    void menuSeries();
    void menuPeliculas();

    void CatalogoCalif();
    void CatalogoGenero();

    void epCalif();
};