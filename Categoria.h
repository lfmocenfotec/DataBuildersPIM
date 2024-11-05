<<<<<<< HEAD
//
// Created by XSF on 10/16/2024.
//
//Laura Fernanda Monge
=======
>>>>>>> origin/Laura
#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
#include <vector>

class Categoria {
private:
    std::string nombre;
    static std::vector<Categoria> categorias; // Lista de todas las categorías

public:
    Categoria(const std::string& nombre);

    // Métodos de gestión
    static void agregarCategoria(const std::string& nombre);
    static void modificarCategoria(const std::string& nombreExistente, const std::string& nuevoNombre);
    static void eliminarCategoria(const std::string& nombre);
    static void visualizarCategorias();

    // Método para verificar si una categoría existe
    static bool existeCategoria(const std::string& nombre);

    // Getters y Setters
    std::string getNombre() const;
    void setNombre(const std::string& nombre);
};

#endif //CATEGORIA_H
