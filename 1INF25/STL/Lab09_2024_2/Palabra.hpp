/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Palabra.hpp
 * Author: 999
 *
 * Created on June 26, 2025, 10:36 PM
 */

#ifndef PALABRA_HPP
#define PALABRA_HPP

#include "utils.hpp"
class Palabra {
public:
    Palabra();
    Palabra(const Palabra& orig);
    virtual ~Palabra();
    void operator = (const Palabra &otro);
    void SetTexto(string texto);
    string GetTexto() const;
    void SetPolaridad(int polaridad);
    int GetPolaridad() const;
    void imprime(ofstream &output);
private:
    int polaridad;
    string texto;
    
};
void operator << (ofstream &output,Palabra pal);

#endif /* PALABRA_HPP */

