/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: 999
 * 
 * Created on June 3, 2025, 12:59 PM
 */

#include "Estante.hpp"

Estante::Estante() {
    espacios=nullptr;
    codigo=nullptr;
    cantidad_libros=0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    this->codigo=new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Estante::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Estante::Leer(ifstream &in){
    char c,cod[8];
    in.getline(cod,8,',');
    in >> anchura >> c>>altura;
    SetCodigo(cod);
    in.get();
    espacios= new Espacio[anchura*altura]{};
}
void operator >> (ifstream &in, Estante &e){
    e.Leer(in);
}
int Estante::calcular_ancho_ocupado(){
    int ocupado=0;
    for (int i=0; i < anchura; i++) {
        if(espacios[(altura-1)*anchura +i ].GetContenido() != ' ') ocupado++;
    }
//    for (int i = 0; i < cantidad_libros; i++) {
//        ocupado+= libros[i].GetAncho();
//    }

    return ocupado;

    
}
void Estante::colocar_libro(Libro &libro, int ancho_ocupado){
    int alto_libro=libro.GetAlto(), ancho_libro=libro.GetAncho();
    for (int i = altura-1; i > (altura-alto_libro)-1; i--) {
        for (int k = ancho_ocupado; k < (ancho_ocupado+ancho_libro); k++) {
            espacios[i*anchura+k].SetContenido('*');
            espacios[i*anchura+k].SetPosX(i);
            espacios[i*anchura+k].SetPosY(k);
        }
    }
    
    libro.SetColocado(true);
    libros[cantidad_libros]=libro;
    cantidad_libros++;
}
bool Estante::operator += (Libro &libro){
    int alto_libro=libro.GetAlto(), ancho_libro=libro.GetAncho();
    int ancho_ocupado=calcular_ancho_ocupado();
    if(alto_libro<=altura and ancho_libro<=(anchura-ancho_ocupado)/*ancho ocupado*/){
        colocar_libro(libro, ancho_ocupado);
        return true;
    }else
        return false;
}
void Estante::imprime_linea(ofstream &out,int size,char car){
    out << setfill(car)<<setw(size)<<" ";
    out<<setfill(' ')<<endl;
}
void Estante::Mostrar(ofstream &out){
    char cod[5];
    GetCodigo(cod);
    out << "Codigo Estante: "<< cod << "Cantidad de Libros: "<< cantidad_libros<<endl;
    out << "Anchura del Estante: "<< anchura << "Altura del Estante: "<< altura<<endl;
    imprime_linea(out,50,'-');
    
    for (int i = 0; i < altura; i++) {
        for (int k = 0; k < anchura; k++) {
            out << espacios[i*anchura+k];
        }
        out << endl;
    }
    for (int i = 0; i < cantidad_libros; i++) {
        out<<libros[i];
    }
}
void operator << (ofstream &out,Estante &e){
    e.Mostrar(out);
}