#include "../include/Usuario.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
    // Crear productos
    auto laptop = make_shared<Producto>("Laptop HP", 1200.00, 5);
    auto raton = make_shared<Producto>("Raton Logitech", 25.50, 20);
    auto teclado = make_shared<Producto>("Teclado Mecanico", 75.00, 15);
    auto monitor = make_shared<Producto>("Monitor 24\"", 200.00, 8);
    auto audifonos = make_shared<Producto>("Audifonos Sony", 150.00, 10);
    
    cout << "===== PRODUCTOS DISPONIBLES =====" << endl;
    laptop->mostrarInfo();
    raton->mostrarInfo();
    teclado->mostrarInfo();
    monitor->mostrarInfo();
    audifonos->mostrarInfo();
    cout << "==================================\n" << endl;
    
    // Crear usuario
    Usuario usuario1("Juan Perez", "juan.perez@email.com");
    
    // Crear carrito
    CarritoCompras carrito;
    
    // Agregar productos al carrito
    cout << "--- Agregando productos al carrito ---" << endl;
    carrito.agregarProducto(laptop, 1);
    carrito.agregarProducto(raton, 2);
    carrito.agregarProducto(teclado, 1);
    cout << endl;
    
    // Mostrar carrito
    carrito.mostrarCarrito();
    
    // Realizar primera compra
    cout << "--- Realizando primera compra ---" << endl;
    usuario1.realizarCompra(carrito);
    
    // Nueva compra
    cout << "\n--- Segunda compra ---" << endl;
    carrito.agregarProducto(monitor, 2);
    carrito.agregarProducto(audifonos, 1);
    carrito.mostrarCarrito();
    usuario1.realizarCompra(carrito);
    
    // Mostrar historial
    usuario1.mostrarHistorial();
    
    // Mostrar stock actualizado
    cout << "\n===== STOCK ACTUALIZADO =====" << endl;
    laptop->mostrarInfo();
    raton->mostrarInfo();
    teclado->mostrarInfo();
    monitor->mostrarInfo();
    audifonos->mostrarInfo();
    cout << "=============================\n" << endl;
    
    return 0;
}