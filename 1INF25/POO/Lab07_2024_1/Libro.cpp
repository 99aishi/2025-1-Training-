/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:14 AM
 */

#include "Libro.hpp"

Libro::Libro() {
    nombre=nullptr;
    codigo=nullptr;
    colocado=false;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    delete this->nombre;
     delete this->codigo;
}
//void Libro::operator =(const Libro &otro){
//    
//}
void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

//void Libro::SetPeso(double peso) {
//    this->peso = peso;
//}
//
//double Libro::GetPeso() const {
//    return peso;
//}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char*nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    strcpy(nombre,this->nombre);
}

void Libro::SetCodigo(const char* codigo) {

    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);

}

void Libro::GetCodigo(char* codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    strcpy(codigo,this->codigo);
}

void Libro::Leer(ifstream &input){
    char cod[8],nom[40],c;
    
    input.getline(cod,8,',');
    input.getline(nom,40,',');
    SetNombre(nom);
    SetCodigo(cod);
    input >> ancho>>c>>alto>>c;
    
}