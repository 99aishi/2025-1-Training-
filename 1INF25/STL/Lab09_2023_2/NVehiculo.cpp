/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   NVehiculo.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:58 PM
 */

#include "NVehiculo.hpp"
#include "Furgon.hpp"
#include "Camion.hpp"

NVehiculo::NVehiculo() {
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    *this = orig;
}

NVehiculo::~NVehiculo() {
}
void NVehiculo::operator =(const NVehiculo &otro){
    this->unidad = otro.unidad;
}
void NVehiculo::asigna_memoria(char tipo){
    if(tipo == 'F')
        unidad= new Furgon;
    if(tipo == 'C')
        unidad = new Camion;
}
void NVehiculo::leer(ifstream &input){
    unidad->lee(input);
}
void operator << (ofstream &output, NVehiculo &nv){
    nv.mostrar(output);
}
void NVehiculo::mostrar(ofstream&output){
    unidad->imprime(output);
}
bool NVehiculo::operator < (const NVehiculo &otro){
    return unidad->GetCliente() < otro.unidad->GetCliente();
}
bool NVehiculo::operator == (int clie){
    return *unidad==clie;
}
void NVehiculo::insertar_ped(NPedido & ped){
    unidad->cargadeposito(ped);
}