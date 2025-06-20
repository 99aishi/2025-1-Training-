/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bebida.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:17 AM
 */

#ifndef BEBIDA_HPP
#define BEBIDA_HPP

#include "Producto.hpp"


class Bebida: public Producto {
public:
    Bebida();
    Bebida(const Bebida& orig);
    virtual ~Bebida();
    void SetTamano(const char* tamano);
    void GetTamano(char*) const;
    
    void Leer(ifstream &);
private:
    char *tamano;
};

#endif /* BEBIDA_HPP */

