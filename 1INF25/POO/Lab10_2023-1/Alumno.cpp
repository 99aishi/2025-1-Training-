/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:00 AM
 */

#include "Alumno.hpp"

Alumno::Alumno() {
    nombre=nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0]=0;
    strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &input){
    char c, nom[100] ; 
    input >> codigo>>c;
    input.getline(nom,100,',');
    SetNombre(nom);
    input >> escala>>c>>creditos>>c;
}
void Alumno::imprime(ofstream &output){
    char nombr[100];
//    GetNombre(nombr);
    output <<left<<setw(10)<<codigo<<setw(45)<<nombre<<setw(10)<<escala<<setw(10)<<creditos;
}
void Alumno::modifica(double precio){
    total= precio * creditos;
}