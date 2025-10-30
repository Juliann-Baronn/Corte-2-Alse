#include "../include/Producto.h"
#include <iostream>
#include <iomanip>

using namespace std;

Producto::Producto(const string& nom, double prec, int stk)
    : nombre(nom), precio(prec), stock(stk) {}

string Producto::obtenerNombre() const {
    return nombre;
}

double Producto::obtenerPrecio() const {
    return precio;
}

int Producto::obtenerStock() const {
    return stock;
}

void Producto::establecerStock(int nuevoStock) {
    stock = nuevoStock;
}

bool Producto::tieneStock(int cantidad) const {
    return stock >= cantidad;
}

void Producto::reducirStock(int cantidad) {
    if (tieneStock(cantidad)) {
        stock -= cantidad;
    }
}

void Producto::aumentarStock(int cantidad) {
    stock += cantidad;
}

void Producto::mostrarInfo() const {
    cout << "Producto: " << nombre 
         << " | Precio: $" << fixed << setprecision(2) << precio 
         << " | Stock: " << stock << endl;
}
