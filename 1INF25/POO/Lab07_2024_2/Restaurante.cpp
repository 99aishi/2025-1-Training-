/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:27 AM
 */

#include "Restaurante.hpp"

Restaurante::Restaurante() {
    cantidad_comandas=0;
}

Restaurante::Restaurante(const Restaurante& orig) {
}

Restaurante::~Restaurante() {
}

void Restaurante::cargar_comandas(){
    ifstream input("comandas.csv",ios::in);
    int id_comanda;
    char c;
    input >> id_comanda;
    while(true){
        id_comanda=comandas[cantidad_comandas].Leer(input,id_comanda);
        if(input.eof()) break;
        cantidad_comandas++;
    }
}

void Restaurante::imprimir_comandas(){
    ofstream repo("ReporteCOMANDAS.txt",ios::out);
    for (int i = 0; i <= cantidad_comandas; i++) {
        repo << comandas[i];
    }

}
int Restaurante::buscar_comanda(int comanda){
    
    for (int i = 0; i <= cantidad_comandas; i++) {
        if(comanda==comandas[i].GetId()) return i;
    }
    return -1;

}
void Restaurante::actualizar_comandas(){
    ifstream input("atenciones.csv",ios::in);
    int comanda;
    char c;
    while(true){
        input >> comanda>>c;
        if(input.eof()) break;
        int pos=buscar_comanda(comanda);
        if(pos!= -1)
            comandas[pos].actualizar_comandas(input);
    }
    ordenar();
}
void Restaurante::ordenar(){
    qsort(comandas,cantidad_comandas,sizeof(class Comanda),compara_cod);
}

int compara_cod(const void* com1,const void *com2){
    Comanda *comA=(Comanda*)com1;
    Comanda *comB=(Comanda*)com2;
    
    return - comA->GetId() + comB->GetId();
}

