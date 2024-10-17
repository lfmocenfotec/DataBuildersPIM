//
// Created by jocel on 16/10/2024.
//Jocelyn Miranda H

#include "Producto.h"

// Constructor
Producto::Producto(int id, const std::string &nombre, const std::string &categoria, double precio, int cantidad)
    : nombre(nombre), categoria(categoria), precio(precio), cantidad(cantidad) {
}

// Método para mostrar los detalles del producto
void Producto::mostrarDetalles() const {
    std::cout << "Nombre: " << nombre << "\n"
            << "Categoría: " << categoria << "\n"
            << "Precio: " << precio << "\n"
            << "Cantidad: " << cantidad << std::endl;
}


void Producto::agregarProducto() {
    // Aquí iría la lógica para agregar un producto.
    std::cout << "Producto agregado: " << nombre << std::endl;
}


void Producto::modificarProducto(int id) {
    // Aquí iría la lógica para modificar un producto.

    std::cout << "Producto con ID " << id << " modificado." << std::endl;
}

void Producto::eliminarProducto(int id) {
    // Aquí iría la lógica para eliminar un producto.
    std::cout << "Producto con ID " << id << " eliminado." << std::endl;
}

void Producto::consultarProducto() {
    std::cout << "Consultando producto: " << std::endl;
    mostrarDetalles(); // Muestra los detalles del producto
}

// Getters y Setters
std::string Producto::getNombre() const { return nombre; }
void Producto::setNombre(const std::string &nombre) { this->nombre = nombre; }

std::string Producto::getCategoria() const { return categoria; }
void Producto::setCategoria(const std::string &categoria) { this->categoria = categoria; }

double Producto::getPrecio() const { return precio; }
void Producto::setPrecio(double precio) { this->precio = precio; }

int Producto::getCantidad() const { return cantidad; }
void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }



