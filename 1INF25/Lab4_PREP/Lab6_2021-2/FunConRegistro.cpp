/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FunConRegistro.cpp
 * Author: 999
 * 
 * Created on May 9, 2025, 2:07 AM
 */

#include "FunConRegistro.hpp"
#include "FunConEnteros.hpp"
void* leepedido(ifstream &input){
    int codigo;
    input>>codigo;
    if(input.eof()) return nullptr;
    char prio,*nombre,*libro,c;
    input>>prio>>c;
    libro=leer_cadena(input,8,',');
    nombre=leer_cadena(input,100,'\n');
    int *ptr= new int;
    *ptr=codigo;
    char *tipo= new char;
    *tipo=prio;
    void **registro= new void*[4];
    registro[NOMBRE]=nombre;
    registro[CODIGO]=ptr;
    registro[TIPO]=tipo;
    registro[LIBRO]=libro;
    return registro;
    
}
char *leer_cadena(ifstream &input,int size,char delim){
    char *cadena,buffer[size];
    input.getline(buffer,size,delim);
    if(input.eof()) return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
void prioridadpedido(void *cola,void* registro){
    void **arr_cola=(void**)cola;
    void **nuevo_nodo=new void*[2];
    nuevo_nodo[DATO]=registro;
    nuevo_nodo[PTR]=nullptr;
    
    void **arr=(void**)registro;
    char *tipo=(char*)arr[TIPO];
    if(esColaVacia(cola)){
        arr_cola[INICIO]=nuevo_nodo;
        arr_cola[FIN]=nuevo_nodo;

        if(*tipo=='A')
            arr_cola[TERCERA]=nuevo_nodo;
        else if(*tipo=='E')
            arr_cola[SEGUNDA]=nuevo_nodo;
        else if(*tipo=='D')
            arr_cola[PRIMERA]=nuevo_nodo;
    }else{
        insertar_prioridad_libros(cola,registro);
    }
    
}
void insertar_prioridad_libros(void* cola,void *elemento){
    void**arr_cola=(void**)cola;
    void **nuevo_nodo=new void*[2];
    nuevo_nodo[DATO]=elemento;
    nuevo_nodo[PTR]=nullptr;    
    void**reg=(void**)elemento;
    char *tipo=(char*)reg[TIPO];
    if(*tipo=='A'){
        if(arr_cola[TERCERA]==nullptr){
            void **anterior=(void**)arr_cola[TERCERA];
            nuevo_nodo[PTR]=(void**)anterior[PTR];
            anterior[PTR]=(void**)nuevo_nodo;
            arr_cola[TERCERA]=nuevo_nodo;
        }else{
            void **ultimo_nodo=(void**)arr_cola[TERCERA];
            nuevo_nodo[PTR]=(void**)ultimo_nodo[PTR];
            ultimo_nodo[PTR]=(void**)nuevo_nodo;
            arr_cola[TERCERA]=nuevo_nodo; 
            arr_cola[FIN]=nuevo_nodo; 
        }
       
    }
    if(*tipo=='E'){
        if(arr_cola[SEGUNDA]==nullptr){
            void **anterior;
            if(arr_cola[PRIMERA]!=nullptr){
                anterior=(void**)arr_cola[PRIMERA];
                nuevo_nodo[PTR]=(void**)anterior[PTR];
                anterior[PTR]=(void**)nuevo_nodo;            
                arr_cola[SEGUNDA]=nuevo_nodo;
            }
            else{
                anterior=(void**)arr_cola[INICIO];
                nuevo_nodo[PTR]=(void**)anterior[PTR];
                anterior[PTR]=(void**)nuevo_nodo;            
                arr_cola[SEGUNDA]=nuevo_nodo;
                arr_cola[INICIO]=nuevo_nodo;
            }                
            
        }else{
            void **ultimo_nodo=(void**)arr_cola[SEGUNDA];
            if(ultimo_nodo[PTR]==nullptr){
                nuevo_nodo[PTR]=(void**)ultimo_nodo;
            }else{
                nuevo_nodo[PTR]=(void**)ultimo_nodo[PTR];
            }            
            ultimo_nodo[PTR]=(void**)nuevo_nodo;
            arr_cola[SEGUNDA]=nuevo_nodo;
        }
       
    }
    if(*tipo=='D'){
        if(arr_cola[PRIMERA]==nullptr){
            void**anterior=(void**)arr_cola[INICIO];
            nuevo_nodo[PTR]=(void**)anterior;
            arr_cola[INICIO]=nuevo_nodo;
            arr_cola[PRIMERA]=nuevo_nodo; //PRIMERA PTR APUNTA A NADA CUANDO DEBERIA APUNTAR AL VALOR PROXIMO
            
        }else{
            void **ultimo_nodo=(void**)arr_cola[PRIMERA];
            nuevo_nodo[PTR]=(void**)ultimo_nodo[PTR];
            ultimo_nodo[PTR]=(void**)nuevo_nodo;
            arr_cola[PRIMERA]=nuevo_nodo;
        }
       
    }
}


void muestrapedido(void *reg,ofstream &repo){
    
    void **arr_registro=(void**)reg;
    char *tipo=(char *)arr_registro[TIPO];
    char *nombre=(char*)arr_registro[NOMBRE];
    char *libro=(char*)arr_registro[LIBRO];
    int *cod=(int*)arr_registro[CODIGO];
    
    repo <<left<<setw(5)<<tipo<<setw(12) << *cod<<setw(60)<<nombre<<libro<<endl;
    
}