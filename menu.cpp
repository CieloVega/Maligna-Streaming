#include "menu.hpp"
#include "video.hpp"
#include "peliculas.hpp"
#include "episodio.hpp"
#include "series.hpp"
#include "consola.hpp"
#include "ExceptionInvalidOption.hpp"

#include <sstream>
#include <fstream>

int menu::menuPrincipal(){
    peliculas_vector.clear();
    series_vector.clear();
    cargaArchivo("videos.txt");
    int opcion;
    cout<<"Bienvenidx a Maligna Streaming, ¿qué deseas hacer hoy?"<<endl;
    cout<<"1. Cargar archivo de datos"<<endl;
    cout<<"2. Ver catalogo"<<endl;
    cout<<"3. Series"<<endl;
    cout<<"4. Peliculas"<<endl;
    cout<<"5. Calificar un titulo"<<endl;
    cout<<"6. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    
    if (opcion==1){
        menu::cargaArchivo("videos.txt");
        cout<<"Archivo cargado con exito"<<endl;
        peliculas_vector.clear();
        series_vector.clear();
        c.pausa();
        c.cls();
    }else if(opcion==2){
        menu::verCatalogo();
        c.pausa();
        c.cls();
    }
    else if(opcion==3){
        menu::menuSeries();
        c.pausa();
        c.cls();
    }
    else if(opcion==4){
        menu::menuPeliculas();
        c.pausa();
        c.cls();
    }
    else if(opcion==5){
        menu::calificarTitulo();
        c.pausa();
        c.cls();
    }
    else if(opcion==6){
        cout<<"Gracias por usar Maligna Streaming"<<endl;
        cout<<"Cerrando programa..."<<endl;
        peliculas_vector.clear();
        series_vector.clear();
        exit(0);
    }    
    else{
        throw ExceptionInvalidOption("Opcion invalida");
    }
    peliculas_vector.clear();
    series_vector.clear();
}

void menu::cargaArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo, id, nombre, duracion, genero, cali, temporada, idCap, nombreEp, califEp;

        getline(ss, tipo, ',');
        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, duracion, ',');
        getline(ss, genero, ',');
        getline(ss, cali, ',');

        if (tipo == "p") {
            peliculas p(stoi(id), nombre, stoi(duracion), genero, stoi(cali));
            peliculas_vector.push_back(p);
        } else if (tipo == "s") {
            series s(stoi(id), nombre, stoi(duracion), genero, stoi(cali));
            series_vector.push_back(s);
        } else if (tipo == "c") {
            episodio e(stoi(id), stoi(nombre), duracion, stoi(genero),stoi(cali));
            episodio_vector.push_back(e);
            for(int i = 0; i < series_vector.size(); i++){
                series_vector[i].getId();
                for(int j = 0; j < 3; j++){
                    episodio_vector[j].getIdSerie();
                    if(series_vector[i].getId()==episodio_vector[j].getIdSerie()){
                        series_vector[i].agregarEpisodio(episodio_vector[j]);
                    } 
                }
                    
            }
        }
    }

    archivo.close();
}

int menu::verCatalogo(){
    c.cls();
    int opcion;
    cout<<"Catalogo"<<endl;
    cout<<"1. Por calificacion"<<endl;
    cout<<"2. Por genero"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    if(opcion==1){
        menu::CatalogoCalif();
    }
    else if(opcion==2){
        menu::CatalogoGenero();
    }
    return opcion;
}

void menu::calificarTitulo(){
    c.cls();
    cout<<"Desea calificar una pelicula o serie: (p/s)\n";
    std::string op;
    cin>>op;
    cout<<"Ingrese el nombre del titulo que desea calificar: ";
    string titulo;
    cin>>titulo;
    cout<<"Ingrese la calificacion que desea darle: ";
    int calif;
    cin>>calif;
    bool tituloEncontrado = false;
    int newCal;
    if (op=="p"){
        for(size_t i =0; i<peliculas_vector.size();i++){           
            if (peliculas_vector[i].getNombre()==titulo){
                tituloEncontrado = true;
                newCal=peliculas_vector[i]+(calif);
                break;
            }
        }
    }
    else if(op=="s"){
        for(size_t i =0; i<series_vector.size();i++){
            if (series_vector[i].getNombre()==titulo){
                tituloEncontrado = true;
                newCal=series_vector[i]+(calif);
                break;
            }
        }
    }
    if (!tituloEncontrado){
        throw("Titulo de video no encontrado");
    }
    cout<<"Titulo calificado con exito, la nueva calificacion es de: "<<newCal<<endl;
}

void menu::menuSeries(){
    c.cls();
    int opcion;
    cout<<"Series"<<endl;
    for (int i=0; i<3; i++){
        cout<<i+1<<". "<<series_vector[i].getNombre()<<endl;
    }
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    while (opcion<1 || opcion>3){
        cout<<"Opcion invalida, ingrese una opcion valida: ";
        cin>>opcion;
    }
    epCalif();
}

