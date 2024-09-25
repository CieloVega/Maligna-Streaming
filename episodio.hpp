#pragma once
#include "video.hpp"
#include <iostream>

class episodio{
protected:
    int idSerie=1;
    int idCap=1;
    std::string titulo="";
    int temporada=1;
    int calif=1;
public:
    episodio();
    episodio(int,int,std::string,int,int);
    
    int getIdSerie();
    void mostrarEpisodio();
    int getCalifEpisodio();
};