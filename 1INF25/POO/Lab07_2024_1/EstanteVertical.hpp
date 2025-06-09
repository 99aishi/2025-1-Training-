/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteVertical.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:26 AM
 */

#ifndef ESTANTEVERTICAL_HPP
#define ESTANTEVERTICAL_HPP

#include "Estante.hpp"
#include "Enciclopedia.hpp"


class EstanteVertical :public Estante{
public:
    EstanteVertical();
    EstanteVertical(const EstanteVertical& orig);
    virtual ~EstanteVertical();
    void SetCantidad_enciclopedias(int cantidad_enciclopedias);
    int GetCantidad_enciclopedias() const;
private:
    Enciclopedia enciclopedias[12];
    int cantidad_enciclopedias;
};

#endif /* ESTANTEVERTICAL_HPP */

