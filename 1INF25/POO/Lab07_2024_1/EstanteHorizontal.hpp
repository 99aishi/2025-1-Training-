/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   EstanteHorizontal.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:27 AM
 */

#ifndef ESTANTEHORIZONTAL_HPP
#define ESTANTEHORIZONTAL_HPP

#include "Estante.hpp"
#include "Novela.hpp"


class EstanteHorizontal:public Estante {
public:
    EstanteHorizontal();
    EstanteHorizontal(const EstanteHorizontal& orig);
    virtual ~EstanteHorizontal();
    void SetCantidad_novelas(int cantidad_novelas);
    int GetCantidad_novelas() const;
    int espacio_ocupado();
private:
    Novela novelas[12];
    int cantidad_novelas;
};

#endif /* ESTANTEHORIZONTAL_HPP */

