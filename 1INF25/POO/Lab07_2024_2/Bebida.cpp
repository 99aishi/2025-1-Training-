/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bebida.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:17 AM
 */

#include "Bebida.hpp"

Bebida::Bebida() {
    tamano=nullptr;
}

Bebida::Bebida(const Bebida& orig) {
}

Bebida::~Bebida() {
}

void Bebida::SetTamano(const char* tamano) {
    if(this->tamano!= nullptr) delete this->tamano;
    this->tamano= new char[strlen(tamano)+1];
    strcpy(this->tamano,tamano);
}

void Bebida::GetTamano(char *tamano) const {
    if(this->tamano==nullptr) tamano[0]=0;
    strcpy(tamano,this->tamano);
}