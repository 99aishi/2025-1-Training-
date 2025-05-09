/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 8, 2025, 11:27 PM
 */
#include "BibGenerica.hpp"
#include "FunConEnteros.hpp"


/*
 * 
 */
int main(int argc, char** argv) {
    
    void *cola;
    creacola(cola,leenumero,prioridadnumero,"numeros.txt");
    imprimirnum(cola,"Reporte.txt");
//    descargarcola(cola,muestranumero,"Orden.txt");
    
//    creacola(cola,leepedido,prioridadpedido,"Pedidos.csv");
//    imprimirped(cola,"Reppedidos.csv");
//    descargarcola(cola,muestrapedido,"Orden.txt");    
    return 0;
}

