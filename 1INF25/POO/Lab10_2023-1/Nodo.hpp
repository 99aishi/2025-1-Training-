/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:16 AM
 */

#ifndef NODO_HPP
#define NODO_HPP

#include "Boleta.hpp"


class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Arbol;
private:
    Boleta dboleta;
    Nodo *izq;
    Nodo *der;
};

#endif /* NODO_HPP */

