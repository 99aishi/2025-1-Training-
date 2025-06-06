/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 999
 *
 * Created on June 5, 2025, 9:38 PM
 */


#include "Almacen.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    Almacen almacen;
    almacen.cargar_clientes();
    almacen.cargar_productos();
    almacen.cargar_pedidos();
    almacen.mostrar_datos();
    
//    int n=0;
//    Cliente clientes[140];
//    ifstream csv1("Clientes.csv",ios::in);
//    while(true){
//        if( ! (csv1>>clientes[n])) break;
//        if(n==130) 
//            cout << "XD"<<endl;
//        n++;
//    }
//    cout << n<<endl;
//    ofstream txt1("repo.txt",ios::out);
//    txt1 << clientes[n-1];
//    
//    int n2=0;
//    Producto productos[170];
//    ifstream csv2("Productos.csv",ios::in);
//    while(true){
//        if( ! (csv2>>productos[n2])) break;
//        n2++;
//    }
//    cout << n2<<endl;
//    ofstream txt2("repo2.txt",ios::out);
//    txt2 << productos[n2-1];
//    
//    int n3=0;
//    ifstream csv3("Pedidos.csv",ios::in);
//    Pedido pedidos[600];
//    while(true){
//         if( ! (csv3>>pedidos[n3])) break;
//        n3++;
//    }
//    cout << n3<<endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

