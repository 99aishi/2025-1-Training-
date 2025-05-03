/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 3, 2025, 1:12 AM
 */

#include <iostream>
#define N 5
#define M 5
using namespace std;



void modificar_matriz(int matriz[N][M],int x,int y,int num_mayor,bool encontrado){
    int mayor,posx=0,posy=0;
    if(encontrado and (x==N and y == M)){
        return modificar_matriz(matriz,x,y,num_mayor,!encontrado);
    }
    
    if(y<M and !encontrado){
        mayor=matriz[x][y];
        if(mayor>num_mayor){
            num_mayor=mayor;            
        }
        return modificar_matriz(matriz,x,y+1,num_mayor,encontrado);
    }
    if(x+1<N and !encontrado){
        mayor=matriz[x][0];
        if(mayor>num_mayor){
            num_mayor=mayor;            
        }
        return modificar_matriz(matriz,x+1,0,num_mayor,encontrado);
    }


    cout << num_mayor<<endl;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout <<15 - matriz[i][k]<<" ";
        }
        cout <<endl;
    }
}










int main(int argc, char** argv) {
    int matriz[N][M]={{4,3,6,8,7},
                    {6,3,8,4,10},
                    {2,15,1,2,13},
                    {5,1,10,11,2},
                    {10,4,7,9,4}};
    
    modificar_matriz(matriz,0,0,0,false);
    
    
    return 0;
}

