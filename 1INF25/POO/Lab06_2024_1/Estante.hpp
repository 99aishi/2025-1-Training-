/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.hpp
 * Author: 999
 *
 * Created on June 3, 2025, 12:59 PM
 */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include "Libro.hpp"
#include "Espacio.hpp"


class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    
    
    void Leer(ifstream &);
    bool operator += (Libro &libro);
    int calcular_ancho_ocupado();
    void colocar_libro(Libro &libro, int);
    
    void Mostrar(ofstream &);
    void imprime_linea(ofstream &out,int size,char car);
private:
    char *codigo;
    int anchura;
    int altura;
    Libro libros[10];
    int cantidad_libros;
    Espacio *espacios;
};
void operator >> (ifstream &in, Estante &e);
void operator << (ofstream &out,Estante &e);
#endif /* ESTANTE_HPP */

