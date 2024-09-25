#pragma once
#include "video.hpp"
#include "episodio.hpp"
#include <vector>

class series:public video
{ 
protected:
    std::vector<episodio> e_vector; 
public:
    series();
    series(int id, const std::string& titulo, int duracion, const std::string& genero, int calificacion);
    

    void mostrarCali() override;
    std::vector<episodio> mostrarEpisodios();

    void agregarEpisodio(const episodio&);

    episodio getEpisodio(int index);
};