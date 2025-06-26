/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Furgon.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:56 PM
 */

#ifndef FURGON_HPP
#define FURGON_HPP

#include "Vehiculo.hpp"
#include "NPedido.hpp"


class Furgon :public Vehiculo{
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void lee(ifstream &input);
    void imprime(ofstream &output);
    bool operator ==(int );
    void cargadeposito(NPedido &ped);
private:
    int filas;
    int puertas;
    list<NPedido> pdeposito; // simular pila, si no se simulare una lista normal :v
};

#endif /* FURGON_HPP */

