/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */




/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 26, 2025, 10:32 PM
 */

#include "AnalisisSentimiento.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    AnalisisSentimiento analisis;
    analisis.cargar_lexicon();
//    cout<<"xd1"<<endl;
    analisis.cargar_comentarios_restaurantes();
//    cout << "xd2"<<endl;
    analisis.ordenar_comentarios();
    analisis.mostrar();
    return 0;
}

