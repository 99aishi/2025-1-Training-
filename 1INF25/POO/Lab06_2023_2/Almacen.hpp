/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Almacen.hpp
 * Author: 999
 *
 * Created on June 5, 2025, 11:24 PM
 */

#ifndef ALMACEN_HPP
#define ALMACEN_HPP

#include "Cliente.hpp"
#include "Producto.hpp"


class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void SetCantidad_productos(int arreglo_productos);
    int GetCantidad_productos() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    
    void cargar_clientes();
    void cargar_productos();
    void cargar_pedidos();
    void procesar_pedido(Pedido &pedido);
    int buscar_producto(Pedido &ped);
    int buscar_cliente(int );
    
    void mostrar_datos();
private:
    Cliente arreglo_clientes[140];
    int cantidad_clientes;
    Producto arreglo_productos[170];
    int cantidad_productos;
};

#endif /* ALMACEN_HPP */

