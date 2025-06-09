/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:09 AM
 */

#include "Producto.hpp"

Producto::Producto() {
    nombre =nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(const char* nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Producto::GetNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    else (nombre,this->nombre);
}


void Producto::Leer(ifstream &input){
    char nom[30],c;
    input.getline(nom,30,',');
    SetNombre(nom);
    input >> precio >>c;
}
void operator >> (ifstream &input,Producto &p){
    p.Leer(input);
}

void Producto::operator = (Producto &otro){
    if(this != &otro){
        SetNombre(otro.nombre);
        this->precio= otro.precio;
    }

}

void Producto::mostrar(ofstream &output){
    char nom[30];
    GetNombre(nom);
    output<<setprecision(2)<<fixed;
    output<< left<< setw(15)<<" "<<setw(30)<<nombre<<setw(10)<< precio;
}