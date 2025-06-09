/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Comanda.hpp
 * Author: 999
 *
 * Created on June 6, 2025, 12:25 AM
 */

#ifndef COMANDA_HPP
#define COMANDA_HPP

#include "PlatoFondo.hpp"
#include "Bebida.hpp"
#include "Entrada.hpp"


class Comanda {
public:
    Comanda();
    Comanda(const Comanda& orig);
    virtual ~Comanda();
    void SetEstado(const char* estado);
    void GetEstado(char *) const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetTiempo_preparacion(int tiempo_preparacion);
    int GetTiempo_preparacion() const;
    void SetHora_servicio(int hora_servicio);
    int GetHora_servicio() const;
    void SetHora_atencion(int hora_atencion);
    int GetHora_atencion() const;
    void SetCantidad_platos_fondo(int cantidad_platos_fondo);
    int GetCantidad_platos_fondo() const;
    void SetCantidad_entradas(int cantidad_entradas);
    int GetCantidad_entradas() const;
    void SetCantidad_bebidas(int cantidad_bebidas);
    int GetCantidad_bebidas() const;
    void SetId(int id);
    int GetId() const;

    int Leer(ifstream &, int &);


    void leer_bebida(ifstream &input);
    void leer_platofondo(ifstream &input);
    void leer_entrada(ifstream &input);
    
    void Mostrar(ofstream &output);
    void imprimir_bebida(ofstream &output);
    void imprimir_entrada(ofstream &output);
    void imprimir_pfondo(ofstream &output);
    void imprimir_horas(ofstream&output);
    void actualizar_comandas(ifstream &input);
    void calcular_estimado();
private:
    int id;
    Bebida bebidas[10];
    Entrada entradas[10];
    PlatoFondo platos_fondo[10];
    int cantidad_bebidas;
    int cantidad_entradas;
    int cantidad_platos_fondo;
    int hora_atencion;
    int hora_servicio;
    int tiempo_preparacion;
    double total;
    char* estado;
};

void operator << (ofstream &output, Comanda &c);

#endif /* COMANDA_HPP */

