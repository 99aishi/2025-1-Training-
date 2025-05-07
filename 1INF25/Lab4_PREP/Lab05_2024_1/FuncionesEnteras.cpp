/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   FuncionesEnteras.cpp
 * Author: 999
 * 
 * Created on May 6, 2025, 7:09 PM
 */

#include "FuncionesEnteras.hpp"

void* leenum(ifstream &arch) {
    int numero;
    arch>>numero;
    if (arch.eof()) return nullptr;
    int *a = new int;
    *a = numero;
    return a;
}

void imprimenum(ofstream &repo, void *elemento) {
    int *num = (int*) elemento;
    repo << *num << endl;
}
int cmpnum(void *elem1, void* elem2){
    int *num1=(int*)elem1;
    int *num2=(int*)elem2;
    return *num2-*num1;
}
