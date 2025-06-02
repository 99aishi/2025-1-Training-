/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: 999
 * 
 * Created on June 2, 2025, 11:09 AM
 */

#include "Cliente.hpp"

Cliente::Cliente() {
    nombre = nullptr;
    distrito = nullptr;
    totalPagado = 0;
}

Cliente::Cliente(const Cliente& orig) {

    nombre = new char[strlen(orig.nombre) + 1];
    strcpy(nombre, orig.nombre);
    distrito = new char[strlen(orig.distrito) + 1];
    strcpy(distrito, orig.distrito);
    descuento = orig.descuento;
    dni = orig.dni;
    totalPagado = orig.totalPagado;

}

void Cliente::operator=(const Cliente &orig) {
    if (this != &orig) {
        delete[] nombre;
        delete[] distrito;
        
//        this=orig;
//        this->orig;
        nombre=new char[strlen(orig.nombre)+1];
        strcpy(nombre,orig.nombre);
        distrito=new char[strlen(orig.distrito)+1];
        strcpy(distrito,orig.distrito);
        descuento=orig.descuento;
        dni=orig.dni;
        totalPagado=orig.totalPagado;
    }
}

Cliente::~Cliente() {

}

void Cliente::SetTotalPagado(double totalPagado) {
    this->totalPagado = totalPagado;
}

double Cliente::GetTotalPagado() const {
    return totalPagado;
}

void Cliente::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::GetDescuento() const {
    return descuento;
}

void Cliente::SetDistrito(const char* distrito) {
    if (this->distrito != nullptr) delete this->distrito;
    this->distrito = new char[strlen(distrito) + 1];
    strcpy(this->distrito, distrito);
}

void Cliente::GetDistrito(char *distrito) const {
    if (this->distrito == nullptr) distrito[0] = 0;
    else strcpy(distrito, this->distrito);
}

void Cliente::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::leer(ifstream& input) {
    char c, nombre[60], distrito[60];
    input >> dni>>c;
    input.getline(nombre, 60, ',');
    input.getline(distrito, 60, ',');
    input >> c;
    if (c == 'S') input >> c >> descuento >> c;
    else descuento=0;
    SetNombre(nombre);
    SetDistrito(distrito);
}

void Cliente::mostrar(ofstream &output) {
    char nom[50], dist[30], c = '%';
    GetNombre(nom);
    GetDistrito(dist);
    output<<setprecision(2)<<fixed;
    output << left << setw(12) << dni << setw(40) << nom << setw(30) << dist <<
            descuento << setw(5) << c << totalPagado << endl;
}

void operator>>(ifstream &input, Cliente &c) {
    c.leer(input);
}

void operator<<(ofstream &output, Cliente &c) {
    c.mostrar(output);
}