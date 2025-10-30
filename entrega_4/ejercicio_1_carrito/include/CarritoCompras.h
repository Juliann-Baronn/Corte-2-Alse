#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include "ItemCarrito.h"
#include <vector>
#include <memory>

class CarritoCompras {
private:
    std::vector<ItemCarrito> items;

public:
    // Agregar producto al carrito
    bool agregarProducto(std::shared_ptr<Producto> producto, int cantidad);
    
    // Eliminar producto del carrito por nombre
    bool eliminarProducto(const std::string& nombreProducto);
    
    // Calcular el total de la compra
    double calcularTotal() const;
    
    // Mostrar contenido del carrito
    void mostrarCarrito() const;
    
    // Vaciar el carrito
    void vaciarCarrito();
    
    // Verificar si el carrito está vacío
    bool estaVacio() const;
    
    // Obtener items (para historial)
    std::vector<ItemCarrito> obtenerItems() const;
};

#endif
