/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.hpp
 * Author: 999
 *
 * Created on June 1, 2025, 4:39 PM
 */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP
#include "Espacio.hpp"
#include "Libro.hpp"


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
    void leer(ifstream &);
    void mostrar(ofstream &);
    int get_espacios_restantes();
    void imprime_linea(ofstream &output,int size, char car);
    void pinta_estante(ofstream &output);
    void colocar_libro(int ,Libro &);
    bool operator+=(Libro&);
private:
    char *codigo;
    int anchura;
    int altura;
    Libro libros[10];
    Espacio *espacios;
    int cantidad_libros;
};
void operator >> (ifstream &input, Estante &estante);
void operator << (ofstream &output, Estante &estante);
#endif /* ESTANTE_HPP */

