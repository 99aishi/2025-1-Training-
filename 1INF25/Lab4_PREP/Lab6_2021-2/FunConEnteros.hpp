/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FunConEnteros.hpp
 * Author: 999
 *
 * Created on May 8, 2025, 11:50 PM
 */

#ifndef FUNCONENTEROS_HPP
#define FUNCONENTEROS_HPP
#include "utils.hpp"
void* leenumero(ifstream &input);
void prioridadnumero(void* cola,void*elemento);
void insertar_prioridad(void* cola,void *elemento);
bool esColaVacia(void *cola);
#endif /* FUNCONENTEROS_HPP */
