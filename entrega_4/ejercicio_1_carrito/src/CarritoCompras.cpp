#include "../include/CarritoCompras.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool CarritoCompras::agregarProducto(shared_ptr<Producto> producto, int cantidad) {
    // Verificar si hay stock suficiente
    if (!producto->tieneStock(cantidad)) {
        cout << "Error: Stock insuficiente para " << producto->obtenerNombre() << endl;
        return false;
    }
    
    // Buscar si el producto ya está en el carrito
    for (auto& item : items) {
        if (item.obtenerProducto()->obtenerNombre() == producto->obtenerNombre()) {
            // Si ya existe, aumentar la cantidad
            if (producto->tieneStock(item.obtenerCantidad() + cantidad)) {
                item.aumentarCantidad(cantidad);
                cout << "Cantidad actualizada en el carrito." << endl;
                return true;
            } else {
                cout << "Error: Stock insuficiente para agregar mas unidades." << endl;
                return false;
            }
        }
    }
    
    // Si no existe, agregar nuevo item
    items.push_back(ItemCarrito(producto, cantidad));
    cout << "Producto agregado al carrito exitosamente." << endl;
    return true;
}

bool CarritoCompras::eliminarProducto(const string& nombreProducto) {
    auto iterador = remove_if(items.begin(), items.end(),
        [&nombreProducto](const ItemCarrito& item) {
            return item.obtenerProducto()->obtenerNombre() == nombreProducto;
        });
    
    if (iterador != items.end()) {
        items.erase(iterador, items.end());
        cout << "Producto eliminado del carrito." << endl;
        return true;
    }
    
    cout << "Producto no encontrado en el carrito." << endl;
    return false;
}

double CarritoCompras::calcularTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.calcularSubtotal();
    }
    return total;
}

void CarritoCompras::mostrarCarrito() const {
    if (items.empty()) {
        cout << "El carrito esta vacio." << endl;
        return;
    }
    
    cout << "\n===== CARRITO DE COMPRAS =====" << endl;
    for (const auto& item : items) {
        item.mostrarInfo();
    }
    cout << "------------------------------" << endl;
    cout << "TOTAL: $" << fixed << setprecision(2) << calcularTotal() << endl;
    cout << "==============================\n" << endl;
}

void CarritoCompras::vaciarCarrito() {
    items.clear();
}

bool CarritoCompras::estaVacio() const {
    return items.empty();
}

vector<ItemCarrito> CarritoCompras::obtenerItems() const {
    return items;
}
