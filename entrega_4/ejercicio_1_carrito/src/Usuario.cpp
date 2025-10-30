#include "../include/Usuario.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

Usuario::Usuario(const string& nom, const string& email)
    : nombre(nom), correo(email) {}

string Usuario::obtenerNombre() const {
    return nombre;
}

string Usuario::obtenerCorreo() const {
    return correo;
}

bool Usuario::realizarCompra(CarritoCompras& carrito) {
    if (carrito.estaVacio()) {
        cout << "Error: El carrito esta vacio." << endl;
        return false;
    }
    
    // Verificar stock antes de procesar
    auto items = carrito.obtenerItems();
    for (const auto& item : items) {
        if (!item.obtenerProducto()->tieneStock(item.obtenerCantidad())) {
            cout << "Error: Stock insuficiente para " 
                 << item.obtenerProducto()->obtenerNombre() << endl;
            return false;
        }
    }
    
    // Reducir stock de productos
    for (const auto& item : items) {
        item.obtenerProducto()->reducirStock(item.obtenerCantidad());
    }
    
    // Obtener fecha actual
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);
    char fecha[20];
    strftime(fecha, sizeof(fecha), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    
    // Guardar en historial
    double total = carrito.calcularTotal();
    historialCompras.push_back(Compra(items, total, string(fecha)));
    
    cout << "\n¡Compra realizada exitosamente!" << endl;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
    
    // Vaciar carrito
    carrito.vaciarCarrito();
    
    return true;
}

void Usuario::mostrarHistorial() const {
    if (historialCompras.empty()) {
        cout << "No hay compras en el historial." << endl;
        return;
    }
    
    cout << "\n===== HISTORIAL DE COMPRAS =====" << endl;
    cout << "Usuario: " << nombre << " (" << correo << ")\n" << endl;
    
    int numeroCompra = 1;
    for (const auto& compra : historialCompras) {
        cout << "Compra #" << numeroCompra++ << " - " << compra.fecha << endl;
        cout << "Items:" << endl;
        for (const auto& item : compra.items) {
            cout << "  - ";
            item.mostrarInfo();
        }
        cout << "Total: $" << fixed << setprecision(2) << compra.total << endl;
        cout << "--------------------------------" << endl;
    }
    
    cout << "Total gastado: $" << fixed << setprecision(2) 
         << obtenerTotalGastado() << endl;
    cout << "================================\n" << endl;
}

double Usuario::obtenerTotalGastado() const {
    double total = 0.0;
    for (const auto& compra : historialCompras) {
        total += compra.total;
    }
    return total;
}