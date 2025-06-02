/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Restaurante.hpp
 * Author: 999
 *
 * Created on June 2, 2025, 11:59 AM
 */

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP
#include "Cliente.hpp"
#include "Plato.hpp"
#define INCREMENTO 5
class Restaurante {
public:
    Restaurante();
    Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void SetCapacidad_platos(int capacidad_platos);
    int GetCapacidad_platos() const;
    void SetCantidad_platos(int cantidad_platos);
    int GetCantidad_platos() const;
    void SetCapacidad_clientes(int capacidad_clientes);
    int GetCapacidad_clientes() const;
    void SetCantidad_clientes(int cantidad_clientes);
    int GetCantidad_clientes() const;
    
    void operator < (const char * nombre_archivo);
    void aumentar_capacidad_clientes();
    void cargar_clientes(ifstream &input);
    
    void operator <=(const char *nombre_archivo);
    void cargar_platos(ifstream &input);
    void aumentar_capacidad_platos();
    
    void operator >>(const char *nombre_archivo);
    void mostrar_platos(ofstream&);
    void mostar_clientes(ofstream&);
    void imprime_linea(ofstream &output,int size, char car);
    
    void operator <<=(const char *nombre_archivo);
    int buscar_dni(int);
    int buscar_plato(char *codigo);
private:
    Cliente *clientes;
    int cantidad_clientes;
    int capacidad_clientes;
    Plato *platos;
    int cantidad_platos;
    int capacidad_platos;
    
};

#endif /* RESTAURANTE_HPP */

