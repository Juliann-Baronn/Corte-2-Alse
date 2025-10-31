#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombreArticulo;
    float precioUnitario;
    int cantidadDisponible;
    int porcentajeDescuento;

public:
    // Constructor que recibe todos los atributos
    Producto(std::string articulo, float valorUnitario, int unidades, int desc);
    
    // Método que cambia el precio
    void actualizarPrecio(float nuevoValor);
    
    // Método que muestra todas las características
    void mostrarResumen() const;
    
    // Método que vende productos y retorna el valor
    float realizarVenta(int unidadesSolicitadas);
    
    // Método que incrementa el stock
    int agregarInventario(int unidadesNuevas);
    
    // Método que devuelve el valor total del inventario
    float obtenerValorTotal() const;
};

#endif