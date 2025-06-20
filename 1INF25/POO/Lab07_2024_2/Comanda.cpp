/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Comanda.cpp
 * Author: 999
 * 
 * Created on June 6, 2025, 12:25 AM
 */

#include "Comanda.hpp"

Comanda::Comanda() {
    estado=nullptr;
    tiempo_preparacion=0;
}

Comanda::Comanda(const Comanda& orig) {
}

Comanda::~Comanda() {
}

void Comanda::SetEstado(const char* estado) {
    if(this->estado!=nullptr) delete this->estado;
    this->estado=new char[strlen(estado)+1];
    strcpy(this->estado,estado);
}
void Comanda::GetEstado(char *estado) const {
    if(this->estado==nullptr) estado[0]=0;
    else strcpy(estado,this->estado);
}

void Comanda::SetTotal(double total) {
    this->total = total;
}

double Comanda::GetTotal() const {
    return total;
}

void Comanda::SetTiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

int Comanda::GetTiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::SetHora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::GetHora_servicio() const {
    return hora_servicio;
}

void Comanda::SetHora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::GetHora_atencion() const {
    return hora_atencion;
}

void Comanda::SetCantidad_platos_fondo(int cantidad_platos_fondo) {
    this->cantidad_platos_fondo = cantidad_platos_fondo;
}

int Comanda::GetCantidad_platos_fondo() const {
    return cantidad_platos_fondo;
}

void Comanda::SetCantidad_entradas(int cantidad_entradas) {
    this->cantidad_entradas = cantidad_entradas;
}

int Comanda::GetCantidad_entradas() const {
    return cantidad_entradas;
}

void Comanda::SetCantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::GetCantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::SetId(int id) {
    this->id = id;
}

int Comanda::GetId() const {
    return id;
}

void Comanda::leer_bebida(ifstream &input) {

    
    bebidas[cantidad_bebidas].Leer(input);
    cantidad_bebidas++;
    
}

void Comanda::leer_platofondo(ifstream &input) {
    int prote[4]{}, i = 0;
    PlatoFondo prod;
    prod.Leer(input);
    while (1) {
        input >> prote[i];
        if (input.get() == '\n') break;
        i++;
    }
    prod.insertar_proteina(prote);
    platos_fondo[cantidad_platos_fondo]=prod;
    cantidad_platos_fondo++;
}

void Comanda::leer_entrada(ifstream &input) {
    char pica[20];
    Entrada prod;
    prod.Leer(input);
    input.getline(pica, 20, '\n');
    if (strcmp(pica, "picante") == 0) prod.SetPicante(true);
    entradas[cantidad_entradas]=prod;
    cantidad_entradas++;
}

int Comanda::Leer(ifstream &input, int &bandera){
    char c,tipo;
    int sig_id;
    SetId(bandera);
    while (true) {
        input >> c>> tipo>>c;
        if (tipo == 'B')
            leer_bebida(input);
//        Bebida bebida;
//        bebida.leer();
        if (tipo == 'E')
            leer_entrada(input);
        if (tipo == 'P')
            leer_platofondo(input);
        input >> sig_id;
        if(sig_id != bandera or input.eof()) return sig_id;
    }

}
void Comanda::imprimir_bebida(ofstream &output){
    
    if(cantidad_bebidas !=0){
    
        output <<setw(5)<<" "<< "Bebidas pedidas: "<< endl;
        for (int i = 0; i < cantidad_bebidas; i++) {
            char tam[20];
            bebidas[i].GetTamano(tam);
            bebidas[i].mostrar(output);
            output << setw(9)<<"Tamano: "<< tam << endl;
            total+= bebidas[i].GetPrecio();
        }

    }
}
void Comanda::imprimir_entrada(ofstream &output) {
    if (cantidad_entradas != 0) {

        output <<setw(5)<<" "<< "Entradas pedidas: " << endl;
        for (int i = 0; i < cantidad_entradas; i++) {
            entradas[i].mostrar(output);
            output << setw(12) << "Picante: ";
            if (entradas[i].IsPicante() == true) output << "Si" << endl;
            else output << "No" << endl;
            total += entradas[i].GetPrecio();
        }

    }
}

void Comanda::imprimir_pfondo(ofstream &output) {
    if (cantidad_platos_fondo != 0) {

        output << setw(5)<<" "<<"Platos de Fondo pedidos: " << endl;
        for (int i = 0; i < cantidad_platos_fondo; i++) {
            platos_fondo[i].mostrar(output);
            total += platos_fondo[i].GetPrecio();
            platos_fondo[i].imprimir_proteinas(output);
            output<<endl;
        }
    }
}
void Comanda::imprimir_horas(ofstream &output){
    int h,m;
    h=hora_atencion/60;
    m=hora_atencion%60;
    output << "ATENCION: " << right<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<setfill(' ')<<setw(6)<<" ";
    h=hora_servicio/60;
    m=hora_servicio%60;
    output << "SERVICIO: " << right<<setfill('0')<<setw(2)<<h<<":"<<setw(2)<<m<<setfill(' ');
    output<<endl;
}
void Comanda::Mostrar(ofstream &output){
    
    output <<left<<setw(18)<<"CODIGO DE COMANDA: "<<setw(5)<< id;
    imprimir_horas(output);
//    << hora_atencion << hora_servicio << endl;
    imprimir_bebida(output);
    imprimir_entrada(output);
    imprimir_pfondo(output);
    output << "TOTAL RECAUDADO EN LA COMANDA :"<<total<<endl<<endl;
}


void operator << (ofstream &output, Comanda &c){
    c.Mostrar(output);
}
void Comanda::calcular_estimado(){
   if(cantidad_bebidas!=0) tiempo_preparacion +=10;
   if(cantidad_entradas!=0) tiempo_preparacion +=15;
   if(cantidad_platos_fondo!=0) tiempo_preparacion +=20;
}
void Comanda::actualizar_comandas(ifstream &input){
    int tiempo_atencion,h,m;
    char c;
    input >>h>>c>>m;
    hora_atencion=h*60+m;
    input>>c>>h>>c>>m;
    hora_servicio=h*60+m;
    
    tiempo_atencion=hora_servicio - hora_atencion;
    calcular_estimado();
    if(tiempo_atencion<tiempo_preparacion){
        SetEstado("ATENDIDO");
    }else{
        SetEstado("ATENDIDO CON RETRASO");
    }
}