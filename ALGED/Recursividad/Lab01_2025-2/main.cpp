/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on May 3, 2025, 2:27 AM
 */

#include <iostream>

using namespace std;

void triangulo(int a,int b){    
    if(a>b) return;
    for (int i = 0; i < a; i++) {
        cout <<"* ";
    }
    cout <<endl;
    triangulo(a+1,b);    
    for (int i = 0; i < a; i++) {
        cout<<"* ";
    }
    cout<<endl;    
}
void patron(int n,int i){
    //caso base
    if(n==0) return;
    //parte recursiva
    patron(n/2,i);
    //dsp de volver imprimimos
    for (int j=0;j<i;j++) cout<<" ";//Los espacios
    for (int j=0;j<n;j++) cout<<"*";//Los asteriscos
    cout<<endl;

    patron(n/2,i+n/2);
    
    
}
int main(int argc, char** argv) {
    int a=3,b=6;
    triangulo(a,b);
    cout <<"------------------------------------------------------"<<endl;
    patron(8,0);
    
    
    
    return 0;
}

