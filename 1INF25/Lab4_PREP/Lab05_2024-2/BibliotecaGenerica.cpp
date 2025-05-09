/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: 999
 * 
 * Created on May 8, 2025, 7:49 PM
 */

#include "BibliotecaGenerica.hpp"


void crealista(void* &lista,void*(*leenumeros)(ifstream &),const char *nom){
    ifstream input(nom,ios::in);
    if(!input) exit(1);
    void *prelista;
    construirlista(prelista);
    
    int i=0;
    while(true){
        void *dupla = leenumeros(input);
        if(input.eof()) break;
        insertafinal(dupla,prelista);        
        cout << i++<<endl;
    }
    
    lista=prelista;
}
void cargalista(void *lista,void(*cmp)(void*, void *),void*(*lee)(ifstream &),const char *nom){
    ifstream input(nom,ios::in);
    if(!input) exit(1);
    while(true){
        void *registro = lee(input);
        if(input.eof()) break;      
        cmp(registro,lista);
    }
    
}
void muestralista(void *lista,void (*imprime)(ofstream &,void*),const char *nom){
    ofstream repo(nom,ios::out);
    if(!repo) exit(1);    
    imprime(repo,lista);
}
void construirlista(void*&lista){
    void **arrlista= new void*[3]{};
    arrlista[INICIO]=nullptr;
    arrlista[FIN]=nullptr;
    int *can=new int;
    *can=0;
    arrlista[CANTIDAD]=can;
    lista=arrlista;
}
void insertafinal(void*dupla,void *lista){
    void **arr_lista=(void**)lista;
    void **nuevo_nodo=new void*[2];
    
    nuevo_nodo[DUPLA]=dupla;
    nuevo_nodo[PTR]=nullptr;
    if(esListaVacia(lista)){
       arr_lista[INICIO]=nuevo_nodo; 
       arr_lista[FIN]=nuevo_nodo;       
    }else{
        void **ultimo_nodo=(void**) arr_lista[FIN];
        arr_lista[FIN]=nuevo_nodo;        
        ultimo_nodo[PTR]=nuevo_nodo;       
    }
    int *cantidad= (int*)arr_lista[CANTIDAD];
    cantidad[0]++;
}

bool esListaVacia(void *lista){
    void **cabeza=(void**)lista;
    return cabeza[INICIO]==nullptr;
    
}