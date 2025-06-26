/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NVehiculo.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:58 PM
 */

#ifndef NVEHICULO_HPP
#define NVEHICULO_HPP

#include "Vehiculo.hpp"
#include "NPedido.hpp"


class NVehiculo {
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    void asigna_memoria(char tipo);
    void leer(ifstream &input);
    void mostrar(ofstream &);
    bool operator < (const NVehiculo &otro);
    void operator =(const NVehiculo &otro);
    bool operator ==(int );
    void insertar_ped(NPedido & ped);
private:
    Vehiculo *unidad;
};
void operator << (ofstream &, NVehiculo &nv);
#endif /* NVEHICULO_HPP */

