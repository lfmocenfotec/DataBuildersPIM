
// Created by XSF on 10/16/2024.
//
// //Laura Fernanda Monge

#include "Categoria.h"
#include <iostream>

// Inicialización del vector estático de categorías
std::vector<Categoria> Categoria::categorias;

Categoria::Categoria(const std::string& nombre) : nombre(nombre) {}

// Agregar una categoría
void Categoria::agregarCategoria(const std::string& nombre) {
    if (existeCategoria(nombre)) {
        std::cout << "La categoría '" << nombre << "' ya existe." << std::endl;
    } else {
        categorias.emplace_back(nombre);
        std::cout << "Categoría agregada: " << nombre << std::endl;
    }
}

// Modificar una categoría
void Categoria::modificarCategoria(const std::string& nombreExistente, const std::string& nuevoNombre) {
    for (auto& categoria : categorias) {
        if (categoria.getNombre() == nombreExistente) {
            categoria.setNombre(nuevoNombre);
            std::cout << "Categoría modificada a: " << nuevoNombre << std::endl;
            return;
        }
    }
    std::cout << "Categoría no encontrada: " << nombreExistente << std::endl;
}

// Eliminar una categoría
void Categoria::eliminarCategoria(const std::string& nombre) {
    for (auto it = categorias.begin(); it != categorias.end(); ++it) {
        if (it->getNombre() == nombre) {
            categorias.erase(it);
            std::cout << "Categoría eliminada: " << nombre << std::endl;
            return;
        }
    }
    std::cout << "Categoría no encontrada: " << nombre << std::endl;
}

// Visualizar todas las categorías
void Categoria::visualizarCategorias() {
    std::cout << "Lista de categorías:" << std::endl;
    for (const auto& categoria : categorias) {
        std::cout << "- " << categoria.getNombre() << std::endl;
    }
}

// Verificar si una categoría existe
bool Categoria::existeCategoria(const std::string& nombre) {
    for (const auto& categoria : categorias) {
        if (categoria.getNombre() == nombre) {
            return true;
        }
    }
    return false;
}

// Getters y Setters
std::string Categoria::getNombre() const { return nombre; }
void Categoria::setNombre(const std::string& nombre) { this->nombre = nombre; }
