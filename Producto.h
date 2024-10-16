//
// Created by jocel on 16/10/2024.
//

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>


class Producto {
private:
  int id;
  std::string nombre;
  std::string categoria;
  double precio;
  int cantidad;


public:
    Producto(int id, const std::string& nombre, const std::string& categoria, double precio, int cantidad);

    void mostrarDetalles() const;

    // Métodos para gestionar productos
    void agregarProducto();
    void modificarProducto(int id);
    void eliminarProducto(int id);
    void consultarProducto();
    // Getters y Setters
    int getId() const;
    void setId(int id);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getCategoria() const;
    void setCategoria(const std::string& categoria);

    double getPrecio() const;
    void setPrecio(double precio);

    int getCantidad() const;
    void setCantidad(int cantidad);
};




#endif //PRODUCTO_H
