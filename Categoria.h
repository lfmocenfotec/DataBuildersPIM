
//
// Created by XSF on 10/16/2024.
//
//Laura Fernanda Monge

#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

using namespace std;

class Categoria {
private:
    string nombre;

public:
    Categoria(const string& nombre);

    // Metodos de gestión
    static void agregarCategoria(const string& nombre);
    static bool modificarCategoria(const string& nombreExistente, const string& nuevoNombre);
    static bool eliminarCategoria(const string& nombre);
    static void visualizarCategorias();

    // Metodo para verificar si una categoría existe
    static bool existeCategoria(const string& nombre);

    // Getters y Setters
    std::string getNombre() const;
    void setNombre(const string& nombre);
};

#endif //CATEGORIA_H
