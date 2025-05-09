/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.hpp
 * Author: 999
 *
 * Created on May 8, 2025, 7:49 PM
 */

#ifndef BIBLIOTECAGENERICA_HPP
#define BIBLIOTECAGENERICA_HPP
#include "utils.hpp"
void crealista(void* &lista,void*(*leenumeros)(ifstream &),const char *nom);
void insertafinal(void*dupla,void *lista);
bool esListaVacia(void *lista);
void construirlista(void*&lista);
void cargalista(void *lista,void(*compruebanumero)(void*, void *),void*(*leeregnumeros)(ifstream &),const char *nom);
void muestralista(void *lista,void (*imprimenumeros)(ofstream &,void*),const char *nom);
#endif /* BIBLIOTECAGENERICA_HPP */
