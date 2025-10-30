#ifndef USUARIO_H
#define USUARIO_H

#include "CarritoCompras.h"
#include <string>
#include <vector>

struct Compra {
    std::vector<ItemCarrito> items;
    double total;
    std::string fecha;
    
    Compra(const std::vector<ItemCarrito>& itms, double tot, const std::string& fch)
        : items(itms), total(tot), fecha(fch) {}
};

class Usuario {
private:
    std::string nombre;
    std::string correo;
    std::vector<Compra> historialCompras;

public:
    // Constructor
    Usuario(const std::string& nom, const std::string& email);
    
    // Getters
    std::string obtenerNombre() const;
    std::string obtenerCorreo() const;
    
    // Realizar compra (guarda en historial y reduce stock)
    bool realizarCompra(CarritoCompras& carrito);
    
    // Mostrar historial de compras
    void mostrarHistorial() const;
    
    // Obtener total gastado
    double obtenerTotalGastado() const;
};

#endif