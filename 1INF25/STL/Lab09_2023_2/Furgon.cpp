/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:56 PM
 */

#include "Furgon.hpp"

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::lee(ifstream &input) {
    Vehiculo::lee(input);
    input >> filas;
    input.get();
    input>>puertas;
    input.get();
}

void Furgon::imprime(ofstream &output) {
    Vehiculo::imprime(output);
    output << "#Filas: " << filas << endl;
    output << "#Puertas: " << puertas << endl;
//    for(auto lis: pdeposito){
//        lis.mostrar(output);
//    }
    int cont=1;
    for (auto lis: pdeposito) {
        output <<setw(3)<< cont++;
        lis.mostrar(output);
    }

}
bool Furgon::operator ==(int clien){
    //pushtop
    return (this->GetCliente() == clien);
}
void Furgon::cargadeposito(NPedido &ped){
    int actual= GetActcarga() , max= GetMaxcarga();
    
    if(ped.GetPeso() <= (max-actual)){
        pdeposito.push_front(ped);
        actual+=ped.GetPeso();
        SetActcarga(actual);
    }
}