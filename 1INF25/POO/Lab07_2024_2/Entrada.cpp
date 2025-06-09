/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Entrada.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:19 AM
 */

#include "Entrada.hpp"

Entrada::Entrada() {
    picante=false;
}

Entrada::Entrada(const Entrada& orig) {
}

Entrada::~Entrada() {
}

void Entrada::SetPicante(bool picante) {
    this->picante = picante;
}

bool Entrada::IsPicante() const {
    return picante;
}

