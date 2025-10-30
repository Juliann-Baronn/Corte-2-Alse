#include "../include/Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(string tit, string aut, string num_isbn) {
    this->titulo = tit;
    this->autor = aut;
    this->isbn = num_isbn;
    this->disponible = true;
}

string Libro::obtenerTitulo() const {
    return titulo;
}

string Libro::obtenerAutor() const {
    return autor;
}

string Libro::obtenerISBN() const {
    return isbn;
}

bool Libro::estaDisponible() const {
    return disponible;
}

void Libro::cambiarDisponibilidad(bool estado) {
    disponible = estado;
}

void Libro::mostrarInfo() const {
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Estado: " << (disponible ? "Disponible" : "Prestado") << endl;
    cout << "------------------------" << endl;
}
