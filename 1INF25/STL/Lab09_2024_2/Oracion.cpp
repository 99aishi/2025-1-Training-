/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Oracion.cpp
 * Author: 999
 * 
 * Created on June 26, 2025, 10:37 PM
 */

#include "Oracion.hpp"

Oracion::Oracion() {
    polaridad_total=0;
    cantidad_palabras=0;
}

Oracion::Oracion(const Oracion& orig) {
    *this=orig;
}
void Oracion::operator = (const Oracion &otro){
    this->palabras=otro.palabras;
    this->polaridad_total=otro.polaridad_total;
    this->cantidad_palabras=otro.cantidad_palabras;
}
Oracion::~Oracion() {
}
void Oracion::anadir_palabra(char *word, int pol){
    Palabra palabra;
    palabra.SetTexto(word);
    palabra.SetPolaridad(pol);
    palabras.push_back(palabra);
    this->cantidad_palabras++;
    this->polaridad_total+=pol;
}
bool Oracion::operator < (Oracion &otro){
    return this->polaridad_total > otro.polaridad_total;
}
void Oracion::imprimir(ofstream &output){
    
    for (int i = 0; i < cantidad_palabras; i++) {
        output << palabras[i];
    }
    output << endl;

//    for (Palabra elem : palabras) {
//        output << elem;
//    }
    
    output << endl;

}