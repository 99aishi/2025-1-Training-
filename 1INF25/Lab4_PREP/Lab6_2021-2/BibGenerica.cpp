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
    void **p1=(void**)arr_cola[PRIMERA];    
    void **dato=(void**)p1[DATO];
        int *ptr1=(int*)dato[0];
        repo << "PRIORIDAD 1 : "<<*ptr1<<endl;;
    void **p2=(void**)arr_cola[SEGUNDA]; 
    dato=(void**)p2[DATO];
        int *ptr2=(int*)dato[0];
        repo << "PRIORIDAD 2 : "<<*ptr2<<endl;;
    void **p3=(void**)arr_cola[TERCERA];
    dato=(void**)p3[DATO];
        int *ptr3=(int*)dato[0];
        repo << "PRIORIDAD 3 : "<<*ptr3<<endl;;
    
}


void descargarcola(void *&cola,void(*muestranumero)(void*,ofstream&),const char *nom){
    ofstream repo(nom,ios::out);
    int i=0;
    while(true){
        void* reg = desencolar(cola);
        repo << left<<setw(6)<<i+1;
        muestranumero(reg,repo);
        i++;
        void ** arr_cola=(void**)cola;
        if(arr_cola[INICIO]==nullptr) break;
    }
    
    
}
void* desencolar(void *&cola){
    void **arr_cola=(void**)cola;
    void **nodo=(void**)arr_cola[INICIO];
    void **reg=(void**)nodo[DATO];
    void **siguiente=(void**)nodo[PTR];  
    arr_cola[INICIO]=siguiente;
    void*aux=(void**)nodo[DATO];
      
    delete nodo;    
    return aux;
}