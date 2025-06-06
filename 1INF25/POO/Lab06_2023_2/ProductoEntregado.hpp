/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProductoEntregado.hpp
 * Author: 999
 *
 * Created on June 5, 2025, 9:39 PM
 */

#ifndef PRODUCTOENTREGADO_HPP
#define PRODUCTOENTREGADO_HPP
#include "utils.hpp"
class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_HPP */

