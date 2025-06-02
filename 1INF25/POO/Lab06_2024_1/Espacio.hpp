/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.hpp
 * Author: 999
 *
 * Created on June 1, 2025, 4:37 PM
 */

#ifndef ESPACIO_HPP
#define ESPACIO_HPP
#include "utils.hpp"
class Espacio {
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosY(int posY);
    int GetPosY() const;
    void SetPosX(int posX);
    int GetPosX() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    void mostrar(ofstream &);
private:
    char contenido;
    int posX;
    int posY;
};

void operator << (ofstream &, Espacio &);


#endif /* ESPACIO_HPP */

