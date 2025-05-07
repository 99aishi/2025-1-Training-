/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.hpp
 * Author: 999
 *
 * Created on May 6, 2025, 7:06 PM
 */

#ifndef BIBLIOTECAGENERICA_HPP
#define BIBLIOTECAGENERICA_HPP
#include "utils.hpp"
#include "FuncionesEnteras.hpp"

void crealista(void *&pedidos1,void *(leenum)(ifstream &),const char *nom);
void construirlista(void *&lista);
void insertarlista(void *lista,void * elemento);
bool listavacia(void *lista);
void imprimelista(void *pedidos1,void(*imprimenum)(ofstream &, void *),const char *nomb);
void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,int (*cmpnum)(void* ,void*));
void *ver_elemento(void *pedidos1);
void *quitalista(void *pedidos);
void ingresarlistanovacia(void *pedidos1,void *pedidos2,void *&pedidosfinal);
#endif /* BIBLIOTECAGENERICA_HPP */
