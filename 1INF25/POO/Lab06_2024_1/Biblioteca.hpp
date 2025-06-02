/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.hpp
 * Author: 999
 *
 * Created on June 1, 2025, 4:44 PM
 */

#ifndef BIBLIOTECA_HPP
#include "Estante.hpp"
#include "Libro.hpp"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    
    
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    void imprime_linea(ofstream& output, int n, char c);
private:
    Estante estantes[10];
    int cantidad_estantes;
    Libro libros[10];
    int cantidad_libros;
};

#endif /* BIBLIOTECA_HPP */

