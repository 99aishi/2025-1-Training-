/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   AnalisisSentimiento.hpp
 * Author: 999
 *
 * Created on June 26, 2025, 10:38 PM
 */

#ifndef ANALISISSENTIMIENTO_HPP
#define ANALISISSENTIMIENTO_HPP

#include "Oracion.hpp"

class AnalisisSentimiento {
public:
    AnalisisSentimiento();
    AnalisisSentimiento(const AnalisisSentimiento& orig);
    virtual ~AnalisisSentimiento();
    void cargar_lexicon();
    void cargar_comentarios_restaurantes();
    void pre_procesar_oracion(string &oracion);
    void procesar_oracion(string oracion,Oracion &orac);
    void leer_oracion(ifstream &input, Oracion &orac);
    void ordenar_comentarios();
    void mostrar();
private:
    map<string, vector<Oracion>> comentarios;
    map<string, int>lexicon;
};

#endif /* ANALISISSENTIMIENTO_HPP */

