/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: 999
 * 
 * Created on June 3, 2025, 1:03 PM
 */

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes=0;
    cantidad_libros=0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros(){
    ifstream input("libros.csv",ios::in);
    while(true){
        Libro libro;
        input >> libro;
        if(input.eof()) break;
        libros[cantidad_libros]=libro;
        cantidad_libros++;
    }
}
void Biblioteca::cargar_estantes(){
    ifstream input("estantes.csv",ios::in);
    while(true){
        Estante estante;
        input >> estante;
        if(input.eof()) break;
        estantes[cantidad_estantes]=estante;
        cantidad_estantes++;
    }
}
void Biblioteca::posicionar_libros(){
    for (int i = 0; i < cantidad_libros; i++) {
        for (int k = 0; k < cantidad_estantes; k++) {
            if(estantes[k]+=libros[i]) 
                break;
        }
    }

}
void Biblioteca::mostrar_datos(){
    ofstream repo("Reporte.txt",ios::out);
    for (int i = 0; i < cantidad_estantes; i++) {
        repo << estantes[i];
    }

}