/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 9, 2025, 1:13 AM
 */
#include "Biblioteca.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    return 0;
}

