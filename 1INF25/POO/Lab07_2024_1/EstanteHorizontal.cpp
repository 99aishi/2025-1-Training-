/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   EstanteHorizontal.cpp
 * Author: 999
 * 
 * Created on June 9, 2025, 1:27 AM
 */

#include "EstanteHorizontal.hpp"

EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas=0;
}

EstanteHorizontal::EstanteHorizontal(const EstanteHorizontal& orig) {
}

EstanteHorizontal::~EstanteHorizontal() {
}

void EstanteHorizontal::SetCantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

int EstanteHorizontal::GetCantidad_novelas() const {
    return cantidad_novelas;
}

