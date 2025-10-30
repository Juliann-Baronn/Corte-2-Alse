#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>
#include <string>
using namespace std;

class Biblioteca {
private:
    vector<Libro> coleccion;

public:
    void agregarLibro(const Libro& lib);
    
    bool eliminarLibro(const string& num_isbn);
    
    vector<Libro*> buscarPorTitulo(const string& tit);
    
    vector<Libro*> buscarPorAutor(const string& aut);
    
    void mostrarDisponibles() const;
    
    void mostrarTodos() const;
    
    bool prestarLibro(const string& num_isbn);
    
    bool devolverLibro(const string& num_isbn);
};

#endif