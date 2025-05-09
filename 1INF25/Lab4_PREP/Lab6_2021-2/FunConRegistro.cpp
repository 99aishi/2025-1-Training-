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
    input.get(prio);
    input>>c;
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
int prioridadpedido(void *dato){
    void **registro=(void**)dato;
    char *tipo=(char*)registro[TIPO];
    if(*tipo=='A') return 3;
    if(*tipo=='E') return 2;
    if(*tipo=='D') return 1;
    
    
    
}
char *leer_cadena(ifstream &input,int size,char delim){
    char *cadena,buffer[size];
    input.getline(buffer,size,delim);
    if(input.eof()) return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}



void muestrapedido(void *reg,ofstream &repo){
    
    void **arr_registro=(void**)reg;
    char *tipo=(char *)arr_registro[TIPO];
    char *nombre=(char*)arr_registro[NOMBRE];
    char *libro=(char*)arr_registro[LIBRO];
    int *cod=(int*)arr_registro[CODIGO];
    
    repo <<left<<setw(5)<<*tipo<<setw(12) << *cod<<setw(60)<<nombre<<libro<<endl;
    
}