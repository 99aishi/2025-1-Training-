/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flota.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:58 PM
 */

#ifndef FLOTA_HPP
#define FLOTA_HPP

#include "NVehiculo.hpp"
#include "NPedido.hpp"




class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
    void cargapedidos();
    void insertar_pedido(NPedido &pedido, int );
private:
    vector<NVehiculo> vflota;
};

#endif /* FLOTA_HPP */

