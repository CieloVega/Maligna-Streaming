#pragma once
#include <iostream>
using namespace std;

class video{
protected:
    int ID=0;
    string nombre="";
    int duracion=0;
    string genero="";
    int calificacion=1;
public:
    video();
    virtual ~video();
    video(int,string,int,string,int);

    int getCali();
    string getGenero();
    string getNombre();
    int getId();
    int getDuracion();

    std::string setNombre();
    int setCalificacion();

    virtual void mostrarCali()=0;

    void mostrarVideo();
    void calificarVideo(std::string,int);
    virtual int operator+(int);
};