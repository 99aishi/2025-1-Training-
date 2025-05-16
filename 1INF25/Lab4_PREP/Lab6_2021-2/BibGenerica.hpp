/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibGenerica.hpp
 * Author: 999
 *
 * Created on May 8, 2025, 11:31 PM
 */

#ifndef BIBGENERICA_HPP
#define BIBGENERICA_HPP
#include "utils.hpp"
void creacola(void *&cola,void*(*leenumero)(ifstream &),int (*prioridadnumero)(void*),const char*nom);
void imprimirnum(void *cola,const char *nom);
void construircola(void *&cola);
bool esColaVacia(void *cola);
void* desencolar(void *&cola);
void descargarcola(void *&cola,void(*muestranumero)(void*,ofstream&),const char *nom);
void encola(void *dato,void *cola,int prio);
void insertar_prioridad(void** arr_cola,void **elemento, int prio);
void imprimirped(void *cola,const char *nom);

void insertar1(void **arr_cola,void **nuevo_nodo,int prio);
void insertar2(void** arr_cola,void **nuevo_nodo, int prio);
void insertar3(void **arr_cola,void **nuevo_nodo,int prio);
#endif /* BIBGENERICA_HPP */
