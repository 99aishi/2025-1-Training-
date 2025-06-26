//
// Created by Erasmo on 24/06/25.
//

#include "Ministerio.hpp"

void Ministerio::leer_zonas() {
    ifstream input("zonas.csv", ios::in);
    char zona_buffer[20];
    while (true) {
        input.getline(zona_buffer, 20, '\n');
        if (input.eof())break;
        ZonaControl zona;
        zona.setNombre(zona_buffer);
        this->zonas.push_back(zona);
    }
    zonas.sort();
    cout<<"Lista de Zonas Ordenadas Alfabeticamente:"<<endl;
    for (auto z: zonas)
        cout <<setw(15)<<z.getNombre();
    cout<<endl;
    cout<<"##################################################################"<<endl;
}

void Ministerio::leer_drones() {
    ifstream input("drones.csv", ios::in);
    int id_drone;
    char zona_drone[20], tipo_drone[20];
    while (true) {
        input >> id_drone;
        if (input.eof())break;
        input.get();
        input.getline(zona_drone, 20, ',');
        input.getline(tipo_drone, 20, '\n');
        Drone drone;
        drone.setId(id_drone);
        drone.setTipo(tipo_drone);
        // Buscar la zona en la lista
        for (auto &zona: zonas) {
            if (zona.getNombre() == zona_drone) {
                zona.agregar_drone(drone);
                break;
            }
        }
    }
    cout<<"Lista de Drones x Zona"<<endl;
    for(auto z :zonas){
        z.imprimir();
    }
    cout<<"##################################################################"<<endl;
}

void Ministerio::leer_eventos_lima() {
    for (auto &zona: zonas) {
        if (zona.getNombre() == "Lima") {
            zona.leer_eventos();
            break;
        }
    }
}

void Ministerio::borrar_eventos_fecha_lima(int fecha_corte){
    for (auto &zona: zonas) {
        if (zona.getNombre() == "Lima") {
            zona.borrar_eventos(fecha_corte);
            break;
        }
    }
}