/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: 999
 * 
 * Created on June 5, 2025, 9:40 PM
 */

#include "Cliente.hpp"

Cliente::Cliente() {
    nombre=nullptr;
    cantidad_productos_entregados=0;
    monto_total=0;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(const char* nombre){
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre=new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}
void Cliente::GetNombre(char *nombre) const{
    if(this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}
void Cliente::operator +=(Pedido &pedido){
    ProductoEntregado entregado;
    char cod[10];
    pedido.GetCodigo(cod);
    entregado.SetCodigo(cod);
    entregado.SetPrecio(pedido.GetPrecio_producto());
    
    productos_entregados[cantidad_productos_entregados]=entregado;
    cantidad_productos_entregados++;
    monto_total+= pedido.GetPrecio_producto() ;
   
}
void Cliente::Leer(ifstream &input){
    input >> dni;
    input.get();
    char _nombre[50];
    input.getline(_nombre,50,',');
    SetNombre(_nombre);
    input >> telefono;
}
void Cliente::Mostrar(ofstream &output){
    char nom[60]{}, cod[10];
    GetNombre(nom);
    output<<setprecision(2)<<fixed;
    output << left << setw(10)<<dni<<setw(40)<<nom<<setw(10)<<telefono<<setw(10)<<monto_total << "Productos entregados: "<<endl;
    if (cantidad_productos_entregados == 0) output << "NO SE LE ENTREGARON PRODUCTOS";
    else for (int i = 0; i < cantidad_productos_entregados; i++) {
            productos_entregados[i].GetCodigo(cod);
            output << cod << " ";
        }
    output << endl;


}
bool operator >> (ifstream &input,Cliente &c){
    c.Leer(input);
    if(input.eof()) return false;
    return true;
  
}
void operator << (ofstream &output,Cliente &c){
    c.Mostrar(output);
}