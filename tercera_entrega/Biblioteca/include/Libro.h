#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponible;

public:
    Libro(string tit, string aut, string num_isbn);
    
    string obtenerTitulo() const;
    string obtenerAutor() const;
    string obtenerISBN() const;
    bool estaDisponible() const;
    
    void cambiarDisponibilidad(bool estado);
    
    void mostrarInfo() const;
};

#endif