/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:10 AM
 */

#include "Virtual.hpp"

Virtual::Virtual() {
    licencia=nullptr;
}

Virtual::Virtual(const Virtual& orig) {
}

Virtual::~Virtual() {
}
void Virtual::SetLicencia(const char* licencia) {
    if (this->licencia != nullptr) delete this->licencia;
    this->licencia = new char[strlen(licencia) + 1];
    strcpy(this->licencia, licencia);
}

void Virtual::GetLicencia(char *licencia) const {
    if (this->licencia == nullptr) licencia[0]=0;
    strcpy(licencia, this->licencia);
}
void Virtual::lee(ifstream &input){
    char lic[20];
    Alumno::lee(input);
    input.getline(lic,20,'\n');
    SetLicencia(lic);
    total=0;
}
void Virtual::imprime(ofstream &output){
    Alumno::imprime(output);
    output << licencia << endl;
}

void Virtual::modifica(double precio){
    Alumno::modifica(precio);
}