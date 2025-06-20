/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:18 AM
 */

#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "Nodo.hpp"
#include "Escala.hpp"


class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void crear(const char *nom);
    void mostrar_en_orden(const char *nom);
    void carga_escalas(const char *nom);
    void modificar();
   
private:
    Nodo *raiz;
    Escala lescala[10];
    void insertar_recursivo(Nodo *&raiz,Boleta &boleta);
    void mostrar_en_orden_recursivo(ofstream &, Nodo *&);
    void modificar_recursivo(Nodo *&raiz);
    void eliminar_recursivo(Nodo *&raiz);
};

#endif /* ARBOL_HPP */

