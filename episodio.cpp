#include "video.hpp"
#include "episodio.hpp"

episodio::episodio(){}

episodio::episodio(int idSerie,int idCap,string titulo,int temporada,int calif){
    this->idSerie=idSerie;
    this->idCap=idCap;
    this->titulo=titulo;
    this->temporada=temporada;
    this->calif=calif;
}

int episodio::getIdSerie(){
    return idSerie;
}

void episodio::mostrarEpisodio(){
    std::cout<<"Episodio: "<<titulo<<" , calificacion: "<<calif<<"\n";
}

int episodio::getCalifEpisodio(){
    return calif;
}