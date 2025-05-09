/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Listaconenteros.hpp
 * Author: 999
 *
 * Created on May 8, 2025, 7:57 PM
 */

#ifndef LISTACONENTEROS_HPP
#define LISTACONENTEROS_HPP
#include "utils.hpp"
void *leenumeros(ifstream &input);
void compruebanumero(void* registro, void *lista);
void *leeregnumeros(ifstream &input);
void imprimenumeros(ofstream &output,void *lista);
#endif /* LISTACONENTEROS_HPP */
