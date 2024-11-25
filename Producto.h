//
// Created by jocel on 16/10/2024.
//
//Jocelyn Miranda H.
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>
using namespace std;

class Producto {
private:
    int idProducto;
    string nombre;
    string categoria;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(int idProducto, const string& nombre, const string& categoria, double precio, int cantidad);


    // Métodos para gestionar productos
    static void agregarProducto(int idProducto, const string &nombre, const string &categoria, double precio, int cantidad);
    static void modificarProducto(int idProducto, const string &nuevoNombre, const string &nuevaCategoria, double nuevoPrecio, int nuevaCantidad);
    static void eliminarProducto(int idProducto);
    static void consultarProducto(int idProducto);
    static void listarProductos();

    // Getters y Setters
    int getId() const;
    void setId(int idProducto);

    string getNombre() const;
    void setNombre(const string& nombre);

    string getCategoria() const;
    void setCategoria(const string& categoria);

    double getPrecio() const;
    void setPrecio(double precio);

    int getCantidad() const;
    void setCantidad(int cantidad);
};

#endif // PRODUCTO_H
