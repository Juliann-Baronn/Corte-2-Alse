#include "../include/Producto.h"
#include <iostream>
#include <iomanip>

// Constructor
Producto::Producto(std::string articulo, float valorUnitario, int unidades, int desc)
    : nombreArticulo(articulo), precioUnitario(valorUnitario), 
      cantidadDisponible(unidades), porcentajeDescuento(desc) {}

// Actualizar el precio del producto
void Producto::actualizarPrecio(float nuevoValor) {
    precioUnitario = nuevoValor;
    std::cout << "Precio actualizado a: $" << std::fixed << std::setprecision(2) 
              << nuevoValor << std::endl;
}

// Mostrar resumen del producto
void Producto::mostrarResumen() const {
    float precioConDescuento = precioUnitario * (1 - porcentajeDescuento / 100.0f);
    
    std::cout << "\n=== RESUMEN DEL PRODUCTO ===" << std::endl;
    std::cout << "Nombre: " << nombreArticulo << std::endl;
    std::cout << "Precio unitario: $" << std::fixed << std::setprecision(2) 
              << precioUnitario << std::endl;
    std::cout << "Descuento: " << porcentajeDescuento << "%" << std::endl;
    std::cout << "Precio con descuento: $" << std::fixed << std::setprecision(2) 
              << precioConDescuento << std::endl;
    std::cout << "Stock disponible: " << cantidadDisponible << " unidades" << std::endl;
    std::cout << "Valor total inventario: $" << std::fixed << std::setprecision(2) 
              << obtenerValorTotal() << std::endl;
    std::cout << "===========================\n" << std::endl;
}

// Realizar venta de productos
float Producto::realizarVenta(int unidadesSolicitadas) {
    if (unidadesSolicitadas <= 0) {
        std::cout << "Error: La cantidad debe ser mayor a 0" << std::endl;
        return 0.0f;
    }
    
    if (unidadesSolicitadas > cantidadDisponible) {
        std::cout << "Error: Stock insuficiente. Solo hay " << cantidadDisponible 
                  << " unidades disponibles" << std::endl;
        return 0.0f;
    }
    
    // Calcular precio con descuento
    float precioConDescuento = precioUnitario * (1 - porcentajeDescuento / 100.0f);
    float totalVenta = precioConDescuento * unidadesSolicitadas;
    
    // Reducir stock
    cantidadDisponible -= unidadesSolicitadas;
    
    std::cout << "Venta realizada: " << unidadesSolicitadas << " x " << nombreArticulo 
              << " = $" << std::fixed << std::setprecision(2) << totalVenta << std::endl;
    std::cout << "Stock restante: " << cantidadDisponible << " unidades" << std::endl;
    
    return totalVenta;
}

// Reabastecer inventario
int Producto::agregarInventario(int unidadesNuevas) {
    if (unidadesNuevas <= 0) {
        std::cout << "Error: La cantidad debe ser mayor a 0" << std::endl;
        return cantidadDisponible;
    }
    
    cantidadDisponible += unidadesNuevas;
    std::cout << "Inventario reabastecido: +" << unidadesNuevas << " unidades. "
              << "Stock actual: " << cantidadDisponible << std::endl;
    
    return cantidadDisponible;
}

// Obtener valor total del inventario
float Producto::obtenerValorTotal() const {
    float precioConDescuento = precioUnitario * (1 - porcentajeDescuento / 100.0f);
    return precioConDescuento * cantidadDisponible;
}