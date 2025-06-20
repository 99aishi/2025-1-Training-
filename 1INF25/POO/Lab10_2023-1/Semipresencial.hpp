/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Semipresencial.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:10 AM
 */

#ifndef SEMIPRESENCIAL_HPP
#define SEMIPRESENCIAL_HPP

#include "Alumno.hpp"


class Semipresencial :public Alumno{
public:
    Semipresencial();
    Semipresencial(const Semipresencial& orig);
    virtual ~Semipresencial();
    void lee(ifstream &);
    void imprime(ofstream &output);
    void modifica(double precio);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_HPP */

