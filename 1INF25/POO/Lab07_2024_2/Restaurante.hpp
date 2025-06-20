/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Restaurante.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:27 AM
 */

#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP

#include "Comanda.hpp"


class Restaurante {
public:
    Restaurante();
    Restaurante(const Restaurante& orig);
    virtual ~Restaurante();
    void cargar_comandas();
    void imprimir_comandas();
    int buscar_comanda(int comanda);
    void actualizar_comandas();
    void ordenar();
    
private:
    Comanda comandas[205];
    int cantidad_comandas;
};
int compara_cod(const void* ,const void *);
#endif /* RESTAURANTE_HPP */

