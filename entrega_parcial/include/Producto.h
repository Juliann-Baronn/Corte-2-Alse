/**
 * @file Producto.h
 * @brief Declaración de la clase Producto para la gestión de inventarios y ventas.
 * 
 * Esta clase representa un producto con información sobre su nombre, precio, 
 * cantidad disponible y descuento. Permite actualizar precios, vender unidades, 
 * aumentar el inventario y calcular el valor total.
 * 
 * @author Julian
 * @date 2025-10-31
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

/**
 * @class Producto
 * @brief Clase que gestiona la información y operaciones de un producto.
 */
class Producto {
private:
    std::string nombreArticulo;      ///< Nombre del artículo
    float precioUnitario;            ///< Precio unitario del producto
    int cantidadDisponible;          ///< Cantidad disponible en inventario
    int porcentajeDescuento;         ///< Porcentaje de descuento aplicado

public:
    /**
     * @brief Constructor que inicializa todos los atributos del producto.
     * @param articulo Nombre del producto.
     * @param valorUnitario Precio unitario del producto.
     * @param unidades Cantidad disponible en inventario.
     * @param desc Porcentaje de descuento aplicado.
     */
    Producto(std::string articulo, float valorUnitario, int unidades, int desc);
    
    /**
     * @brief Actualiza el precio del producto.
     * @param nuevoValor Nuevo valor a asignar como precio unitario.
     */
    void actualizarPrecio(float nuevoValor);
    
    /**
     * @brief Muestra todas las características del producto.
     */
    void mostrarResumen() const;
    
    /**
     * @brief Realiza una venta de cierta cantidad de unidades.
     * 
     * Reduce el inventario y calcula el total de la venta aplicando el descuento correspondiente.
     * 
     * @param unidadesSolicitadas Número de unidades a vender.
     * @return Valor total de la venta.
     */
    float realizarVenta(int unidadesSolicitadas);
    
    /**
     * @brief Incrementa el stock del producto.
     * @param unidadesNuevas Cantidad de unidades nuevas a agregar.
     * @return Nueva cantidad total disponible en inventario.
     */
    int agregarInventario(int unidadesNuevas);
    
    /**
     * @brief Calcula el valor total del inventario disponible.
     * @return Valor total del inventario considerando el descuento.
     */
    float obtenerValorTotal() const;
};

#endif
