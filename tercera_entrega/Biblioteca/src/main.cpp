#include "../include/Biblioteca.h"
#include "../include/Libro.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "\nSISTEMA DE BIBLIOTECA" << endl;
    cout << "1. Agregar libro" << endl;
    cout << "2. Eliminar libro" << endl;
    cout << "3. Buscar libro por titulo" << endl;
    cout << "4. Buscar libro por autor" << endl;
    cout << "5. Mostrar libros disponibles" << endl;
    cout << "6. Mostrar todos los libros" << endl;
    cout << "7. Prestar libro" << endl;
    cout << "8. Devolver libro" << endl;
    cout << "9. Salir" << endl;
    cout << "===========================================" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Biblioteca bib;
    int opc;
    string tit, aut, num_isbn;
    
    bib.agregarLibro(Libro("Cien anos de soledad", "Gabriel Garcia Marquez", "978-0307474728"));
    bib.agregarLibro(Libro("El principito", "Antoine de Saint-Exupery", "978-0156012195"));
    bib.agregarLibro(Libro("1984", "George Orwell", "978-0451524935"));
    
    do {
        mostrarMenu();
        cin >> opc;
        cin.ignore();
        
        switch(opc) {
            case 1: {
                cout << "\nIngrese titulo del libro: ";
                getline(cin, tit);
                cout << "Ingrese autor del libro: ";
                getline(cin, aut);
                cout << "Ingrese ISBN del libro: ";
                getline(cin, num_isbn);
                bib.agregarLibro(Libro(tit, aut, num_isbn));
                break;
            }
            case 2: {
                cout << "\nIngrese ISBN del libro a eliminar: ";
                getline(cin, num_isbn);
                bib.eliminarLibro(num_isbn);
                break;
            }
            case 3: {
                cout << "\nIngrese titulo a buscar: ";
                getline(cin, tit);
                vector<Libro*> res = bib.buscarPorTitulo(tit);
                if (res.empty()) {
                    cout << "No se encontraron libros con ese titulo." << endl;
                } else {
                    cout << "\nResultados de busqueda:" << endl;
                    for (auto lib : res) {
                        lib->mostrarInfo();
                    }
                }
                break;
            }
            case 4: {
                cout << "\nIngrese autor a buscar: ";
                getline(cin, aut);
                vector<Libro*> res = bib.buscarPorAutor(aut);
                if (res.empty()) {
                    cout << "No se encontraron libros de ese autor." << endl;
                } else {
                    cout << "\nResultados de busqueda:" << endl;
                    for (auto lib : res) {
                        lib->mostrarInfo();
                    }
                }
                break;
            }
            case 5: {
                bib.mostrarDisponibles();
                break;
            }
            case 6: {
                bib.mostrarTodos();
                break;
            }
            case 7: {
                cout << "\nIngrese ISBN del libro a prestar: ";
                getline(cin, num_isbn);
                bib.prestarLibro(num_isbn);
                break;
            }
            case 8: {
                cout << "\nIngrese ISBN del libro a devolver: ";
                getline(cin, num_isbn);
                bib.devolverLibro(num_isbn);
                break;
            }
            case 9: {
                cout << "\nGracias por usar el sistema de biblioteca!" << endl;
                break;
            }
            default: {
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
            }
        }
    } while(opc != 9);
    
    return 0;
}