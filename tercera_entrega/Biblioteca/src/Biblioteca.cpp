#include "../include/Biblioteca.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Biblioteca::agregarLibro(const Libro& lib) {
    coleccion.push_back(lib);
    cout << "Libro agregado exitosamente: " << lib.obtenerTitulo() << endl;
}

bool Biblioteca::eliminarLibro(const string& num_isbn) {
    for (auto it = coleccion.begin(); it != coleccion.end(); ++it) {
        if (it->obtenerISBN() == num_isbn) {
            cout << "Libro eliminado: " << it->obtenerTitulo() << endl;
            coleccion.erase(it);
            return true;
        }
    }
    cout << "Libro con ISBN " << num_isbn << " no encontrado." << endl;
    return false;
}

vector<Libro*> Biblioteca::buscarPorTitulo(const string& tit) {
    vector<Libro*> resultado;
    for (auto& lib : coleccion) {
        if (lib.obtenerTitulo().find(tit) != string::npos) {
            resultado.push_back(&lib);
        }
    }
    return resultado;
}

vector<Libro*> Biblioteca::buscarPorAutor(const string& aut) {
    vector<Libro*> resultado;
    for (auto& lib : coleccion) {
        if (lib.obtenerAutor().find(aut) != string::npos) {
            resultado.push_back(&lib);
        }
    }
    return resultado;
}

void Biblioteca::mostrarDisponibles() const {
    cout << "\n=== LIBROS DISPONIBLES ===" << endl;
    bool hay = false;
    for (const auto& lib : coleccion) {
        if (lib.estaDisponible()) {
            lib.mostrarInfo();
            hay = true;
        }
    }
    if (!hay) {
        cout << "No hay libros disponibles en este momento." << endl;
    }
}

void Biblioteca::mostrarTodos() const {
    cout << "\n=== TODOS LOS LIBROS ===" << endl;
    if (coleccion.empty()) {
        cout << "La biblioteca esta vacia." << endl;
        return;
    }
    for (const auto& lib : coleccion) {
        lib.mostrarInfo();
    }
}

bool Biblioteca::prestarLibro(const string& num_isbn) {
    for (auto& lib : coleccion) {
        if (lib.obtenerISBN() == num_isbn) {
            if (lib.estaDisponible()) {
                lib.cambiarDisponibilidad(false);
                cout << "Libro prestado: " << lib.obtenerTitulo() << endl;
                return true;
            } else {
                cout << "El libro ya esta prestado." << endl;
                return false;
            }
        }
    }
    cout << "Libro con ISBN " << num_isbn << " no encontrado." << endl;
    return false;
}

bool Biblioteca::devolverLibro(const string& num_isbn) {
    for (auto& lib : coleccion) {
        if (lib.obtenerISBN() == num_isbn) {
            if (!lib.estaDisponible()) {
                lib.cambiarDisponibilidad(true);
                cout << "Libro devuelto: " << lib.obtenerTitulo() << endl;
                return true;
            } else {
                cout << "El libro no estaba prestado." << endl;
                return false;
            }
        }
    }
    cout << "Libro con ISBN " << num_isbn << " no encontrado." << endl;
    return false;
}