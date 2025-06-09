/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:07 AM
 */

#include "Restaurante.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante restaurante;
    restaurante.cargar_comandas();
    restaurante.actualizar_comandas();
    restaurante.imprimir_comandas();
    return 0;
}

