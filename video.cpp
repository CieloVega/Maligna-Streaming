#include "video.hpp"

video::video(){
    this->ID=0;
    this->nombre="";
    this->duracion=0;
    this->genero="";
    this->calificacion=1;
}

video::~video(){}

video::video(int ID, std::string nombre, int duracion, std::string genero, int calificacion){
    this->ID=ID;
    this->nombre=nombre;
    this->duracion=duracion;
    this->genero=genero;
    this->calificacion=calificacion;
    if (calificacion>5){
        calificacion=5;
    }
}

int video::getCali(){
    return calificacion;
}

std::string video::getGenero(){
    return genero;
} 

std::string video::getNombre(){
    return nombre;
}

int video::getId(){
    return ID;
}

int video::getDuracion(){
    return duracion;
}


std::string video::setNombre(){
    return nombre;
}

//Sobrecargar operador
int video::setCalificacion(){
    return calificacion;
}

void video::mostrarVideo(){
    cout<<"Mostrando video... \n";
    cout<<"ID: "<<getId()<<"\n";
    cout<<"Nombre: "<<getNombre()<<"\n";
    cout<<"Duracion: "<<getDuracion()<<"\n";
    cout<<"Genero: "<<getGenero()<<"\n";
    cout<<"Calificacion: "<<getCali()<<"\n";
}

void video::calificarVideo(std::string nombre, int calificacion){
    cout<<"Titulo a calificar: "<<nombre<<"\n";
    cout<<"Calificacion: "<<calificacion<<"\n";
}

int video::operator+(int nuevaCalif){
    calificacion=(calificacion+nuevaCalif)/2;
    return calificacion;
}
