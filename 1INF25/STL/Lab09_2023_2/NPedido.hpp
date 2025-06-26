/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NPedido.hpp
 * Author: 999
 *
 * Created on June 25, 2025, 11:39 PM
 */

#ifndef NPEDIDO_HPP
#define NPEDIDO_HPP

#include "utils.hpp"

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void leer(ifstream &input);
    void mostrar(ofstream &output);
    void operator = (const NPedido &otro);
private:
    string codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_HPP */

