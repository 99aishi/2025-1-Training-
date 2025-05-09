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
void creacola(void *&cola,void*(*leenumero)(ifstream &),void (*prioridadnumero)(void *, void*),const char*nom);
void imprimirnum(void *cola,const char *nom);
void construircola(void *&cola);
void* desencolar(void *&cola);
void descargarcola(void *&cola,void(*muestranumero)(void*,ofstream&),const char *nom);
#endif /* BIBGENERICA_HPP */
