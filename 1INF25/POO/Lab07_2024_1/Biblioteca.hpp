/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.hpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:28 AM
 */

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "EstanteVertical.hpp"
#include "EstanteHorizontal.hpp"


class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void SetCantidad_total_novelas(int cantidad_total_novelas);
    int GetCantidad_total_novelas() const;
    void SetCantidad_total_enciclopedias(int cantidad_total_enciclopedias);
    int GetCantidad_total_enciclopedias() const;
    void SetCantidad_estantes_horizontales(int cantidad_estantes_horizontales);
    int GetCantidad_estantes_horizontales() const;
    void SetCantidad_estantes_verticales(int cantidad_estantes_verticales);
    int GetCantidad_estantes_verticales() const;
    
    
    void cargar_libros();
    void leer_enciclopedia(ifstream &input);
    void leer_novela(ifstream &input);
    void cargar_estantes();
    void leer_esta_horizontal(ifstream &input);
    void leer_esta_vertical(ifstream &input);
private:
    EstanteVertical estantesVerticales[5];
    int cantidad_estantes_verticales;
    EstanteHorizontal estantesHorizontales[5];
    int cantidad_estantes_horizontales;
    Enciclopedia enciclopedias[20];
    int cantidad_total_enciclopedias;
    Novela novelas[20];
    int cantidad_total_novelas;
    
};

#endif /* BIBLIOTECA_HPP */