void menu::menuPeliculas(){
    c.cls();
    int opcion;
    cout<<"Peliculas por calificacion"<<endl;
    cout<<"1. Peliculas 3 estrellas"<<endl;
    cout<<"2. Peliculas 4 estrellas"<<endl;
    cout<<"3. Peliculas 5 estrellas"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    if (opcion == 1){
        cout<<"Peliculas 3 estrellas"<<endl;
        for (int i=0; i<9; i++){
            if (peliculas_vector[i].getCali()==3){
                peliculas_vector[i].mostrarVideo();
            }
        }
    }else if(opcion==2){
        cout<<"Peliculas 4 estrellas"<<endl;
        for (int i=0; i<9; i++){
            if (peliculas_vector[i].getCali()==4){
                peliculas_vector[i].mostrarVideo();
            }
        }
    }else if(opcion==3){
        cout<<"Peliculas 5 estrellas"<<endl;
        for (int i=0; i<9; i++){
            if (peliculas_vector[i].getCali()==5){
                peliculas_vector[i].mostrarVideo();
            }
        }
    }
}

void menu::CatalogoCalif(){
    int opcion;
    cout<<"Catalogo por calificacion"<<endl;
    cout<<"1. Catalogo 3 estrellas"<<endl;
    cout<<"2. Catalogo 4 estrellas"<<endl;
    cout<<"3. Catalogo 5 estrellas"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;
    if (opcion==1){
        cout<<"Catalogo 3 estrellas"<<endl;
        for (int i=0; i<peliculas_vector.size(); i++){
            if (peliculas_vector[i].getCali()==3){
                peliculas_vector[i].mostrarVideo();
            }
        }
        for (int i=0; i<series_vector.size(); i++){
            if (series_vector[i].getCali()==3){
                series_vector[i].mostrarVideo();
            }
        }

    }else if(opcion==2){
        cout<<"Catalogo 4 estrellas"<<endl;
        for (int i=0; i<peliculas_vector.size(); i++){
            if (peliculas_vector[i].getCali()==4){
                peliculas_vector[i].mostrarVideo();
            }
        }
        for (int i=0; i<series_vector.size(); i++){
            if (series_vector[i].getCali()==4){
                series_vector[i].mostrarVideo();
            }
        }
    }else if(opcion==3){
        cout<<"Catalogo 5 estrellas"<<endl;
        for (int i=0; i<peliculas_vector.size(); i++){
            if (peliculas_vector[i].getCali()==5){
                peliculas_vector[i].mostrarVideo();
            }
        }
        for (int i=0; i<series_vector.size(); i++){
            if (series_vector[i].getCali()==5){
                series_vector[i].mostrarVideo();
            }
        }
    }
}

void menu::CatalogoGenero(){
    int opcion;
    cout<<"Catalogo por genero"<<endl;
    cout<<"1. Terror"<<endl;
    cout<<"2. Comedia"<<endl;
    cout<<"3. Drama"<<endl;
    cout<<"4. Accion"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;

    string genero;
    if (opcion==1){
        genero = "Terror";
    }else if(opcion==2){
        genero = "Comedia";
    }else if(opcion==3){
        genero = "Drama";
    }else if(opcion==4){
        genero = "Accion";
    }

    cout<<"Catalogo de "<<genero<<endl;
    for (int i=0; i<peliculas_vector.size(); i++){
        if (peliculas_vector[i].getGenero()==genero){
            peliculas_vector[i].mostrarVideo();
        }
    }
    for (int i=0; i<series_vector.size(); i++){
        if (series_vector[i].getGenero()==genero){
            series_vector[i].mostrarVideo();
        }
    }
    
}

void menu::epCalif(){
    int opcion;
    cout<<"1. Episodios de 3 estrellas"<<endl;
    cout<<"2. Episodios de 4 estrellas"<<endl;
    cout<<"3. Episodios de 5 estrellas"<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>opcion;

    if (opcion==1){
        cout<<"Episodios de 3 estrellas"<<endl;
        
        for (int i=0; i<series_vector.size(); i++){
            int j=0;
            if(j>episodio_vector.size()){
                j=0;
            }
            if (episodio_vector[j].getCalifEpisodio()==3 && series_vector[i].getId()==episodio_vector[j].getIdSerie()){
                episodio_vector[j].mostrarEpisodio();
            }
            j++;
        }
    }else if(opcion==2){
        cout<<"Episodios de 4 estrellas"<<endl;
        
        for (int i=0; i<series_vector.size(); i++){
            int j=0;
            if(j>episodio_vector.size()){
                j=0;
            }
            if (episodio_vector[j].getCalifEpisodio()==4 && series_vector[i].getId()==episodio_vector[j].getIdSerie()){
                episodio_vector[j].mostrarEpisodio();
            }
            j++;
        }
    }else if(opcion==3){
        cout<<"Episodios de 5 estrellas"<<endl;
        
        for (int i=0; i<series_vector.size(); i++){
            int j=0;
            if(j>episodio_vector.size()){
                j=0;
            }
            if (episodio_vector[j].getCalifEpisodio()==5 && series_vector[i].getId()==episodio_vector[j].getIdSerie()){
                episodio_vector[j].mostrarEpisodio();
            }
            j++;
        }
    }
}