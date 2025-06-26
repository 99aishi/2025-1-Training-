//
// Created by Erasmo on 24/06/25.
//

#ifndef STL_EVENTO_HPP
#define STL_EVENTO_HPP

#include "Utils.hpp"

class Evento {
private:
    int fecha;
    string descripcion;
public:
    Evento();

    Evento(int fecha, const char *descripcion);

    Evento(const Evento &e);

    virtual ~Evento();

    int getFecha() const;

    void setFecha(int fecha);

    const string &getDescripcion() const;

    void setDescripcion(const char *descripcion);

    bool operator<(const Evento& otra) const;

    Evento& operator=(const Evento& otra);

};


#endif //STL_EVENTO_HPP
