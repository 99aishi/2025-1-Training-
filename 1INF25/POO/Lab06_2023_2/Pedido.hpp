/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.hpp
 * Author: 999
 *
 * Created on June 5, 2025, 9:52 PM
 */

#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include "utils.hpp"
class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetPrecio_producto(double precio_producto);
    double GetPrecio_producto() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* );
    void GetCodigo(char *) const;
    void Leer(ifstream &);
private:
    char * codigo;
    int dni_cliente;
    double precio_producto;
};
bool operator >> (ifstream &input, Pedido &ped);
#endif /* PEDIDO_HPP */

