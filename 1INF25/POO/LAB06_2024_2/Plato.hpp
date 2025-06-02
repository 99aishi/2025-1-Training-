/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Plato.hpp
 * Author: 999
 *
 * Created on June 2, 2025, 11:23 AM
 */

#ifndef PLATO_HPP
#define PLATO_HPP
#include "utils.hpp"
class Plato {
public:
    Plato();
    Plato(const Plato& orig);
    virtual ~Plato();
//    void operator =(const Plato &orig);
    void SetTotalNeto(double totalNeto);
    double GetTotalNeto() const;
    void SetTotalBruto(double totalBruto);
    double GetTotalBruto() const;
    void SetTotalEsperado(double totalEsperado);
    double GetTotalEsperado() const;
    void SetNoAtendidos(int noAtendidos);
    int GetNoAtendidos() const;
    void SetAtendidos(int atendidos);
    int GetAtendidos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPreparados(int preparados);
    int GetPreparados() const;
    void SetCategoria(const char* categoria);
    void GetCategoria(char *) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    
    void mostrar(ofstream &);
    void leer(ifstream &);
private:    
    char *codigo;
    char *nombre;
    double precio;
    char *categoria;
    int preparados;
    double descuento;
    int atendidos;
    int noAtendidos;
    double totalEsperado;
    double totalBruto;
    double totalNeto;
};
void operator >> (ifstream &input,Plato &plato);
void operator << (ofstream &output,Plato &plato);



#endif /* PLATO_HPP */

