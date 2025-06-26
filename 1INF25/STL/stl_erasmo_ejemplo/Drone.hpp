//
// Created by Erasmo on 24/06/25.
//

#ifndef STL_DRONE_HPP
#define STL_DRONE_HPP

#include "Evento.hpp"

class Drone {
private:
    int id;
    string zona;
    string tipo;
public:
    virtual ~Drone();

    Drone();

    int getId() const;

    void setId(int id);

    const string &getZona() const;

    void setZona(const char *zona);

    const string &getTipo() const;

    void setTipo(const char *tipo);

    Drone(int id, const string &zona, const char *tipo);

};


#endif //STL_DRONE_HPP
