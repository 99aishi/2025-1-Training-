/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Boleta.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:13 AM
 */

#ifndef BOLETA_HPP
#define BOLETA_HPP
#include "Alumno.hpp"
#include "Escala.hpp"
class Boleta {
public:
    Boleta();
    Boleta(const Boleta& orig);
    virtual ~Boleta();
    void crear_memoria(char);
    void leer(ifstream &input);
    bool operator > (const Boleta &otro );
    void imprime(ofstream &output);
    void actualiza(Escala *lescala);
private:
    Alumno *pboleta;
};
void operator << (ofstream &, Boleta &);
#endif /* BOLETA_HPP */

