/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

#include "Biblioteca.hpp"


/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 3, 2025, 12:46 PM
 */


/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
//    cout << biblioteca.GetCantidad_libros()<<endl;
    biblioteca.cargar_estantes();
//    cout << biblioteca.GetCantidad_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    return 0;
}

