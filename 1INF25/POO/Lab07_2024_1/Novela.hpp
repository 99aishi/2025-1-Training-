/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Novelas.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:19 AM
 */

#ifndef NOVELAS_HPP
#define NOVELAS_HPP

#include "Libro.hpp"


class Novela: public Libro{
public:
    Novelas();
    Novelas(const Novela& orig);
    virtual ~Novela();
    void SetTipo(const char* tipo);
    void GetTipo(char*tipo) const;
    void SetPeso(double peso);
    double GetPeso() const;
private:
    char *tipo;
    double peso;
};

#endif /* NOVELAS_HPP */

