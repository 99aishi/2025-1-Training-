/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 8, 2025, 7:48 PM
 */

#include "BibliotecaGenerica.hpp"
#include "Listaconenteros.hpp"
#include "ListaconRegsitros.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    
    void *lista, *repos;
    
    crealista(lista,leenumeros,"numeros1.txt");
    cargalista(lista, compruebanumero, leeregnumeros, "numeros2.txt");
    muestralista(lista,imprimenumeros,"repnum.txt");    
    
    crealista(repos,leeregistros,"repartidores.csv");
    cargalista(repos,compruebaregistro,leeordenes,"ordenes.csv");
    muestralista(repos,imprimeregistros,"repregistros.txt");
    return 0;
}

