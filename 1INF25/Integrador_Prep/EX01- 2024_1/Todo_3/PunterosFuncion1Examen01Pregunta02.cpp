/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PunterosFuncion1Examen01Pregunta02.cpp
 * Author: 999
 * 
 * Created on May 16, 2025, 1:47 AM
 */

#include "PunterosFuncion1Examen01Pregunta02.hpp"
#include "utils.hpp"
void cargaranking(void *&ranking,void*(*crearegistro)(void*),void *ventas){
    
    creacola(ranking);
    void **arr_ventas=(void **)ventas;
    for (int i = 0; arr_ventas[i]; i++) {
        void *registro=crearegistro(arr_ventas[i]);
        
    }

    
}
