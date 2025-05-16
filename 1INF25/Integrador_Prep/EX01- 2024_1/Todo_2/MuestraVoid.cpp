/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   MuestraVoid.cpp
 * Author: 999
 * 
 * Created on May 16, 2025, 12:29 AM
 */

#include "MuestraVoid.hpp"
#include "AperturaDeArchivos.h"
void muestraventas(void*ventas){
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output,"MuestraVentas.txt");
    void **arr_ventas=(void**)ventas;
    for (int i = 0; arr_ventas[i]; i++) {
        imprime_ventas(arr_ventas[i],output);
    }
}
void imprime_ventas(void *venta,ofstream &output){
    void **registro=(void**)venta;
    char *titulo=(char*)registro[TITULO];
    char *codigo=(char*)registro[CODIGO];
    char *autor=(char*)registro[AUTOR];
    int *vendidos=(int*)registro[CANT];
    int *puntaje=(int*)registro[PUNTAJE];
    int *promedio=(int*)registro[PROMEDIO];
    int *ranking=(int*)registro[RANKING];
    output<<left<<"Codigo: "<<codigo<<endl;
    output<<"Titulo: "<<titulo<<endl;
    output<<"Autor: "<<autor<<endl;
    output<< "Estadisticas: "<<endl;
        for (int i = 0; i < 80; i++) {
        output <<"=";
    }
    output<<endl;
    output<<"Cant Vendidos: "<< setw(5)<<*vendidos << "Suma de puntajes: "<<*puntaje<<endl;
    output << "Promedio: "<<setw(5)<<*promedio<< "Ranking: "<<*ranking<<endl;
        for (int i = 0; i < 80; i++) {
        output <<"-";
    }
    output<<endl;
}