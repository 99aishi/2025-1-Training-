/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteVertical.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:26 AM
 */

#include "EstanteVertical.hpp"

EstanteVertical::EstanteVertical() {
    cantidad_enciclopedias=0;
}

EstanteVertical::EstanteVertical(const EstanteVertical& orig) {
}

EstanteVertical::~EstanteVertical() {
}

void EstanteVertical::SetCantidad_enciclopedias(int cantidad_enciclopedias) {
    this->cantidad_enciclopedias = cantidad_enciclopedias;
}

int EstanteVertical::GetCantidad_enciclopedias() const {
    return cantidad_enciclopedias;
}

