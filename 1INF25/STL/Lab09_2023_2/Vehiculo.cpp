/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:46 PM
 */

#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char *placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream &input){
    char c, buffer[20];
    input >> cliente>>c;
    input.getline(buffer,20,',');
    input >> maxcarga;
    actcarga=0;
    input.get();
    SetPlaca(buffer);
}
void Vehiculo::imprime(ofstream &output){
    output << "Codigo Cliente: "<< cliente << endl;
    output << "Placa: "<< placa << endl;
    output << "Carga maxima: "<< maxcarga << endl;
    output << "Carga actual: "<< actcarga << endl;
}