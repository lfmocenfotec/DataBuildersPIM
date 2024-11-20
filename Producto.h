//
// Created by jocel on 16/10/2024.
//
//Jocelyn Miranda H.
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Producto {
private:
    int idProducto;
    std::string nombre;
    std::string categoria;
    double precio;
    int cantidad;

    // Lista estática de productos
    static std::vector<Producto> productos;

public:
    // Constructor
    Producto(int idProducto, const std::string& nombre, const std::string& categoria, double precio, int cantidad);

    // Método para mostrar los detalles del producto
    void mostrarDetalles() const;

    // Métodos para gestionar productos
    static void agregarProducto(int idProducto, const std::string &nombre, const std::string &categoria, double precio, int cantidad);
    static void modificarProducto(int idProducto, const std::string &nuevoNombre, const std::string &nuevaCategoria, double nuevoPrecio, int nuevaCantidad);
    static void eliminarProducto(int idProducto);
    static void consultarProducto(int idProducto);

    // Getters y Setters
    int getId() const;
    void setId(int idProducto);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getCategoria() const;
    void setCategoria(const std::string& categoria);

    double getPrecio() const;
    void setPrecio(double precio);

    int getCantidad() const;
    void setCantidad(int cantidad);
};

#endif // PRODUCTO_H
