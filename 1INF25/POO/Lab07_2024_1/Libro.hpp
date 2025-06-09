/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:14 AM
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP
#include "utils.hpp"
class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
//    void SetPeso(double peso);
//    double GetPeso() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* ) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
    
    void Leer(ifstream &);
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;
};

#endif /* LIBRO_HPP */

