/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:18 AM
 */

#include "Arbol.hpp"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::crear(const char *nom) {
    ifstream input(nom, ios::in);
    char tipo, c;
    while (true) {
        class Boleta boleta;
        input >> tipo>>c;
        if (input.eof()) break;
        boleta.crear_memoria(tipo);
        boleta.leer(input);
        insertar_recursivo(raiz, boleta);
    }
}

void Arbol::insertar_recursivo(Nodo *&arbol, Boleta &dato) {
    if (arbol == nullptr) {
        arbol = new class Nodo;
        arbol->dboleta = dato;
        return;
    }
    if (arbol->dboleta > dato)
        insertar_recursivo(arbol->izq, dato);
    else
        insertar_recursivo(arbol->der, dato);
}

void Arbol::mostrar_en_orden(const char *nom) {
    ofstream output(nom, ios::out);

    mostrar_en_orden_recursivo(output, raiz);
}

void Arbol::mostrar_en_orden_recursivo(ofstream &output, Nodo *&arbol) {
    if (arbol) {
        mostrar_en_orden_recursivo(output, arbol->izq);
        output << arbol->dboleta;
        mostrar_en_orden_recursivo(output, arbol->der);
    }
}

void Arbol::carga_escalas(const char *nom) {
    ifstream input(nom, ios::in);
    int cod;
    double precio;
    char c;
    while (true) {
        input>>cod;
        if (input.eof()) break;
        input >> c >> precio;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(precio);
    }
}
void Arbol::modificar(){
    modificar_recursivo(raiz);
}
void Arbol::modificar_recursivo(Nodo *&arbol){
    if(arbol){
        modificar_recursivo(arbol->izq);
        modificar_recursivo(arbol->der);
        arbol->dboleta.actualiza(lescala);
    }
    
}