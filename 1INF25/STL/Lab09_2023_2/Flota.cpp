/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: 999
 * 
 * Created on June 25, 2025, 11:58 PM
 */

#include "Flota.hpp"
#include "NPedido.hpp"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}
void Flota::cargaflota(){
    ifstream input("Vehiculos.csv",ios::in);
    ofstream output("prueba.txt",ios::out);
//F,79464412,K0D-676,300,1,3
//F,16552775,S7E-946,300,2,3
    char tipo,c;
    while(true){
        NVehiculo vehiculo;
        input >> tipo>>c;
        if(input.eof()) break;
        vehiculo.asigna_memoria(tipo);
        vehiculo.leer(input);
        vflota.push_back(vehiculo);
    }
    sort(vflota.begin(),vflota.end());
}
void Flota::muestracarga(){
    ofstream output("reporte_carga.txt",ios::out);
    
    for(NVehiculo nv: vflota){
        output << setprecision(2) << fixed;
        output << nv;
    }
}
void Flota::cargapedidos(){
    ifstream input ("Pedidos3.csv",ios::in);
    //50375303,JXD.139,6,120
//50375303,CRU.009,5,200
    int clien;
    while(true){
        input >> clien;
        if(input.eof()) break;
        input.get();
        NPedido pedido;
        pedido.leer(input);
        insertar_pedido(pedido, clien);
        
    }
}
void Flota::insertar_pedido(NPedido &pedido, int clien){
    for(NVehiculo &nv: vflota){
        if(nv == clien){
            nv.insertar_ped(pedido);
        }
    }
    
    
}