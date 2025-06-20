/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:18 AM
 */

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {
}

Enciclopedia::Enciclopedia(const Enciclopedia& orig) {
}

Enciclopedia::~Enciclopedia() {
}

void Enciclopedia::SetVolumen(int volumen) {
    this->volumen = volumen;
}

int Enciclopedia::GetVolumen() const {
    return volumen;
}

void Enciclopedia::SetPeso(double peso) {
    this->peso = peso;
}

double Enciclopedia::GetPeso() const {
    return peso;
}
void Enciclopedia::Leer(ifstream &input){
    Libro::Leer(input);
    char c;
    int vol;
    double peso;
    input >>vol>>c>>peso;
    input.get();
}

