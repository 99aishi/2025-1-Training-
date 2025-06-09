/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:22 AM
 */

#ifndef ESPACIO_HPP
#define ESPACIO_HPP

#include "utils.hpp"
class Espacio {
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
private:
    char contenido;
    int posx;
    int posy;
};

#endif /* ESPACIO_HPP */

