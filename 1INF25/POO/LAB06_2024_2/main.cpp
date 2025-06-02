/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 2, 2025, 11:03 AM
 */
#include "Restaurante.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream csv_clientes("Clientes.csv",ios::in);
    ifstream csv_platos("PlatosOfrecidos.csv",ios::in);
    Cliente cl;
    csv_clientes>>cl;
    char nom_cl[100];
    cl.GetNombre(nom_cl);
//    cout << nom_cl<<endl;
    ofstream prueba("prueba.txt",ios::out);
    prueba<<cl;
    Plato plato;
    csv_platos>>plato;
    char nom_pt[100];
    plato.GetNombre(nom_pt);
    prueba<<plato;
//    cout << nom_pt<<endl;
    
    
    Restaurante restaurante;
    restaurante <"Clientes.csv";
    restaurante <="PlatosOfrecidos.csv";
    restaurante <<="Pedidos.csv";
    restaurante >> "ReporteDeVentasDelDia.txt";
    return 0;
}

