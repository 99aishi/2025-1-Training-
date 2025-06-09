/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Novelas.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:19 AM
 */

#include "Novela.hpp"

Novela::Novelas() {
    tipo = nullptr;
}

Novela::Novelas(const Novela& orig) {
}

Novela::~Novela() {
//    delete this->tipo;
}

void Novela::SetTipo(const char* tipo) {
    if(this->tipo!=nullptr) delete this->tipo;
    this->tipo=new char[strlen(tipo)+1];
    strcpy(this->tipo,tipo);
}

void Novela::GetTipo(char* tipo) const {
    if(this->tipo==nullptr) tipo[0]=0;
    strcpy(tipo,this->tipo);
}

void Novela::SetPeso(double peso) {
    this->peso = peso;
}

double Novela::GetPeso() const {
    return peso;
}

