/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: 999
 *
 * Created on June 3, 2025, 12:52 PM
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
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    
    void Leer(ifstream &);
    void Mostrar(ofstream &);
private:
    char*codigo;
    char*nombre;
    int ancho;
    int alto;
    bool colocado;
};

void operator >> (ifstream &in, Libro &libro);
void operator << (ofstream &out,Libro &libro);
#endif /* LIBRO_HPP */

