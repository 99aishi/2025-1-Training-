/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesRegistros.hpp
 * Author: 999
 *
 * Created on May 6, 2025, 9:16 PM
 */

#ifndef FUNCIONESREGISTROS_HPP
#define FUNCIONESREGISTROS_HPP
#include "utils.hpp"
void *leeregistro(ifstream &input);
char *lee_cadena(ifstream &input);
void imprimeregistro(ofstream &repo, void *elemento);
int cmpregistro(void* elemento1,  void* elemento2);
#endif /* FUNCIONESREGISTROS_HPP */
