/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tesoreria.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:19 AM
 */

#ifndef TESORERIA_HPP
#define TESORERIA_HPP

#include "Arbol.hpp"


class Tesoreria {
public:
    Tesoreria();
    Tesoreria(const Tesoreria& orig);
    virtual ~Tesoreria();
    void cargaalumnos();
    void imprimeboleta();
    void actualizaboleta();
private:
    Arbol aboleta;
};

#endif /* TESORERIA_HPP */

