/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:09 AM
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include "utils.hpp"

class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void Leer(ifstream &);
    void operator = (Producto &otro);
    void mostrar(ofstream &);
private:
    char *nombre;
    double precio;
};
void operator >> (ifstream &input,Producto &p);

#endif /* PRODUCTO_HPP */

