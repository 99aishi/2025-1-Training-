/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FunConRegistro.hpp
 * Author: 999
 *
 * Created on May 9, 2025, 2:07 AM
 */

#ifndef FUNCONREGISTRO_HPP
#define FUNCONREGISTRO_HPP
#include "utils.hpp"
void* leepedido(ifstream &input);
char *leer_cadena(ifstream &input,int size,char delim);
int prioridadpedido(void *dato);
void muestrapedido(void *reg,ofstream &repo);
void insertar_prioridad_libros(void* cola,void *elemento);
#endif /* FUNCONREGISTRO_HPP */
