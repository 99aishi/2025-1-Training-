//
// Created by Erasmo on 24/06/25.
//

#include "ZonaControl.hpp"

ZonaControl::ZonaControl() {
}

ZonaControl::~ZonaControl() {

}

const string &ZonaControl::getNombre() const {
    return nombre;
}

void ZonaControl::setNombre(const char * nombre) {
    this->nombre = nombre;
}

bool ZonaControl::operator<(const ZonaControl& otra) const {
    return this->nombre < otra.nombre;
}

void ZonaControl::agregar_drone(class Drone d) {
    this->drones[this->nombre].push_back(d);
}

void ZonaControl::imprimir() {
    for(auto p: drones){
        cout<<"Zona: "<<p.first<<endl;
        for(auto d: p.second)
            cout<<setw(10)<<d.getId();
        cout<<endl;
    }

}

void ZonaControl::leer_eventos() {
    ifstream input("eventos.csv", ios::in);
    //123,Arequipa,Tipo1
    int id_drone, dd, mm, aa, _fecha;
    char c, buffer[20];
    while(true){
        input>>id_drone;
        if(input.eof())break;
        input.get();
        input>>dd>>c>>mm>>c>>aa;
        input.get();
        input.getline(buffer, 20, '\n');
        _fecha = aa*10000+mm*100+dd;
        Evento e(_fecha, buffer);
        eventos.push_back(e);
    }
    sort(eventos.begin(), eventos.end());
    cout<<"Lista de Eventos de Lima: Ordenados Por Fecha "<<endl;
    for(auto e:eventos){
        cout<<setw(10)<<e.getFecha()<<setw(20)<<e.getDescripcion();
    cout<<endl;
    }
    cout<<"##################################################################"<<endl;
}

void ZonaControl::borrar_eventos(int fecha_corte){
    int indice_cambio = 0;
    for(int i=0; i<eventos.size(); i++)
        if(eventos[i].getFecha()>fecha_corte) {
            indice_cambio = i;
            break;
        }
    vector<Evento>::iterator it1 = eventos.begin();
    vector<Evento>::iterator it2 = eventos.begin() + indice_cambio;
    eventos.erase(it1, it2);
    cout<<"Lista Fechas luego de eliminar"<<endl;
    for(auto e: eventos)
        cout<<setw(10)<<e.getFecha();
    cout<<endl;
}