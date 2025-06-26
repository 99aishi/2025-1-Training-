/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NPedido.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:39 PM
 */

#include "NPedido.hpp"

NPedido::NPedido() {
}

NPedido::NPedido(const NPedido& orig) {
    *this = orig;
}

NPedido::~NPedido() {
}

void NPedido::operator = (const NPedido &otro){
    this->codigo=otro.codigo;
    this->cantidad=otro.cantidad;
    this->peso=otro.peso;
}
void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string NPedido::GetCodigo() const {
    return codigo;
}

void NPedido::leer(ifstream &input){
    char buffer[20],c;
    input.getline(buffer,20,',');
    SetCodigo(buffer);
    input >> cantidad>>c>>peso;
}
void NPedido::mostrar(ofstream &output){
    
    output << right << setw(15)<<GetCodigo() <<setw(5)<< GetCantidad() <<setw(10)<< GetPeso() <<endl;
 }
