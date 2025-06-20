/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:28 AM
 */

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes_horizontales = 0;
    cantidad_estantes_verticales = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_novelas = 0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_total_novelas(int cantidad_total_novelas) {
    this->cantidad_total_novelas = cantidad_total_novelas;
}

int Biblioteca::GetCantidad_total_novelas() const {
    return cantidad_total_novelas;
}

void Biblioteca::SetCantidad_total_enciclopedias(int cantidad_total_enciclopedias) {
    this->cantidad_total_enciclopedias = cantidad_total_enciclopedias;
}

int Biblioteca::GetCantidad_total_enciclopedias() const {
    return cantidad_total_enciclopedias;
}

void Biblioteca::SetCantidad_estantes_horizontales(int cantidad_estantes_horizontales) {
    this->cantidad_estantes_horizontales = cantidad_estantes_horizontales;
}

int Biblioteca::GetCantidad_estantes_horizontales() const {
    return cantidad_estantes_horizontales;
}

void Biblioteca::SetCantidad_estantes_verticales(int cantidad_estantes_verticales) {
    this->cantidad_estantes_verticales = cantidad_estantes_verticales;
}

int Biblioteca::GetCantidad_estantes_verticales() const {
    return cantidad_estantes_verticales;
}

void Biblioteca::leer_enciclopedia(ifstream &input) {
    enciclopedias[cantidad_total_enciclopedias].Leer(input);
    cantidad_total_enciclopedias++;
}

void Biblioteca::leer_novela(ifstream &input) {

    novelas[cantidad_total_novelas].Leer(input);
    char tipo[20];
    input.getline(tipo, 20, ',');
    novelas[cantidad_total_novelas].SetTipo(tipo);
    double peso;
    input>>peso;
    input.get();
    novelas[cantidad_total_novelas].SetPeso(peso);
    cantidad_total_novelas++;
}

void Biblioteca::cargar_libros() {
    ifstream csv("libros2.csv", ios::in);
    char tipo, c;
    while (true) {
        csv >> tipo>>c;
        if (csv.eof()) break;
        if (tipo == 'E')
            leer_enciclopedia(csv);
        if (tipo == 'N')
            leer_novela(csv);
    }
}

void Biblioteca::leer_esta_horizontal(ifstream &input) {
    estantesHorizontales[cantidad_estantes_horizontales].Leer(input);
    cantidad_estantes_horizontales++;
}

void Biblioteca::leer_esta_vertical(ifstream &input) {
    estantesVerticales[cantidad_estantes_verticales].Leer(input);
    cantidad_estantes_verticales++;
}

void Biblioteca::cargar_estantes() {
    ifstream csv("estantes2.csv", ios::in);
    char tipo, c;
    while (true) {
        csv >> tipo>>c;
        if (csv.eof()) break;
        if (tipo == 'H')
            leer_esta_horizontal(csv);
        if (tipo == 'V')
            leer_esta_vertical(csv);
    }
}

void Biblioteca::posicionar_libros() {
    //    posicionar_estante_horizontal();

    //    for(int i=0; i<cantidad_total_novelas;i++){
    //        for (int k = 0; k < cantidad_estantes_horizontales; k++) {
    //            
    //        }   
    //    }



}