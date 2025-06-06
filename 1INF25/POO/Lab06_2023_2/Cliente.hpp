/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.hpp
 * Author: 999
 *
 * Created on June 5, 2025, 9:40 PM
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "ProductoEntregado.hpp"
#include "Pedido.hpp"


class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void Leer(ifstream &);
    
    void operator +=(Pedido &);
    
    
    void Mostrar(ofstream &);
private:
    int dni;
    char *nombre;
    int telefono;
    ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
};


bool operator >> (ifstream &,Cliente &c);
void operator << (ofstream &,Cliente &c);




#endif /* CLIENTE_HPP */

