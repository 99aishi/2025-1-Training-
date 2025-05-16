/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PunterosMultiples1Examen01Pregunta01.hpp
 * Author: 999
 *
 * Created on May 15, 2025, 10:58 PM
 */

#ifndef PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_HPP
#define PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_HPP
#include "utils.hpp"

void cargarVentas(char**&ventasLibroCodigo,int **&ventasDniFechaPuntaje,const char *nom);
void leer_info(ifstream &input,int &dni, int&fecha,int&calificacion);
void aumentar_capacidad(int **&ventasDniFechaPuntaje,char **&ventasLibroCodigo,int &capacidad,int &n_datos);
char *lee_cadena(ifstream &input, int size, char delim);
void ingresar_datos(char *codigo,int dni, int fecha,int calificacion,int *&ventasDniFechaPuntaje,char *&ventasLibroCodigo);
void pruebaCargaVentas(char **ventasLibroCodigo,int **ventasDniFechaPuntaje,const char *nom);
void pasar_datos_libros(char* codigo,char *titulo,char *autor,char **&registro);
void cargaLibros(char ***&libro,const char *nom);
int cmpcadena(const void *a,const void* b);
void pruebaLibros(char ***libro,const char *nom);

#endif /* PUNTEROSMULTIPLES1EXAMEN01PREGUNTA01_HPP */
