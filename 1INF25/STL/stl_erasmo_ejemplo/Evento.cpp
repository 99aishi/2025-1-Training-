//
// Created by Erasmo on 24/06/25.
//

#include "Evento.hpp"

Evento::Evento() {}

Evento::~Evento() {}

Evento::Evento(const Evento &e) {
    *this = e;
}

Evento::Evento(int fecha, const char *descripcion) {
    this->fecha = fecha;
    this->descripcion = descripcion;
}

int Evento::getFecha() const {
    return fecha;
}

void Evento::setFecha(int fecha) {
    Evento::fecha = fecha;
}

const string &Evento::getDescripcion() const {
    return descripcion;
}

void Evento::setDescripcion(const char *descripcion) {
    Evento::descripcion = descripcion;
}

bool Evento::operator<(const Evento& otra) const {
    return this->fecha<otra.fecha;
}

Evento& Evento::operator=(const Evento& otra) {
    if (this != &otra) {
        this->fecha = otra.fecha;
        this->descripcion = otra.descripcion;
    }
    return *this;
}

