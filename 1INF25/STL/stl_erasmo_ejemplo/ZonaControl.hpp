//
// Created by Erasmo on 24/06/25.
//

#ifndef STL_ZONACONTROL_HPP
#define STL_ZONACONTROL_HPP

#include "Drone.hpp"

class ZonaControl {
private:
    string nombre;
    map<string, vector<Drone>> drones;
    vector<Evento> eventos;

public:
    ZonaControl();

    virtual ~ZonaControl();

    const string &getNombre() const;

    void setNombre(const char *nombre);

    bool operator<(const ZonaControl& otra) const;

    void agregar_drone(class Drone);

    void imprimir();

    void leer_eventos();

    void borrar_eventos(int);
};


#endif //STL_ZONACONTROL_HPP
