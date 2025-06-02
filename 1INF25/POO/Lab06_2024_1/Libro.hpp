/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.hpp
 * Author: 999
 *
 * Created on June 1, 2025, 4:25 PM
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
    void GetNombre(char *) const; // se voidea
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const; // se voidea
    
    void mostrar(ofstream &);
    void leer(ifstream &);
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
};


void operator >> (ifstream &input, Libro &libro);
void operator << (ofstream &output,Libro &libro);




#endif /* LIBRO_HPP */

