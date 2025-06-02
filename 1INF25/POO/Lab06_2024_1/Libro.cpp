/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: 999
 * 
 * Created on June 1, 2025, 4:25 PM
 */

#include "Libro.hpp"

Libro::Libro() {
    codigo= nullptr;
    nombre=nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

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

void Libro::SetNombre(const char* nombre) {
    if(nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre,this->nombre);
}


void Libro::SetCodigo(const char* codigo) {
    if(codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}
    
void Libro::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}

void Libro::leer(ifstream &input){
    char cod[8], nomb[60],c;
    input.getline(cod,8,',');
    input.getline(nomb,60,',');
    SetCodigo(cod);
    SetNombre(nomb);
    input >> ancho >> c >> alto;
    colocado=false;
    input.get();
}
void operator >> (ifstream &input, Libro &libro){
    libro.leer(input);
}
void Libro::mostrar(ofstream &output){
    output << left <<setw(5)<<codigo<<setw(30) << nombre<<setw(4) << ancho << alto<<endl;
}
void operator << (ofstream &output,Libro &libro){
    libro.mostrar(output);
}