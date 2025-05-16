/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ColaPrioridadGenerica.cpp
 * Author: 999
 * 
 * Created on May 16, 2025, 1:47 AM
 */

#include "ColaPrioridadGenerica.hpp"

void creacola(void *&ranking){
    void **arr=new void*[4];
    arr[INICIO]=nullptr;
    arr[TRES]=nullptr;
    arr[DOS]=nullptr;
    arr[UNO]=nullptr;
    ranking=arr;
}