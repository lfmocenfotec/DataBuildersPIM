//
// Created by XSF on 10/16/2024.
//
//Laura Fernanda Monge
#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>

class Categoria {
private:
    std::string nombre;

public:
    Categoria(std::string nombre);

    // Gestiones

    void agregarCategoria();
    void modificarCategoria();
    void eliminarCategoria();
    void visualizarCategoria();



    // Getter y Setters
    std::string getNombre() const;
    void setNombre(const std::string nombre);
};
#endif //CATEGORIA_H
