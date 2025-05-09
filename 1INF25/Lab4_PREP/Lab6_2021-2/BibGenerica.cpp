/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibGenerica.cpp
 * Author: 999
 * 
 * Created on May 8, 2025, 11:31 PM
 */

#include "BibGenerica.hpp"

void creacola(void *&cola,void*(*leenumero)(ifstream &),void (*prioridadnumero)(void *, void*),const char*nom){
    ifstream input(nom,ios::in);
    if(!input) exit(1);
    
    construircola(cola);
    
    while(true){
        void* registro=leenumero(input);
        if(input.eof()) break;
        prioridadnumero(cola,registro);
    }
    
}
void construircola(void *&cola){
    void** arr_cola=new void*[5]{};
    cola = arr_cola;
}

void imprimirnum(void *cola,const char *nom){
    ofstream repo(nom,ios::out);
    if(!repo) exit(1);
    void **arr_cola=(void**)cola;
    void **recorrido=(void**)arr_cola[INICIO];    
    for (int i = 0; recorrido; i++) {
        void **dato=(void**)recorrido[DATO];
        int *ptr=(int*)dato[0];
        repo << *ptr<<endl;
        recorrido=(void**)recorrido[PTR];
    }
}
