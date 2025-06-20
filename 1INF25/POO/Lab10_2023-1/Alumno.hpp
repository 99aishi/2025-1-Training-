/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: 999
 *
 * Created on June 20, 2025, 12:00 AM
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP
#include "utils.hpp"
class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void lee(ifstream &input);
    virtual void imprime(ofstream &output);
    virtual void modifica(double precio);
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
    double creditos;
};

#endif /* ALUMNO_HPP */

