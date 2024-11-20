
// Created by jocel on 16/10/2024.
//Jocelyn Miranda H


#include "Producto.h"
#include "Categoria.h"

// Inicializar el vector estático de productos
std::vector<Producto> Producto::productos;

// Constructor
Producto::Producto(int idProducto, const std::string &nombre, const std::string &categoria, double precio, int cantidad)
    : idProducto(idProducto), nombre(nombre), categoria(categoria), precio(precio), cantidad(cantidad) {}

// Método para mostrar los detalles del producto
void Producto::mostrarDetalles() const {
    std::cout << "ID: " << idProducto << "\n"
              << "Nombre: " << nombre << "\n"
              << "Categoría: " << categoria << "\n"
              << "Precio: " << precio << "\n"
              << "Cantidad: " << cantidad << std::endl;
}

// Método para agregar un producto
void Producto::agregarProducto(int idProducto, const std::string& nombre, const std::string& categoria, double precio, int cantidad) {
    if (!Categoria::existeCategoria(categoria)) {
        std::cout << "La categoría '" << categoria << "' no existe. Agregue la categoría antes de agregar el producto." << std::endl;
        return;
    }
    productos.emplace_back(idProducto, nombre, categoria, precio, cantidad);
    std::cout << "Producto agregado: " <<std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Categoria: " << categoria << std::endl;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "Cantidad: " << cantidad << std::endl;
}


// Método para modificar un producto
void Producto::modificarProducto(int idProducto, const std::string &nuevoNombre, const std::string &nuevaCategoria, double nuevoPrecio, int nuevaCantidad) {
    auto it = std::find_if(productos.begin(), productos.end(), [idProducto](const Producto& producto) {
        return producto.idProducto == idProducto;
    });

    if (it != productos.end()) {
        it->setNombre(nuevoNombre);
        it->setCategoria(nuevaCategoria);
        it->setPrecio(nuevoPrecio);
        it->setCantidad(nuevaCantidad);
        std::cout << "Producto con ID " << idProducto << " modificado." << std::endl;
    } else {
        std::cout << "Producto con ID " << idProducto << " no encontrado." << std::endl;
    }
}

// Método para eliminar un producto
void Producto::eliminarProducto(int idProducto) {
    auto it = std::remove_if(productos.begin(), productos.end(), [idProducto](const Producto& producto) {
        return producto.idProducto == idProducto;
    });

    if (it != productos.end()) {
        productos.erase(it, productos.end());
        std::cout << "Producto con ID " << idProducto << " eliminado." << std::endl;
    } else {
        std::cout << "Producto con ID " << idProducto << " no encontrado." << std::endl;
    }
}

// Método para consultar un producto
void Producto::consultarProducto(int idProducto) {
    auto it = std::find_if(productos.begin(), productos.end(), [idProducto](const Producto& producto) {
        return producto.idProducto == idProducto;
    });

    if (it != productos.end()) {
        std::cout << "Detalles del producto con ID " << idProducto << ":" << std::endl;
        it->mostrarDetalles();
    } else {
        std::cout << "Producto con ID " << idProducto << " no encontrado." << std::endl;
    }
}

// Getters y Setters
int Producto::getId() const { return idProducto; }
void Producto::setId(int idProducto) { this->idProducto = idProducto; }

std::string Producto::getNombre() const { return nombre; }
void Producto::setNombre(const std::string &nombre) { this->nombre = nombre; }

std::string Producto::getCategoria() const { return categoria; }
void Producto::setCategoria(const std::string &categoria) { this->categoria = categoria; }

double Producto::getPrecio() const { return precio; }
void Producto::setPrecio(double precio) { this->precio = precio; }

int Producto::getCantidad() const { return cantidad; }
void Producto::setCantidad(int cantidad) { this->cantidad = cantidad; }
