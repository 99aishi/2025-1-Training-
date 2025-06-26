/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Vehiculo.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:46 PM
 */

#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include "utils.hpp"
#include "NPedido.hpp"

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char *);
    string GetPlaca() const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &input);
    virtual void imprime(ofstream &output);
    virtual bool operator ==(int ) =0;
    virtual void cargadeposito(NPedido &ped)=0;
private:
    int cliente;
    string placa;
    double maxcarga;
    double actcarga;
    //actcarga no puede exceder maxcarga
};

#endif /* VEHICULO_HPP */

