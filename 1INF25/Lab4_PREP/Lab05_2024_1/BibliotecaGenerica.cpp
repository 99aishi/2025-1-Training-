/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   BibliotecaGenerica.cpp
 * Author: 999
 * 
 * Created on May 6, 2025, 7:06 PM
 */

#include "BibliotecaGenerica.hpp"
#include "FuncionesEnteras.hpp"
void crealista(void *&pedidos1,void *(leenum)(ifstream &),const char *nom){
    ifstream input(nom,ios::in);
    if(!input){
        exit(1);
    }
    void *lista;
    construirlista(lista);
    
    while(true){
        void *elemento= leenum(input);
        if(input.eof()) break;
        insertarlista(lista,elemento);
    }
    pedidos1=lista;
}
void construirlista(void *&lista){
    
    void **arr_lista=new void*[2];
    arr_lista[0]=nullptr;
    arr_lista[1]=nullptr;
    lista = arr_lista;
}
void insertarlista(void *lista,void * elemento){
    void **cabeza= (void**)lista;
    void **nuevoNodo= new void*[2];
    nuevoNodo[0]=elemento;
    nuevoNodo[1]=nullptr;
    
    if(listavacia(lista)){
        cabeza[0]=nuevoNodo;
        cabeza[1]=nuevoNodo;
    }else{
        void **ultimoNodo=(void**)cabeza[1];
        cabeza[1]=nuevoNodo;
        ultimoNodo[1]=nuevoNodo;
    }
}

bool listavacia(void *lista){
    void **nodo= (void**)lista;
    return nodo[0]==nullptr;
}

void imprimelista(void *pedidos1,void(*imprimenum)(ofstream &, void *),const char *nomb){
    
    ofstream repo(nomb,ios::out);
    void ** cabeza=(void**)pedidos1;
    void ** recorrido=(void**)cabeza[0];
    
    for (int i = 0;recorrido; i++) {
        imprimenum(repo,recorrido[0]);
        recorrido=(void**)recorrido[1];
    }
}
void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,int (*cmpnum)(void* ,void*)){
    construirlista(pedidosfinal);

    
    while(!listavacia(pedidos1) and !listavacia(pedidos2)){
        void *elemento1=ver_elemento(pedidos1);
        void* elemento2=ver_elemento(pedidos2);
        int valcmp=cmpnum(elemento1,elemento2);
        if(valcmp<0){
            void *ingresar=quitalista(pedidos2);
            insertarlista(pedidosfinal,ingresar);
        }
        if(valcmp==0){
            void *ingresar1=quitalista(pedidos1);
            void *ingresar2=quitalista(pedidos2);
            insertarlista(pedidosfinal,ingresar1);
        }
        if(valcmp>0){
            void *ingresar=quitalista(pedidos1);
            insertarlista(pedidosfinal,ingresar);
        }
    }
    ingresarlistanovacia(pedidos1,pedidos2,pedidosfinal);
}
void *ver_elemento(void *pedidos1){
    void **cabeza=(void**)pedidos1;
    void **nodo=(void**)cabeza[0];
    void *elemento=nullptr;
    if(!listavacia(pedidos1))
        elemento=nodo[0];
    return elemento;
}
void *quitalista(void *pedidos){    
    void** cabeza=(void**)pedidos;
    void **nodo=(void**) cabeza[0];
    void *elemento=nullptr;
    if(!listavacia(pedidos)){
        if(cabeza[0]==cabeza[1]){
            cabeza[0]=nullptr;
            cabeza[1]=nullptr;
        }else{
            cabeza[0]=nodo[1];
            nodo[1]= nullptr;
        }
        elemento=nodo[0];
        delete nodo;
    }
    return elemento;
}
void ingresarlistanovacia(void *pedidos1,void *pedidos2,void *&pedidosfinal){
    
    
    while(!listavacia(pedidos1)){
        void *ingresar=quitalista(pedidos1);
        insertarlista(pedidosfinal,ingresar);
    }
    while(!listavacia(pedidos2)){
        void *ingresar=quitalista(pedidos2);
        insertarlista(pedidosfinal,ingresar);
    }
    
    
}