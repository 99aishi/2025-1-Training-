/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:09 AM
 */

#include "Presencial.hpp"

Presencial::Presencial() {
}

Presencial::Presencial(const Presencial& orig) {
}

Presencial::~Presencial() {
}
void Presencial::lee(ifstream &input){
    Alumno::lee(input);
    input >>recargo;
    input.get();
    total=0;
}
void Presencial::imprime(ofstream &output){
    Alumno::imprime(output);
    output<<setw(15)<< " ";
    output << total<<endl;
}

void Presencial::modifica(double precio){
    total = (1+recargo/100) * Alumno::GetCreditos() * precio;
    Alumno::SetTotal(total);
}