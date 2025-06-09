/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PlatoFondo.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:20 AM
 */

#ifndef PLATOFONDO_HPP
#define PLATOFONDO_HPP

#include "Producto.hpp"


class PlatoFondo: public Producto{
public:
    PlatoFondo();
    PlatoFondo(const PlatoFondo& orig);
    virtual ~PlatoFondo();
    void insertar_proteina(int *protes);
    void imprimir_proteinas(ofstream &output);
private:
    int* proteina;
};

#endif /* PLATOFONDO_HPP */

