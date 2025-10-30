#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    int stock;

public:
    // Constructor
    Producto(const std::string& nom, double prec, int stk);
    
    // Getters
    std::string obtenerNombre() const;
    double obtenerPrecio() const;
    int obtenerStock() const;
    
    // Setters
    void establecerStock(int nuevoStock);
    
    // Métodos
    bool tieneStock(int cantidad) const;
    void reducirStock(int cantidad);
    void aumentarStock(int cantidad);
    void mostrarInfo() const;
};

#endif