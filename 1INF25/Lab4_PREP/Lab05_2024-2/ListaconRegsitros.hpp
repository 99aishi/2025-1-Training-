/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaconRegsitros.hpp
 * Author: 999
 *
 * Created on May 8, 2025, 9:27 PM
 */

#ifndef LISTACONREGSITROS_HPP
#define LISTACONREGSITROS_HPP
#include "utils.hpp"
void *leeregistros(ifstream&input);
char *leer_cadena(ifstream &input,int size,char delim);
void *devolver_registro_ingresar(void* registro);
void compruebaregistro(void *registro, void *lista);
void* leeordenes(ifstream &input);
void imprimeregistros(ofstream &repo,void* lista);
#endif /* LISTACONREGSITROS_HPP */
