#include "series.hpp"
#include "episodio.hpp"
#include <fstream>
#include <iostream>
#include <vector>

series::series():video{}
{
    int sum = 0;
    if(e_vector.size()>0){
        for(int i = 0; i < 3; i++){
        sum += e_vector[i].getCalifEpisodio();
    }
    int average = sum / 3;
    if (average > 5){ 
        average = 5;
    }
    calificacion = average;
    }
    
}

series::series(int id, const std::string& titulo, int duracion, const std::string& genero, int calificacion):video{id,titulo,duracion,genero,calificacion}
{
    int sum = 0;
    if(e_vector.size()>0){
        for(int i = 0; i < 3; i++){
        sum += e_vector[i].getCalifEpisodio();
    }
    int average = sum / 3;
    if (average > 5){ 
        average = 5;
    }
    calificacion = average;
    }
}

void series::mostrarCali(){
    std::cout<<"La calificacion de la serie: "<<nombre<<" es de: "<<calificacion;
}

std::vector<episodio> series::mostrarEpisodios(){
    cout<<"Mostrando Episodios de "<<nombre<<".\n";
    for(int i=0;i<e_vector.size();i++){
        e_vector[i].mostrarEpisodio();
    }
}

void series::agregarEpisodio(const episodio& e){
    e_vector.push_back(e);
}

episodio series::getEpisodio(int index){
    return e_vector[index];
}