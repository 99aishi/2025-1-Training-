/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 15, 2025, 8:18 PM
 */

#include "PunterosMultiples1Examen01Pregunta01.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    char **ventasLibroCodigo, ***libro;
    int **ventasDniFechaPuntaje;
    void *ventas;
    //PREGUNTA 1
    cargarVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"Ventas.csv");
    pruebaCargaVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"PruebaVentas.txt");
    cargaLibros(libro,"Libros.csv");
    pruebaLibros(libro,"PruebaLibros.txt");
    //PREGUNTA 2
    cargaventas(libro,ventas);
//    actualizaventas(ventasDniFechaPuntaje,ventasLibroCodigo,ventas);
    return 0;
}

