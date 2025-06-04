/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.hpp
 * Author: 999
 *
 * Created on June 3, 2025, 1:03 PM
 */

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Estante.hpp"


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
private:
    Estante estantes[5];
    int cantidad_estantes;
    Libro libros[15];
    int cantidad_libros;
};

#endif /* BIBLIOTECA_HPP */

