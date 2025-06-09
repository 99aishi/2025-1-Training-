/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Enciclopedia.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:18 AM
 */

#ifndef ENCICLOPEDIA_HPP
#define ENCICLOPEDIA_HPP

#include "Libro.hpp"


class Enciclopedia: public Libro {
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia& orig);
    virtual ~Enciclopedia();
    void SetVolumen(int volumen);
    int GetVolumen() const;
    void SetPeso(double peso);
    double GetPeso() const;
private:
    int volumen;
    double peso;
};

#endif /* ENCICLOPEDIA_HPP */

