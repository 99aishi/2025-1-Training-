/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Palabra.cpp
 * Author: 999
 * 
 * Created on June 26, 2025, 10:36 PM
 */

#include "Palabra.hpp"

Palabra::Palabra() {
    polaridad=0;
}

Palabra::Palabra(const Palabra& orig) {
    *this=orig;
}

Palabra::~Palabra() {
}
void Palabra::operator = (const Palabra &otro){
    this->polaridad= otro.polaridad;
    this->texto=otro.texto;
}
void Palabra::SetTexto(string texto) {
    this->texto = texto;
}

string Palabra::GetTexto() const {
    return texto;
}

void Palabra::SetPolaridad(int polaridad) {
    this->polaridad = polaridad;
}

int Palabra::GetPolaridad() const {
    return polaridad;
}
void Palabra::imprime(ofstream &output){
    output<< this->texto<< " ";
}
void operator << (ofstream &output,Palabra pal){
    pal.imprime(output);
}