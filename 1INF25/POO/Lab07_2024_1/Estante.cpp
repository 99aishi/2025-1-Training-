/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:23 AM
 */

#include "Estante.hpp"

Estante::Estante() {
    espacios=nullptr;
    codigo=nullptr;
    pesoActual=0;
    pesoSoportado=0;
}

Estante::Estante(const Estante& orig) {
    delete codigo;
    delete espacios;
}

Estante::~Estante() {
}

void Estante::SetPesoActual(double pesoActual) {
    this->pesoActual = pesoActual;
}

double Estante::GetPesoActual() const {
    return pesoActual;
}

void Estante::SetPesoSoportado(double pesoSoportado) {
    this->pesoSoportado = pesoSoportado;
}

double Estante::GetPesoSoportado() const {
    return pesoSoportado;
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

    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);

}

void Estante::GetCodigo(char* codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    strcpy(codigo,this->codigo);
}

void Estante::Leer(ifstream &input){
    char c, cod[6];
    input.getline(cod,6,',');
    SetCodigo(cod);
    input >> anchura>>c>>altura;
    espacios= new Espacio[anchura*altura]{};
}

int  calcular_espacio_ocupado(){
            
}