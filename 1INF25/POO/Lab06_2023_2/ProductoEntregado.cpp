/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: 999
 * 
 * Created on June 5, 2025, 9:39 PM
 */

#include "ProductoEntregado.hpp"

ProductoEntregado::ProductoEntregado() {
    codigo=nullptr;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
}

ProductoEntregado::~ProductoEntregado() {
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}

void ProductoEntregado::SetCodigo(const char* codigo){
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
    
}
void ProductoEntregado::GetCodigo(char *codigo) const{
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}

