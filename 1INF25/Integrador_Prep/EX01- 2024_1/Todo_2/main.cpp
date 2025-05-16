/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 16, 2025, 12:25 AM
 */
#include "PunteroVoid.hpp"
#include "MuestraVoid.hpp"
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
//    pruebaCargaVentas(ventasLibroCodigo,ventasDniFechaPuntaje,"PruebaVentas.txt");
    cargaLibros(libro,"Libros.csv");
//    pruebaLibros(libro,"PruebaLibros.txt");
    
    cargaventas(libro,ventas);
    actualizaventas(ventasDniFechaPuntaje,ventasLibroCodigo,ventas);
    muestraventas(ventas);
    
    return 0;
}

