/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:10 AM
 */

#include "Semipresencial.hpp"

Semipresencial::Semipresencial() {
}

Semipresencial::Semipresencial(const Semipresencial& orig) {
}

Semipresencial::~Semipresencial() {
}
void Semipresencial::lee(ifstream &input){
    Alumno::lee(input);
    input >>descuento;
    input.get();
}
void Semipresencial::imprime(ofstream &output){
    Alumno::imprime(output);
    output<<setw(15)<< " ";
    output << total<<endl;
}

void Semipresencial::modifica(double precio){
    Alumno::modifica(precio);
}