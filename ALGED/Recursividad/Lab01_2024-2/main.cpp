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



void modificar_matriz(int matriz[N][M],int x,int y,int num_mayor, int aux[N][M]){
    
    int mayor;
    if(x>=N){
        cout << num_mayor<<endl;
        return;
    }
    
    if(y<M){
        mayor=matriz[x][y];
        if(mayor>num_mayor){
            num_mayor=mayor;			        
        }
//        aux[x][y]=num_mayor - matriz[x][y];   
        modificar_matriz(matriz,x,y+1,num_mayor,aux);
    }else{
        if(x+1<N){
        mayor=matriz[x+1][0];
        if(mayor>num_mayor){
            num_mayor=mayor;            
        }
//        aux[x][y]=num_mayor - matriz[x][0];    
        modificar_matriz(matriz,x+1,0,num_mayor,aux);
        }else{
            modificar_matriz(matriz,x+1,4,num_mayor,aux);
        }
    }
    
    
    aux[x][y-1]= num_mayor-matriz[x][y-1];





}










int main(int argc, char** argv) {
    int matriz[N][M]={{4,3,6,8,7},
                    {6,3,8,4,10},
                    {2,15,1,2,13},
                    {5,1,10,11,2},
                    {10,4,7,9,4}};
    int aux[N][M]={{4,3,6,8,7},
                    {6,3,8,4,10},
                    {2,15,1,2,13},
                    {5,1,10,11,2},
                    {10,4,7,9,4}};
    modificar_matriz(matriz,0,0,0,aux);
    
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cout <<aux[i][k]<<" ";
        }
        cout <<endl;
    }
    return 0;
}

