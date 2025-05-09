/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Listaconenteros.cpp
 * Author: 999
 * 
 * Created on May 8, 2025, 7:57 PM
 */

#include "Listaconenteros.hpp"


void *leenumeros(ifstream &input){    
    int num;
    input >> num;
    if(input.eof() ) return nullptr;
    int *ptr= new int;
    ptr[0]=num;    
    void **dupla=new void*[2];
    dupla[DATO]=ptr;
    int *arreglo= new int[20]{};
    dupla[ARREGLO]=arreglo;
    return dupla;
}
void *leeregnumeros(ifstream &input){
    void **registro= new void *[2];
    int clave,numero;
    input>>clave;
    if(input.eof()) return nullptr;
    input >>numero;
    int *ptr_clave = new int, *ptr_numero=new int;
    ptr_clave[0]=clave;
    ptr_numero[0]=numero;
    registro[DATO]=ptr_clave;
    registro[1]=ptr_numero;
    return registro;
}
void compruebanumero(void* registro, void *lista){
    void **arr_registro = (void**)registro;
    int *numero= (int*)arr_registro[0];
    void **arr_lista= (void ** )lista;
    void ** recorrido=(void **)arr_lista[INICIO];
    while(recorrido){
        void **dupla=(void **) recorrido[DUPLA];
        int *clave=(int *)dupla[DATO];
        int *arreglo=(int *)dupla[ARREGLO];
        if(*clave==*numero){
            int i=0;
            for (i= 0;arreglo[i]!=0; i++);
            int *agregalo=(int*)arr_registro[1];
            arreglo[i]=*agregalo;
            break;
        }
        recorrido=(void**)recorrido[PTR];
    }   
}
void imprimenumeros(ofstream &output,void *lista){
    void **arr_lista=(void**)lista;
    
    void **recorrido=(void **)arr_lista[INICIO];
    for (int i = 0; recorrido; i++) {
        void **data=(void**)recorrido[DUPLA];
        int *clave=(int*)data[0];
        output<< *clave<<endl;
        int *arreglo=(int *)data[1];
        for (int i = 0;arreglo[i]!=0; i++) {
            output << left<<setw(4)<<arreglo[i];
        }
        output<<endl;
        recorrido=(void**)recorrido[PTR];
    }

}