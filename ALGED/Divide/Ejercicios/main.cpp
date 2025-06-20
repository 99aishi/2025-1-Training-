/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 2 de junio de 2025, 11:18
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int evaluarMaximo(int max1,int max2,int max3){
    if (max1>=max2 && max1>=max3){
        return max1;
    }
    else{
        if (max2>=max1 && max2>=max3){
            return max2;
        }
        else{
            return max3;
        }
    }
}

int buscarMayorCentro(int *arreglo,int inicio,int medio,int fin){
    /*Evaluamos primero para la izquierda*/
    bool esPrimero = true;
    int suma = 0, maxIzq, maxDer, maxTotal;
    for (int i=medio; i>=inicio; i--){
        suma = suma + arreglo[i];
        if (esPrimero || suma>maxIzq){
            maxIzq = suma;
        }
        esPrimero = false;
    }
    /*Evaluamos primero para la derecha*/
    esPrimero = true;
    suma = 0;
    for (int i=medio+1; i<=fin; i++){
        suma = suma + arreglo[i];
        if (esPrimero || suma>maxDer){
            maxDer = suma;
        }
        esPrimero = false;
    }
    maxTotal = maxIzq + maxDer;
    return evaluarMaximo(maxIzq,maxDer,maxTotal);
}

int buscarMayorSuma(int *arreglo,int inicio,int fin){
    if (inicio==fin){
        return arreglo[inicio];
    }
    int medio = (inicio+fin)/2;
    int maxIzq = buscarMayorSuma(arreglo,inicio,medio);
    int maxDer = buscarMayorSuma(arreglo,medio+1,fin);
    int maxCentro = buscarMayorCentro(arreglo,inicio,medio,fin);
    return evaluarMaximo(maxIzq,maxDer,maxCentro);
}

int main(int argc, char** argv) {
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(arr)/sizeof(arr[0]),ini=0,fin=n-1;
    int numero=buscarMayorSuma(arr,ini,fin);
    cout<<numero;
    
    return 0;
}
