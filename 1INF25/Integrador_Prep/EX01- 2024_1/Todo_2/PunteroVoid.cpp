/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunteroVoid.cpp
 * Author: 999
 * 
 * Created on May 16, 2025, 12:29 AM
 */

#include "PunteroVoid.hpp"
#include "utils.hpp"
void cargaventas(char ***libro,void *&ventas){
    void **arreglo_ventas;
    int cant_libros;
    for ( cant_libros= 0; libro[cant_libros]; cant_libros++);     
    arreglo_ventas=new void*[cant_libros]{};    
    for ( cant_libros= 0; libro[cant_libros]; cant_libros++){
        void **registro;
        char** aux= libro[cant_libros];
        registro= new void*[7]{};
        registro[CODIGO]=aux[0];
        registro[TITULO]=aux[1];
        registro[AUTOR]=aux[2];
        registro[PUNTAJE]=nullptr;
        registro[PROMEDIO]=nullptr;
        registro[CANT]=nullptr;
        registro[RANKING]=nullptr;
        arreglo_ventas[cant_libros]=registro;
    }
    ventas=arreglo_ventas;
}
void actualizaventas(int **ventasDniFechaPuntaje,char **ventasLibroCodigo,void *ventas){
    void **arr_ventas=(void**)ventas;
    for (int i = 0;arr_ventas[i]; i++) {
        void**registro=(void**)arr_ventas[i];
        char *codLibro=(char*)registro[CODIGO];
        int *vendidos=new int,*suma=new int,*promedio=new int,*ranking=new int;
        int cant=0,prom=0,sum=0;
        for (int k = 0; ventasDniFechaPuntaje[k]; k++) {
            int *aux=ventasDniFechaPuntaje[k];
            if(strcmp(codLibro,ventasLibroCodigo[k])==0){ 
                cant++;
                sum += aux[2];
                prom=sum/cant;                
            }
        }
        if(prom<30) *ranking=1;
        else if(prom>=30 and prom <70) *ranking=2;
        else *ranking=3;        
        *suma=sum;
        *vendidos=cant;
        *promedio=prom;
        registro[PUNTAJE]=suma;
        registro[PROMEDIO]=promedio;
        registro[RANKING]=ranking;
        registro[CANT]=vendidos;
    }
}