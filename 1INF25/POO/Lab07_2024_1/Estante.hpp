/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:23 AM
 */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include "Espacio.hpp"


class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetPesoActual(double pesoActual);
    double GetPesoActual() const;
    void SetPesoSoportado(double pesoSoportado);
    double GetPesoSoportado() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
    
    void Leer(ifstream &input);
    
private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacios;
    double pesoSoportado;
    double pesoActual;
    
};

#endif /* ESTANTE_HPP */

