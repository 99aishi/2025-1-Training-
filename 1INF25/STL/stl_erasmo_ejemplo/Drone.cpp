//
// Created by Erasmo on 24/06/25.
//

#include "Drone.hpp"

Drone::Drone() {}

Drone::~Drone() {

}

int Drone::getId() const {
    return id;
}

void Drone::setId(int id) {
    this->id = id;
}

const string &Drone::getZona() const {
    return zona;
}

void Drone::setZona(const char *zona) {
    this->zona = zona;
}

const string &Drone::getTipo() const {
    return tipo;
}

void Drone::setTipo(const char *tipo) {
    this->tipo = tipo;
}

Drone::Drone(int id, const string &zona, const char *tipo) {
    this->id = id;
    this->zona = zona;
    this->tipo = tipo;
}
