#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "Producto.h"
#include <memory>

class ItemCarrito {
private:
    std::shared_ptr<Producto> producto;
    int cantidad;

public:
    // Constructor
    ItemCarrito(std::shared_ptr<Producto> prod, int cant);
    
    // Getters
    std::shared_ptr<Producto> obtenerProducto() const;
    int obtenerCantidad() const;
    
    // Setters
    void establecerCantidad(int nuevaCantidad);
    
    // Métodos
    void aumentarCantidad(int cant);
    void reducirCantidad(int cant);
    double calcularSubtotal() const;
    void mostrarInfo() const;
};

#endif
