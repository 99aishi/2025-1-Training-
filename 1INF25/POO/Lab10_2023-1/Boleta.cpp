/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:13 AM
 */

#include "Boleta.hpp"
#include "Presencial.hpp"
#include "Virtual.hpp"
#include "Semipresencial.hpp"
#include "Escala.hpp"

Boleta::Boleta() {
}

Boleta::Boleta(const Boleta& orig) {
}

Boleta::~Boleta() {
}

void Boleta::crear_memoria(char tipo){
    
    if(tipo=='P')
        pboleta=new Presencial;
    if(tipo=='S')
        pboleta=new Semipresencial;
    if(tipo=='V')
        pboleta=new Virtual;
    
    
}
void Boleta::leer(ifstream &input){
    pboleta->lee(input);
}
bool Boleta::operator > (const Boleta &otro){
    return pboleta->GetCodigo() > otro.pboleta->GetCodigo();
}
void operator << (ofstream &output, Boleta &dato){
    dato.imprime(output);
}
void Boleta::imprime(ofstream &output){
   pboleta->imprime(output);
}
void Boleta::actualiza(Escala *lescala){
    int cod_escala=pboleta->GetEscala();
    double precio = lescala[cod_escala-1].GetPrecio();
    pboleta->modifica(precio);
}