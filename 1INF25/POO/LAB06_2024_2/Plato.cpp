/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Plato.cpp
 * Author: 999
 * 
 * Created on June 2, 2025, 11:23 AM
 */

#include "Plato.hpp"

Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    categoria=nullptr;
    totalBruto=0;
    totalEsperado=0;
    totalNeto=0;
    preparados=0;
    atendidos=0;
    noAtendidos=0;
}

Plato::Plato(const Plato& orig) {
    
//    codigo=new char[strlen(orig.codigo)+1];
//    strcpy(codigo,orig.codigo);
//    nombre=new char[strlen(orig.nombre)+1];
//    strcpy(nombre,orig.nombre);
//    categoria=new char[strlen(orig.categoria)+1];
//    strcpy(categoria,orig.categoria);
//    
//    totalBruto=orig.totalBruto;
//    totalEsperado=orig.totalEsperado;
//    totalNeto=orig.totalNeto;
//    preparados=orig.preparados;
//    atendidos=orig.atendidos;
//    noAtendidos=orig.noAtendidos;
}
//void Plato::operator =(const Plato &orig){
    
//    if(this != &orig){
//        delete[] codigo;
//        delete[] nombre;
//        delete[] categoria;
//        
//        codigo=new char[strlen(orig.codigo)+1];
//        strcpy(codigo,orig.codigo);
//        nombre=new char[strlen(orig.nombre)+1];
//        strcpy(nombre,orig.nombre);
//        categoria=new char[strlen(orig.categoria)+1];
//        strcpy(categoria,orig.categoria);
//
//        totalBruto=orig.totalBruto;
//        totalEsperado=orig.totalEsperado;
//        totalNeto=orig.totalNeto;
//        preparados=orig.preparados;
//        atendidos=orig.atendidos;
//        noAtendidos=orig.noAtendidos;
//    }

//}
Plato::~Plato() {
}

void Plato::SetTotalNeto(double totalNeto) {
    this->totalNeto = totalNeto;
}

double Plato::GetTotalNeto() const {
    return totalNeto;
}

void Plato::SetTotalBruto(double totalBruto) {
    this->totalBruto = totalBruto;
}

double Plato::GetTotalBruto() const {
    return totalBruto;
}

void Plato::SetTotalEsperado(double totalEsperado) {
    this->totalEsperado = totalEsperado;
}

double Plato::GetTotalEsperado() const {
    return totalEsperado;
}

void Plato::SetNoAtendidos(int noAtendidos) {
    this->noAtendidos = noAtendidos;
}

int Plato::GetNoAtendidos() const {
    return noAtendidos;
}

void Plato::SetAtendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::GetAtendidos() const {
    return atendidos;
}

void Plato::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Plato::GetDescuento() const {
    return descuento;
}

void Plato::SetPreparados(int preparados) {
    this->preparados = preparados;
}

int Plato::GetPreparados() const {
    return preparados;
}

void Plato::SetCategoria(const char* categoria) {
    if(this->categoria!=nullptr) delete this->categoria;
    this->categoria=new char[strlen(categoria)+1];
    strcpy(this->categoria,categoria);
}

void Plato::GetCategoria(char *categoria) const {
    if(this->categoria==nullptr) categoria[0]=0;
    else strcpy(categoria,this->categoria);
}

void Plato::SetPrecio(double precio) {
    this->precio = precio;
}

double Plato::GetPrecio() const {
    return precio;
}

void Plato::SetNombre(const char* nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Plato::GetNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0]=0;
    else strcpy(nombre,this->nombre);
}

void Plato::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Plato::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Plato::leer(ifstream &input){
    char cod[10], nom[100],cate[30],c;
    input.getline(cod,10,',');
    input.getline(nom,100,',');
    input >> precio>>c;
    input.getline(cate,30,',');
    input >>preparados;
    if(input.get()!='\n'){
        input>>descuento>>c;
        input.get();
    }else descuento=0;
    SetNombre(nom);
    SetCodigo(cod);
    SetCategoria(cate);
}
void Plato::mostrar(ofstream &output){
    char cod[10],nom[80],cate[30], c='%';
    GetCodigo(cod);
    GetCategoria(cate);
    GetNombre(nom);
    output<<setprecision(2)<<fixed;
    output<<left<<setw(12)<<cod<<setw(50)<<nom<<setw(10)<<cate<<right<<setw(10)
            <<preparados<<setw(8)<<precio<<setw(10)<<descuento<<c<<setw(10)<<
            atendidos<<setw(10)<<noAtendidos<<setw(10)<<totalEsperado<<setw(10)<<totalBruto<<setw(10)<<
            totalNeto<<endl;
}
void operator >> (ifstream &input,Plato &plato){
    plato.leer(input);
}

void operator<<(ofstream &output, Plato &p) {
    p.mostrar(output);
}