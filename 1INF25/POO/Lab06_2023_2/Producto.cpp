/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: 999
 * 
 * Created on June 5, 2025, 9:41 PM
 */

#include "Producto.hpp"

Producto::Producto() {
    codigo=nullptr;
    descripcion=nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}


void Producto::SetCodigo(const char* codigo){
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
    
}
void Producto::GetCodigo(char *codigo) const{
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Producto::SetDescripcion(const char* descripcion){
    if(this->descripcion!=nullptr) delete this->descripcion;
    this->descripcion=new char[strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
    
}
void Producto::GetDescripcion(char *descripcion) const{
    if(this->descripcion==nullptr) descripcion[0]=0;
    else strcpy(descripcion,this->descripcion);
}
void Producto::Leer(ifstream &input){
    char cod[10],desc[100],c;
    input.getline(cod,10,',');
    input.getline(desc,100,',');
    input >>precio>>c>>stock;
    input.get();
    SetCodigo(cod);
    SetDescripcion(desc);
    cantidad_clientes_no_servidos=0;
    cantidad_clientes_servidos=0;
}
bool operator >> (ifstream &input, Producto &p){
    
    p.Leer(input);
    if(input.eof()) return false;
    return true;
}
void Producto::Mostrar(ofstream &output){
    char cod[10],desc[100];
    GetCodigo(cod);
    GetDescripcion(desc);
    
    output <<left<<setw(10)<<cod<<desc<<endl;
    output << "Clientes atendidos: ";
    if(!cantidad_clientes_servidos) output<<"NO SE ATENDIERON PEDIDOS"<<endl;
    else {
        for (int i = 0; i < cantidad_clientes_servidos; i++)
            output << clientes_servidos[i] << " ";
        output << endl;
    }

    output << "Clientes no atendidos: ";
    if (!cantidad_clientes_no_servidos) output << "NO HAY CLIENTES SIN ATENDER" << endl;
    else {
        for (int i = 0; i < cantidad_clientes_no_servidos; i++)
            output << clientes_no_servidos[i] << " ";
        output << endl;
    }
    output<< endl;


}
 bool Producto::operator +=(Pedido &pedido){
    if(stock){
        pedido.SetPrecio_producto(precio);
        clientes_servidos[cantidad_clientes_servidos]=pedido.GetDni_cliente();
        cantidad_clientes_servidos++;
        stock--;
        return true;
    }else{
        clientes_no_servidos[cantidad_clientes_no_servidos]=pedido.GetDni_cliente();
        cantidad_clientes_no_servidos++;
        return false;
    }
    
     
 }
void operator << (ofstream &output,Producto &p){
    p.Mostrar(output);
}