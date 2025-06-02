/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: 999
 * 
 * Created on June 1, 2025, 4:39 PM
 */

#include "Estante.hpp"

Estante::Estante() {
    codigo=nullptr;
    cantidad_libros=0;
    espacios=nullptr;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* codigo) {
    if(codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Estante::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}

void Estante::leer(ifstream &input){
    char c, cod[5];
    input.getline(cod,5,',');
    SetCodigo(cod);
    input >> altura >> c >> anchura;
    input.get();
    this->espacios= new Espacio[anchura*altura]{};
}

void operator >> (ifstream &input, Estante &estante){
    estante.leer(input);
}


int Estante::get_espacios_restantes(){
    int ancho_utilizado=0;
    for (int i = 0; i < cantidad_libros; i++) {
        ancho_utilizado += libros[i].GetAncho();
    }
    return ancho_utilizado;
}
void Estante::colocar_libro(int ancho_utilizado,Libro &libro){
    for (int i = altura-1; i > (altura-libro.GetAlto()-1); i--) {
        for (int k = ancho_utilizado; k < ancho_utilizado+libro.GetAncho(); k++) {
            espacios[i*anchura+k].SetPosX(i);
            espacios[i*anchura+k].SetPosY(k);
            espacios[i*anchura+k].SetContenido('*');
        }
    }
    libro.SetColocado(true);
    libros[cantidad_libros]=libro;
    cantidad_libros++;
}
bool Estante::operator +=(Libro &libro){
    int alto_libro=libro.GetAlto();
    int ancho_libro= libro.GetAncho();
    int ancho_utilizado=get_espacios_restantes();
    
    if(alto_libro<=altura and ancho_libro <= (anchura-ancho_utilizado)){
        colocar_libro(ancho_utilizado,libro);
        return true;
    }else
        return false;
}
void Estante::imprime_linea(ofstream &output,int size, char car){
    for (int i=0;i<size;i++)
        output<<car;
    output<<endl;
}
void Estante::pinta_estante(ofstream &output){
    imprime_linea(output,50,'-');
    output<<endl;
    
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < anchura; j++) {
            output << espacios[i*anchura+j];
        }
        output<<endl;
    }
}
void Estante::mostrar(ofstream &output){
    imprime_linea(output, 50, '-');
    output << left<<"Codigo de Estante : " << setw(10) << codigo << "Cantidad de Libro: " << cantidad_libros << endl;
    output << left<< "Anchura del estante: " << setw(10) << anchura << "Altura del estante: " << altura << endl;
    pinta_estante(output);
    imprime_linea(output, 50, '.');
    for(int i=0;i<cantidad_libros;i++)
        output << libros[i];
}
void operator << (ofstream &output, Estante &estante){
    estante.mostrar(output);
}