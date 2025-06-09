/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Entrada.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:19 AM
 */

#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include "Producto.hpp"


class Entrada : public Producto{
public:
    Entrada();
    Entrada(const Entrada& orig);
    virtual ~Entrada();
    void SetPicante(bool picante);
    bool IsPicante() const;
private:
    bool picante;
};

#endif /* ENTRADA_HPP */

