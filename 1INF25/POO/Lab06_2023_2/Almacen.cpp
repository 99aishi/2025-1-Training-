/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: 999
 * 
 * Created on June 5, 2025, 11:24 PM
 */

#include "Almacen.hpp"

Almacen::Almacen() {
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes() {
    int n=0;
    ifstream csv1("Clientes.csv", ios::in);
    while (true) {
        if (!(csv1 >> arreglo_clientes[n])) break;
        n++;
    }
    cantidad_clientes=n;
}
void Almacen::cargar_productos(){
    int n2=0;
    ifstream csv2("Productos.csv",ios::in);
    while(true){
        if( ! (csv2>>arreglo_productos[n2])) break;
        n2++;
    }
    cantidad_productos=n2;
}
int Almacen::buscar_producto(Pedido &ped){
    char cod_prod[10], cod_ped[10];
    ped.GetCodigo(cod_ped);
    for (int i = 0; i < cantidad_productos; i++) {
        arreglo_productos[i].GetCodigo(cod_prod);
        if(strcmp(cod_ped,cod_prod)==0) return i;
    }
    return -1;
}
int Almacen::buscar_cliente(int dni_buscar){
    for (int i = 0; i < cantidad_clientes; i++) {
        if(arreglo_clientes[i].GetDni()== dni_buscar) return i;
    }
    return -1;
}
void Almacen::procesar_pedido(Pedido &pedido){
    int pos_prod=buscar_producto(pedido);
    if(pos_prod!= -1 ){
        if(arreglo_productos[pos_prod]+=pedido){
            int pos_cliente= buscar_cliente(pedido.GetDni_cliente());
            if(pos_cliente != -1 ) arreglo_clientes[pos_cliente]+= pedido;
        }
    }
}
void Almacen::cargar_pedidos() {
    int n3 = 0;
    ifstream csv3("Pedidos.csv", ios::in);
    while (true) {
        Pedido pedido;
        if (!(csv3 >> pedido)) break;
        else{
            procesar_pedido(pedido);
            
        }
        n3++;
        
    }

}
void Almacen::mostrar_datos(){
    
    ofstream txt1("RepoClientes.txt",ios::out);
    for (int i = 0; i < cantidad_clientes; i++) {
        txt1<<arreglo_clientes[i];
    }
    ofstream txt2("RepoProductos.txt",ios::out);
    for (int i = 0; i < cantidad_productos; i++) {
        txt2<<arreglo_productos[i];
    }
    
}