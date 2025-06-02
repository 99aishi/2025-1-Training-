/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cliente.hpp
 * Author: 999
 *
 * Created on June 2, 2025, 11:09 AM
 */

#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include "utils.hpp"

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    
    void operator =(const Cliente &orig);
    void SetTotalPagado(double totalPagado);
    double GetTotalPagado() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetDistrito(const char* distrito);
    void GetDistrito(char *) const;
    void SetNombre(const char* nombre);
    void GetNombre(char *) const;
    void SetDni(int dni);
    int GetDni() const;
    
    void leer(ifstream &);
    void mostrar(ofstream &);
private:
    int dni;
    char *nombre;
    char *distrito;
    double descuento;
    double totalPagado;
};

void operator >> (ifstream &, Cliente &c);
void operator << (ofstream &output,Cliente &c);
    
#endif /* CLIENTE_HPP */

