/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Presencial.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:09 AM
 */

#ifndef PRESENCIAL_HPP
#define PRESENCIAL_HPP

#include "Alumno.hpp"


class Presencial :public Alumno{
public:
    Presencial();
    Presencial(const Presencial& orig);
    virtual ~Presencial();
    void lee(ifstream &);
    void imprime(ofstream &);
    void modifica(double precio);
private:
    double total;
    double recargo;
};

#endif /* PRESENCIAL_HPP */

