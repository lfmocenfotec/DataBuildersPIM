//
// Created by XSF on 10/16/2024.
//

#include "Categoria.h"

#include <iostream>
#include <ostream>

//Constructor

Categoria::Categoria(std::string nombre) : nombre(nombre){

}

void Categoria::agregarCategoria() {
    std::cout << "Categoria agragda: " << nombre <<  std::endl;
}

void Categoria::eliminarCategoria() {
    std::cout << "Categoria eliminada: " << nombre <<  std::endl;
}

void Categoria::modificarCategoria() {
    std::cout << "Categoria modificada: " << nombre <<  std::endl;
}

void Categoria::visualizarCategoria() {
    std::cout << "Visualizar categoria: " << nombre <<  std::endl;
}

// Getter - Setters

std::string Categoria::getNombre() const {
    return nombre;
}
void Categoria::setNombre( const std::string nombre) {
    this -> nombre = nombre;
}