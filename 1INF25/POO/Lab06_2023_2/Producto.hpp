/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Producto.hpp
 * Author: 999
 *
 * Created on June 5, 2025, 9:41 PM
 */

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include "utils.hpp"
#include "Pedido.hpp"
class Producto {
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos);
    int GetCantidad_clientes_no_servidos() const;
    void SetCantidad_clientes_servidos(int cantidad_clientes_servidos);
    int GetCantidad_clientes_servidos() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetDescripcion(const char* );
    void GetDescripcion(char *) const;
    void SetCodigo(const char* );
    void GetCodigo(char *) const;
    
    void Leer(ifstream &);
    void Mostrar(ofstream &);
    
    bool operator +=(Pedido &);
private:
    char*codigo;
    char*descripcion;
    double precio;
    int stock;
    int clientes_servidos[100];
    int clientes_no_servidos[100];
    int cantidad_clientes_servidos;
    int cantidad_clientes_no_servidos;
};  
bool operator >> (ifstream &input, Producto &p);
void operator << (ofstream &output,Producto &p);
#endif /* PRODUCTO_HPP */

