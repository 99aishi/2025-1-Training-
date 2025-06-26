//
// Created by Erasmo on 24/06/25.
//

#ifndef STL_MINISTERIO_HPP
#define STL_MINISTERIO_HPP
#include "ZonaControl.hpp"

class Ministerio {
private:
    list<ZonaControl> zonas;
public:
    void leer_zonas();
    void leer_drones();
    void leer_eventos_lima();
    void borrar_eventos_fecha_lima(int);
};


#endif //STL_MINISTERIO_HPP
