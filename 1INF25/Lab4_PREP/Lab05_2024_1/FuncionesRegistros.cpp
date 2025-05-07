/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesRegistros.cpp
 * Author: 999
 * 
 * Created on May 6, 2025, 9:16 PM
 */

#include "FuncionesRegistros.hpp"


void *leeregistro(ifstream &input){
    //2,14268463,BHD6079
    //7,42302422,RWW7975
    int num,dni;
    char *codigo,c;
    input>>num;
    if(input.eof()) return nullptr;
    input>>c>>dni>>c;
    codigo=lee_cadena(input);
    int *pt_dni= new int,*pt_numped=new int;
    *pt_dni=dni;
    *pt_numped=num;
    void **registro = new void*[3];
    registro[0]=pt_numped;
    registro[1]=pt_dni;
    registro[2]=codigo;
    return registro;
}
void imprimeregistro(ofstream &repo, void *elemento){
    void **data=(void**)elemento;
    int *numped=(int*)data[0],*dni=(int*)data[1];
    char *codigo=(char*)data[2];
    repo <<left<< setw(10)<<*numped<<setw(10) << *dni << codigo<< endl;
}
char *lee_cadena(ifstream &input){
    char buffer[10],*cadena;
    input.getline(buffer,10);
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
    
}
int cmpregistro(void* elemento1,  void* elemento2){
    void **data=(void**)elemento1;
    void **data2=(void**)elemento2;
    int *num1 = (int*)data[0], *dni1=(int*)data[1];
    int *num2 = (int*)data2[0], *dni2=(int*)data2[1];
    char *cod1=(char*)data[2],*cod2=(char*)data2[2];
    
    if(*num1==*num2 and *dni1==*dni2){
        return strcmp(cod1,cod2);
    }
    if(*num1==*num2)
        return *dni2-*dni1;
    return *num2-*num1;
    
}