/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PlatoFondo.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:20 AM
 */

#include "PlatoFondo.hpp"

PlatoFondo::PlatoFondo() {
    proteina= new int[4]{};//ind 0 pollo, 1 carne, 2 pescado, 3 lacteos;
}

PlatoFondo::PlatoFondo(const PlatoFondo& orig) {
}

PlatoFondo::~PlatoFondo() {
}

void PlatoFondo::insertar_proteina(int *protes){
    for (int i = 0; i < 4; i++) {
        proteina[i]=protes[i];
    }

}
void PlatoFondo::imprimir_proteinas(ofstream &output){
    output << "Proteina en el plato: ";
    for (int i = 0; i < 4; i++) {
        if(proteina[i]==1){
            switch(i){
                case 0:
                    output << "Pollo ";
                    break;
                case 1:
                    output<< "Carne ";
                    break;
                case 2:
                    output<<"Pescado ";
                    break;
                case 3:
                    output<<"Lacteos ";
                    break;
            }
        }
    }

}
