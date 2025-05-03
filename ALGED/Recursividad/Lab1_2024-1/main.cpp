

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 3, 2025, 12:31 AM
 */

#include <iostream>
#define N 6 
#define M 6 


using namespace std;

int recursivo(int matriz[N][M],int x,int y,int n,int m,int limX,int limY, int nivel){
    int cont=0;
    //caso base
    if(x>=N or y>=M or x <0 or y < 0) return 0;
    //recursivida
    if(x==limX and y ==limY){
        cout << "Nivel " << nivel << ": " << matriz[x][y] << endl;
        return matriz[x][y] + recursivo(matriz,x-1,y-1,n,m,limX+1,limY+1,nivel+1);
    }
    for (int i = y; i < limY; i++) cont+= matriz[x][i];
    for (int i = x; i < limX; i++) cont+= matriz[i][limY];
    for (int i = limY; i >y ; i--) cont+= matriz[limX][i];
    for (int i = limX; i > x; i--) cont+= matriz[i][y];
    cout << "Nivel " << nivel << ": " << cont << endl;
    return cont + recursivo(matriz,x-1,y-1,n,m,limX+1,limY+1,nivel+1);
    
}


int main(int argc, char** argv) {
    
    int matriz[N][M]={{0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,0,0,1,0}};
    int n=6, m=6, x=3, y=2, limX = x, limY = y;
    cout << "Se encontraron " << recursivo(matriz,x,y,n,m,limX,limY,1) << " unidades";
    
    return 0;
}

