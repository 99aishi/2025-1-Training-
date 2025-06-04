/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: 999
 * 
 * Created on June 3, 2025, 12:52 PM
 */

#include "Libro.hpp"

Libro::Libro() {
    nombre=nullptr;
    codigo=nullptr;
//    colocado=false;
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
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Libro::GetNombre(char *nombre) const {
    if(this->nombre==nullptr)nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Libro::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Libro::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr)codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Libro::Leer(ifstream &in){
    char cod[10],nom[40],c;
    in.getline(cod,10,',');
    in.getline(nom,40,',');
    in >> ancho>>c >>alto;
    in.get();
    SetNombre(nom);
    SetCodigo(cod);
    colocado=false;
}
void Libro::Mostrar(ofstream &out){
    char cod[10],nom[60];
    GetCodigo(cod);
    GetNombre(nom);
    if(colocado)
        out << left<< setw(10)<<cod<<setw(40)<<nom<<setw(4)<<ancho<<alto<<endl;
    else
        out << left<< setw(10)<<cod<<setw(40)<<"NO SE PUDO COLOCAR"<<setw(4)<<ancho<<alto<<endl;
}
void operator >> (ifstream &in, Libro &libro){
    libro.Leer(in);
}
void operator << (ofstream &out, Libro &libro){
    libro.Mostrar(out);
}