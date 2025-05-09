/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FunConEnteros.cpp
 * Author: 999
 * 
 * Created on May 8, 2025, 11:50 PM
 */

#include "FunConEnteros.hpp"

void* leenumero(ifstream &input){
    int numero;
    input >>numero;
    if(input.eof()) return nullptr;
    int *ptr_num=new int;
    *ptr_num=numero;
    
    void **registro=new void*;
    registro[0]=ptr_num;
    return registro;    
}
void prioridadnumero(void* cola,void* elemento){
    void **arr_cola=(void**)cola;
    void **nuevo_nodo=new void*[2];
    nuevo_nodo[DATO]=elemento;
    nuevo_nodo[PTR]=nullptr;
    void**reg=(void**)elemento;
    int *num=(int*)reg[0];
    if(esColaVacia(cola)){
        arr_cola[INICIO]=nuevo_nodo;
        arr_cola[FIN]=nuevo_nodo;
//        arr_cola[TERCERA]=nuevo_nodo;
//        arr_cola[SEGUNDA]=nuevo_nodo;
//        arr_cola[PRIMERA]=nuevo_nodo;
        if(*num<50)
            arr_cola[TERCERA]=nuevo_nodo;
        else if(*num>=50 and *num<=100)
            arr_cola[SEGUNDA]=nuevo_nodo;
        else if(*num>100)
            arr_cola[PRIMERA]=nuevo_nodo;
    }else{
        insertar_prioridad(cola,elemento);
    }

    
}
void insertar_prioridad(void* cola,void *elemento){
    void**arr_cola=(void**)cola;
    void **nuevo_nodo=new void*[2];
    nuevo_nodo[DATO]=elemento;
    nuevo_nodo[PTR]=nullptr;    
    void**reg=(void**)elemento;
    int *numero=(int*)reg[0];
    if(*numero<50){
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
    if(*numero>=50 and *numero<=100){
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
            nuevo_nodo[PTR]=(void**)ultimo_nodo[PTR];
            ultimo_nodo[PTR]=(void**)nuevo_nodo;
            arr_cola[SEGUNDA]=nuevo_nodo;
        }
       
    }
    if(*numero>100){
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
bool esColaVacia(void *cola){
    void** arr_cola=(void**)cola;
    return arr_cola[INICIO]==nullptr;
}