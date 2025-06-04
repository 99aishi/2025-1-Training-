/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Espacio.cpp
 * Author: 999
 * 
 * Created on June 3, 2025, 12:55 PM
 */

#include "Espacio.hpp"

Espacio::Espacio() {
    contenido = ' ';
    posX=0;
    posY=0;
}

Espacio::Espacio(const Espacio& orig) {
}

Espacio::~Espacio() {
}

void Espacio::SetPosY(int posY) {
    this->posY = posY;
}

int Espacio::GetPosY() const {
    return posY;
}

void Espacio::SetPosX(int posX) {
    this->posX = posX;
}

int Espacio::GetPosX() const {
    return posX;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}
void Espacio::Mostrar(ofstream &out){
    out << "[ " <<contenido<<" ]";
}
void operator << (ofstream &out, Espacio&e){
    e.Mostrar(out);
}