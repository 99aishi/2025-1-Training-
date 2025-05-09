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
int prioridadnumero(void* elemento){
    void **reg=(void**)elemento;
    int *num=(int*)reg[0];
    if(*num<50) return 3;
    if(*num>50 and *num<=100) return 2;
    if(*num>100) return 1;
    
}


void muestranumero(void *reg, ofstream &repo){
    void**registro=(void**)reg;
    int *num=(int*)registro[0];
    
    repo <<right<<setw(4)<< *num <<endl;
}