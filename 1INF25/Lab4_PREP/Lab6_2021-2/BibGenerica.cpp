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

void creacola(void *&cola,void*(*leenumero)(ifstream &),int (*prioridadnumero)(void*),const char*nom){
    ifstream input(nom,ios::in);
    if(!input) exit(1);
    
    construircola(cola);    
    while(true){
        void* registro=leenumero(input);
        if(input.eof()) break;
        int prio = prioridadnumero(registro);
        encola(registro,cola,prio);
    }
    
}
void construircola(void *&cola){
    void** arr_cola=new void*[5]{};
    arr_cola[0]=nullptr;
    arr_cola[4]=nullptr;
    arr_cola[1]=nullptr;
    arr_cola[2]=nullptr;
    arr_cola[3]=nullptr;
    cout << arr_cola[1]<<endl;
    cola = arr_cola;
}
void encola(void *dato,void *cola,int prio){
    void**arr_cola=(void**)cola;
    void **nuevo_nodo=new void*[2];
    nuevo_nodo[DATO]=dato;
    nuevo_nodo[SIGUIENTE]=nullptr;
    if(esColaVacia(cola)){
        arr_cola[0]=nuevo_nodo;
        arr_cola[4]=nuevo_nodo;
        arr_cola[prio]=nuevo_nodo;
        cout << arr_cola[1]<<endl;
    }else{
        insertar_prioridad(arr_cola,nuevo_nodo,prio);
    }

}

void insertar_prioridad(void** arr_cola,void **nuevo_nodo, int prio){
    arr_cola[1];
    if(prio==3){
        if(arr_cola[3]==nullptr){
            void **ultimo_nodo=(void**)arr_cola[2];
            nuevo_nodo[SIGUIENTE]=nullptr;
            ultimo_nodo[SIGUIENTE]=nuevo_nodo;
            arr_cola[prio]=nuevo_nodo;
            arr_cola[4]=nuevo_nodo;
        }else{
            void **ultimo_nodo=(void**)arr_cola[4];
            nuevo_nodo[SIGUIENTE]=nullptr;
            ultimo_nodo[SIGUIENTE]=nuevo_nodo;
            arr_cola[prio]=nuevo_nodo;
            arr_cola[4]=nuevo_nodo;
        }
            
    }
    if(prio==2){
        if(arr_cola[prio]==nullptr){
            void **anterior;
            if(arr_cola[prio-1]!=nullptr){
                anterior=(void**)arr_cola[prio-1];
                nuevo_nodo[SIGUIENTE]=anterior[SIGUIENTE];
                anterior[SIGUIENTE]=nuevo_nodo;            
                arr_cola[prio]=nuevo_nodo;
            }else{
                anterior=(void**)arr_cola[0];
                nuevo_nodo[SIGUIENTE]=anterior;
                arr_cola[prio]=nuevo_nodo; 
                arr_cola[0]=nuevo_nodo;
            }               
            
        }else{
            void **ultimo_nodo=(void**)arr_cola[prio]; //0x917088
            nuevo_nodo[SIGUIENTE]=ultimo_nodo[SIGUIENTE];
            ultimo_nodo[SIGUIENTE]=nuevo_nodo;
            arr_cola[prio]=nuevo_nodo;//0x917520
        }
       
    }
    if(prio==1){
        if(arr_cola[prio]==nullptr){
            void**anterior=(void**)arr_cola[0];
            nuevo_nodo[SIGUIENTE]=anterior;
            arr_cola[0]=nuevo_nodo;
            arr_cola[prio]=nuevo_nodo;
        }else{
            void **ultimo_nodo=(void**)arr_cola[prio];
            nuevo_nodo[SIGUIENTE]=ultimo_nodo[SIGUIENTE];
            ultimo_nodo[SIGUIENTE]=nuevo_nodo;
            arr_cola[prio]=nuevo_nodo;
        }
       
    }
}
bool esColaVacia(void *cola){
    void** arr_cola=(void**)cola;
    return arr_cola[0]==nullptr;
}

void imprimirnum(void *cola,const char *nom){
    ofstream repo(nom,ios::out);
    if(!repo) exit(1);
    void **arr_cola=(void**)cola;
    void **recorrido=(void**)arr_cola[0];    
    for (int i = 0; recorrido; i++) {
        void **dato=(void**)recorrido[DATO];
        int *ptr=(int*)dato[0];
        repo << *ptr<<endl;
        recorrido=(void**)recorrido[SIGUIENTE];
    }
    void **p1=(void**)arr_cola[1];    
    void **dato=(void**)p1[DATO];
        int *ptr1=(int*)dato[0];
        repo << "PRIORIDAD 1 : "<<*ptr1<<endl;;
    void **p2=(void**)arr_cola[2]; 
    dato=(void**)p2[DATO];
        int *ptr2=(int*)dato[0];
        repo << "PRIORIDAD 2 : "<<*ptr2<<endl;;
    void **p3=(void**)arr_cola[3];
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
        if(arr_cola[0]==nullptr) break;
    }
    
    
}
void* desencolar(void *&cola){
    void **arr_cola=(void**)cola;
    void **nodo=(void**)arr_cola[0];
    void **reg=(void**)nodo[DATO];
    void **siguiente=(void**)nodo[SIGUIENTE];  
    arr_cola[0]=siguiente;
    void*aux=(void**)nodo[DATO];
      
    delete nodo;    
    return aux;
}
void imprimirped(void *cola,const char *nom){
    void **arr_cola=(void**)cola;
    void **recorrido=(void**)arr_cola[0];
    for (int i = 0;recorrido ; i++) {
        cout << i<<endl;
        recorrido=(void**)recorrido[SIGUIENTE];
    }

}