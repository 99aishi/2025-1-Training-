/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Escala.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 1:15 AM
 */

#ifndef ESCALA_HPP
#define ESCALA_HPP

class Escala {
public:
    Escala();
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_HPP */

