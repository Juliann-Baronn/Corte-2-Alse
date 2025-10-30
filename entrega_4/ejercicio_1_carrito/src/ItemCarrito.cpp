#include "../include/ItemCarrito.h"
#include <iostream>
#include <iomanip>

using namespace std;

ItemCarrito::ItemCarrito(shared_ptr<Producto> prod, int cant)
    : producto(prod), cantidad(cant) {}

shared_ptr<Producto> ItemCarrito::obtenerProducto() const {
    return producto;
}

int ItemCarrito::obtenerCantidad() const {
    return cantidad;
}

void ItemCarrito::establecerCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
}

void ItemCarrito::aumentarCantidad(int cant) {
    cantidad += cant;
}

void ItemCarrito::reducirCantidad(int cant) {
    if (cantidad >= cant) {
        cantidad -= cant;
    }
}

double ItemCarrito::calcularSubtotal() const {
    return producto->obtenerPrecio() * cantidad;
}

void ItemCarrito::mostrarInfo() const {
    cout << producto->obtenerNombre() 
         << " x" << cantidad 
         << " = $" << fixed << setprecision(2) << calcularSubtotal() << endl;
}