/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Camion.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:54 PM
 */

#ifndef CAMION_HPP
#define CAMION_HPP

#include "Vehiculo.hpp"
#include "NPedido.hpp"


class Camion:public Vehiculo {
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void lee(ifstream &input);
    void imprime(ofstream &output);
    bool operator ==(int );
    void cargadeposito(NPedido &ped);
private:
    int ejes;
    int llantas;
    map<int, vector<NPedido>> mdeposito;
    //cada camion puede llevar 5 pedidos maximo
};

#endif /* CAMION_HPP */

