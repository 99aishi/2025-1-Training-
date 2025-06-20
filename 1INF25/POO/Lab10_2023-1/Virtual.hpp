/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Virtual.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:10 AM
 */

#ifndef VIRTUAL_HPP
#define VIRTUAL_HPP

#include "Alumno.hpp"


class Virtual :public Alumno{
public:
    Virtual();
    Virtual(const Virtual& orig);
    virtual ~Virtual();
    void SetLicencia(const char* nombre);
    void GetLicencia(char* nombre) const;
    void lee(ifstream &input);
    void imprime(ofstream &output);
    void modifica(double precio);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_HPP */

