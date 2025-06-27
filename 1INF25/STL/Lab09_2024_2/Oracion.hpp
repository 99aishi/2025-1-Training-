/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Oracion.hpp
 * Author: 999
 *
 * Created on June 26, 2025, 10:37 PM
 */

#ifndef ORACION_HPP
#define ORACION_HPP

#include "Palabra.hpp"


class Oracion {
public:
    Oracion();
    Oracion(const Oracion& orig);
    virtual ~Oracion();
    void operator = (const Oracion &otro);
    void anadir_palabra(char *word, int);
    bool operator < (Oracion &otro);
    void imprimir(ofstream &output);
private:
    vector<Palabra> palabras;
    int polaridad_total;
    int cantidad_palabras;
};

#endif /* ORACION_HPP */

