/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: 999
 * 
 * Created on June 20, 2025, 12:19 AM
 */

#include "Tesoreria.hpp"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}
void Tesoreria::cargaalumnos(){
    aboleta.crear("Alumnos.csv");
}
void Tesoreria::imprimeboleta(){
    aboleta.mostrar_en_orden("BoletasAlumnos.txt");
}
void Tesoreria::actualizaboleta(){
    aboleta.carga_escalas("escalas.csv");
    aboleta.modificar();
}
