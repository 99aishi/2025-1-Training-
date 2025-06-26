#include "Ministerio.hpp"

int main() {
    Ministerio ministerio;
    ministerio.leer_zonas();
    ministerio.leer_drones();
    ministerio.leer_eventos_lima();
    ministerio.borrar_eventos_fecha_lima(20250312);
    return 0;
}
