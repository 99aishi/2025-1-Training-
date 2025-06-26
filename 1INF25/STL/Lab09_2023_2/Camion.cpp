/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:54 PM
 */

#include "Camion.hpp"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::lee(ifstream &input){
    Vehiculo::lee(input);
    input >> ejes;
    input.get();
    input>>llantas;
    input.get();
}

void Camion::imprime(ofstream &output){
    Vehiculo::imprime(output);
    output << "#Ejes: "<< ejes<<endl;
    output << "#Llantas: "<< llantas<<endl;
    int key=this->GetCliente();
    if(mdeposito[key].size()==0){
        output << "No hay pedidos"<<endl;
    }
//    for(auto pedi: mdeposito[key]){
//        pedi.mostrar(output);
//    }
    for (int i = 0; i < mdeposito[key].size(); i++) {
        output << right << setw(3)<<i+1;
        mdeposito[key][i].mostrar(output);

    }

}

bool Camion::operator ==(int clien ){
    if(clien == this->GetCliente() and mdeposito[this->GetCliente()].size()<5)
        return true;
    return false;
}
void Camion::cargadeposito(NPedido &ped){
    int actual= GetActcarga() , max= GetMaxcarga();
    
    if(ped.GetPeso() <= (max-actual)){
        mdeposito[GetCliente()].push_back(ped);
        actual+=ped.GetPeso();
        SetActcarga(actual);
    }
    
}