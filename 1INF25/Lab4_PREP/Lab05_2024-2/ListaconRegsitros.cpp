/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaconRegsitros.cpp
 * Author: 999
 * 
 * Created on May 8, 2025, 9:27 PM
 */

#include "ListaconRegsitros.hpp"


void *leeregistros(ifstream&input){
    char *codigo;
    codigo=leer_cadena(input,8,',');
    if(input.eof() ) return nullptr;
    char* nombre,*vehiculo;
    nombre =leer_cadena(input,60,',');
    vehiculo =leer_cadena(input,15,'\n');
    void **dupla= new void*[2];
    void **info_repa=new void*[3];
    info_repa[CODIGO]=codigo;
    info_repa[NOMBRE]=nombre;
    info_repa[UNIDAD]=vehiculo;
    dupla[DATO]=info_repa;
    void **arr_pedidos=new void*[20]{};
    dupla[ARREGLO]=arr_pedidos;
    return dupla;
}
char *leer_cadena(ifstream &input,int size,char delim){
    char *cadena,buffer[size];
    input.getline(buffer,size,delim);
    if(input.eof()) return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
void* leeordenes(ifstream &input){
    
    int dni,cantidad;
    char c, *plato,*repa;
    input>>dni;
    if(input.eof()) return nullptr;
    input >>c>>cantidad>>c;
    plato=leer_cadena(input,7,',');    
    repa=leer_cadena(input,7,'\n');    
    void **registro=new void*[4];
    int *ptr_dni=new int,*ptr_cantidad=new int;
    ptr_cantidad[0]=cantidad;
    ptr_dni[0]=dni;
    registro[0]=ptr_dni;
    registro[1]=ptr_cantidad;
    registro[2]=plato;
    registro[3]=repa;
    return registro;
    
}
void imprimeregistros(ofstream &repo,void* lista){
    void **arr_lista=(void**)lista;    
    void**recorrido=(void**)arr_lista[INICIO];    
    for (int i = 0;recorrido; i++) {
        void ** dupla=(void**)recorrido[DUPLA];
        void** info_rep=(void**)dupla[0];
        char *cod= (char*)info_rep[CODIGO], *nombre=(char *)info_rep[NOMBRE];
        repo << left<<setw(10)<<cod << nombre << endl;        
        void ** arr_pedidos=(void**)dupla[1];        
        for (int i = 0;arr_pedidos[i]; i++) {
            void **pedidos=(void**)arr_pedidos[i];
            int *dni=(int*)pedidos[0];
            int *cantidad=(int*)pedidos[1];
            char *cod_plato=(char*)pedidos[2];
            repo<< setw(16)<<*dni<<setw(6)<<*cantidad<<cod_plato<<endl;
        }
        repo <<endl;
        recorrido=(void**)recorrido[PTR];        
    }
}
void compruebaregistro(void *registro, void *lista){
    void **arr_registro=(void**)registro;
    void **arr_lista=(void**)lista;
    char *rep_buscar= (char*)arr_registro[3];
    
    void**nodo_recorrido=(void**)arr_lista[INICIO];
    while(nodo_recorrido){
        void**dupla=(void**)nodo_recorrido[DUPLA];
        void**info_repa=(void**)dupla[DATO];
        char *codigo_rep= (char*)info_repa[CODIGO];
        if(strcmp(codigo_rep,rep_buscar)==0){
            void **arr_pedidos=(void**)dupla[ARREGLO];
            void *reg_pedido=devolver_registro_ingresar(registro);
            int i;
            for (i= 0;arr_pedidos[i]!=nullptr ; i++);
            arr_pedidos[i]=reg_pedido;
            break;
        }
        nodo_recorrido=(void**)nodo_recorrido[PTR];
    }
}
void *devolver_registro_ingresar(void* registro){
    void **arr_registro=(void**)registro;
    void**data=new void*[3];
    data[0]=arr_registro[0];
    data[1]=arr_registro[1];
    data[2]=arr_registro[2];
    return data;    
}