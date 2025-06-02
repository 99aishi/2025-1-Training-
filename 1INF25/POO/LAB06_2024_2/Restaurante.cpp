/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Restaurante.cpp
 * Author: 999
 * 
 * Created on June 2, 2025, 11:59 AM
 */

#include "Restaurante.hpp"

Restaurante::Restaurante() {
    platos=nullptr;
    clientes=nullptr;
    cantidad_clientes=0;
    cantidad_platos=0;
    capacidad_clientes=0;
    capacidad_platos=0;
}

Restaurante::Restaurante(const Restaurante& orig) {
}

Restaurante::~Restaurante() {
}

void Restaurante::SetCapacidad_platos(int capacidad_platos) {
    this->capacidad_platos = capacidad_platos;
}

int Restaurante::GetCapacidad_platos() const {
    return capacidad_platos;
}

void Restaurante::SetCantidad_platos(int cantidad_platos) {
    this->cantidad_platos = cantidad_platos;
}

int Restaurante::GetCantidad_platos() const {
    return cantidad_platos;
}

void Restaurante::SetCapacidad_clientes(int capacidad_clientes) {
    this->capacidad_clientes = capacidad_clientes;
}

int Restaurante::GetCapacidad_clientes() const {
    return capacidad_clientes;
}

void Restaurante::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Restaurante::GetCantidad_clientes() const {
    return cantidad_clientes;
}
void Restaurante::aumentar_capacidad_clientes(){
    capacidad_clientes+=INCREMENTO;
    Cliente *aux;
    if(clientes==nullptr){
        clientes=new Cliente[capacidad_clientes]{};
        cantidad_clientes=0;
    }else{
        aux=new Cliente[capacidad_clientes]{};
        for (int i = 0; i < cantidad_clientes; i++) {
            aux[i]=clientes[i];
        }
        delete clientes;
        clientes=aux;
    }
}
void Restaurante::cargar_clientes(ifstream &input){
    
    while(true){
        Cliente cliente;
        input >> cliente;
        if(input.eof()) break;
        if(cantidad_clientes==capacidad_clientes)
            aumentar_capacidad_clientes();
        clientes[cantidad_clientes]=cliente;
        cantidad_clientes++;
    }        
//    clientes[cantidad_clientes]=nullptr;
}

void Restaurante::aumentar_capacidad_platos(){
    capacidad_platos+=INCREMENTO;
    Plato *aux;
    if(platos==nullptr){
        platos=new Plato[capacidad_platos]{};
        cantidad_platos=1;
    }else{
        aux=new Plato[capacidad_platos]{};
        for (int i = 0; i < cantidad_platos; i++) {
            aux[i]=platos[i];
        }
        delete platos;
        platos=aux;
    }
}
void Restaurante::cargar_platos(ifstream &input){
    while(true){
        Plato plato;
        input >> plato;
        if(input.eof()) break;
        if(cantidad_platos==capacidad_platos)
            aumentar_capacidad_platos();
        platos[cantidad_platos-1]=plato;
        cantidad_platos++;
    }
}


void Restaurante::mostrar_platos(ofstream &output){
    for (int i = 0; i < cantidad_platos; i++) {
        output<<platos[i];
    }

}

void Restaurante::mostar_clientes(ofstream &output){
    for (int i = 0; i < cantidad_clientes; i++) {
        output<<clientes[i];
    }

}
void Restaurante::imprime_linea(ofstream &output,int size, char car){
    output<< setfill(car)<<setw(size)<<" ";
    output<<setfill(' ')<<endl;
}
void Restaurante::operator >>(const char *nombre_archivo){
    ofstream output(nombre_archivo,ios::out);
    mostrar_platos(output);
    imprime_linea(output,120,'=');
    mostar_clientes(output);
}
    
void Restaurante::operator <<=(const char *nombre_archivo){
    ifstream input(nombre_archivo,ios::in);
    int pedido,dni,cantidad,pos_cliente,pos_plato;
    char c;
    while(true){
        input >> pedido>>c>>dni;
        if(input.eof()) break;
        pos_cliente=buscar_dni(dni);
        if(pos_cliente!= -1){
            cout <<"encontrado "<<buscar_dni(dni)<<endl;
            while(input.get()!='\n'){
                double total=clientes[pos_cliente].GetTotalPagado();
                char plato_cod[10];
                input.getline(plato_cod,10,',');
                input >> cantidad;
                pos_plato=buscar_plato(plato_cod);
                if(pos_plato!=-1){
                    double neto = platos[pos_plato].GetTotalNeto();
                    int acum=platos[pos_plato].GetAtendidos();
                    if(acum+cantidad<=platos[pos_plato].GetPreparados()){
                        acum+=cantidad;
                        platos[pos_plato].SetAtendidos(acum);
                        total+=cantidad*(platos[pos_plato].GetPrecio()) * (1-clientes[pos_cliente].GetDescuento()/100);
                        clientes[pos_cliente].SetTotalPagado(total);
                        
                        neto+= cantidad * (platos[pos_plato].GetPrecio()) *(1-platos[pos_plato].GetDescuento()/100) * (1-clientes[pos_cliente].GetDescuento()/100);
                        platos[pos_plato].SetTotalNeto(neto);
                        
                    }else{
                        int no_aten=platos[pos_plato].GetNoAtendidos();
                        no_aten+=cantidad;
                        platos[pos_plato].SetNoAtendidos(no_aten);
                    }
                    
                    double esperado=platos[pos_plato].GetTotalEsperado();
                    esperado=platos[pos_plato].GetPreparados() * platos[pos_plato].GetPrecio();
                    platos[pos_plato].SetTotalEsperado(esperado);
                    double bruto=platos[pos_plato].GetTotalBruto();
                    bruto=platos[pos_plato].GetAtendidos() * platos[pos_plato].GetPrecio();
                    platos[pos_plato].SetTotalBruto(bruto);
                }
            }
        }
//        while(input.get()!='\n');
    }
    
}
int Restaurante::buscar_plato(char *codigo){
    char aux_cod[10];
    for (int i = 0; i < cantidad_platos; i++) {
        platos[i].GetCodigo(aux_cod);
        if(strcmp(codigo,aux_cod)==0) return i; 
    }
    return -1;

}
int Restaurante::buscar_dni(int dni){
    for (int i = 0; i < cantidad_clientes; i++) {
        
        if(clientes[i].GetDni()==dni)
            return i;
    }
    return -1;
}
void Restaurante::operator < (const char * nombre_archivo){
    ifstream input(nombre_archivo,ios::in);
    cargar_clientes(input);
}
void Restaurante::operator <=(const char *nombre_archivo){
    ifstream input(nombre_archivo,ios::in);
    cargar_platos(input);
}