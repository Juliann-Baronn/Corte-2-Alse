#include "../include/Producto.h"
#include <iostream>

using namespace std;

int main() {
    string nom;
    float prec;
    int cant, desc;
    
    cout << "Nombre del producto: ";
    getline(cin, nom);
    cout << "Precio: ";
    cin >> prec;
    cout << "Cantidad: ";
    cin >> cant;
    cout << "Descuento (%): ";
    cin >> desc;
    
    Producto p(nom, prec, cant, desc);
    
    int op;
    
    while(true) {
        cout << "\n1. Ver info" << endl;
        cout << "2. Cambiar precio" << endl;
        cout << "3. Vender" << endl;
        cout << "4. Agregar stock" << endl;
        cout << "5. Ver valor total" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        
        if(op == 1) {
            p.mostrarResumen();
        }
        else if(op == 2) {
            float np;
            cout << "Nuevo precio: ";
            cin >> np;
            p.actualizarPrecio(np);
        }
        else if(op == 3) {
            int u;
            cout << "Cuantas unidades? ";
            cin >> u;
            p.realizarVenta(u);
        }
        else if(op == 4) {
            int u;
            cout << "Cuantas agregar? ";
            cin >> u;
            p.agregarInventario(u);
        }
        else if(op == 5) {
            cout << "Valor total: $" << p.obtenerValorTotal() << endl;
        }
        else if(op == 6) {
            cout << "Chao!" << endl;
            break;
        }
        else {
            cout << "Opcion no valida" << endl;
        }
    }
    
    return 0;
}