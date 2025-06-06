/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: 999
 * 
 * Created on June 5, 2025, 9:52 PM
 */

#include "Pedido.hpp"

Pedido::Pedido() {
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* codigo){
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
    
}
void Pedido::GetCodigo(char *codigo) const{
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Pedido::Leer(ifstream &input){
    char cod[10];
    input.getline(cod,10,',');
    SetCodigo(cod);
    input>>dni_cliente;
    input.get();
}
bool operator >> (ifstream &input, Pedido &ped){
    if(input.eof()) return false;
    ped.Leer(input);
    return true;
}