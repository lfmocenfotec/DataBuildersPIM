
// Created by jocel on 16/10/2024.
//Jocelyn Miranda H


#include "Producto.h"
#include "Categoria.h"
#include "sqlite/sqlite3.h"
#include "ConnectionDB.h"

using namespace std;


// Constructor
Producto::Producto(int idProducto, const string &nombre, const string &categoria, double precio, int cantidad)
    : idProducto(idProducto), nombre(nombre), categoria(categoria), precio(precio), cantidad(cantidad) {}








// Metodo para agregar un producto a la base de datos
void Producto::agregarProducto(int idProducto, const std::string& nombre, const std::string& categoria, double precio, int cantidad) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "INSERT INTO PRODUCTO (IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD) VALUES (?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_int(stmt, 1, idProducto);
    sqlite3_bind_text(stmt, 2, nombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, categoria.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 4, precio);
    sqlite3_bind_int(stmt, 5, cantidad);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error al insertar el producto: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Producto agregado correctamente." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}








// Metodo para modificar un producto en la base de datos
void Producto::modificarProducto(int idProducto, const std::string& nuevoNombre, const std::string& nuevaCategoria, double nuevoPrecio, int nuevaCantidad) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "UPDATE PRODUCTO SET NOMBRE = ?, CATEGORIA = ?, PRECIO = ?, CANTIDAD = ? WHERE IDPRODUCTO = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, nuevoNombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nuevaCategoria.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, nuevoPrecio);
    sqlite3_bind_int(stmt, 4, nuevaCantidad);
    sqlite3_bind_int(stmt, 5, idProducto);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error al modificar el producto: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Producto modificado correctamente." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}







// Metodo para eliminar un producto de la base de datos
void Producto::eliminarProducto(int idProducto) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "DELETE FROM PRODUCTO WHERE IDPRODUCTO = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_int(stmt, 1, idProducto);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error al eliminar el producto: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Producto eliminado correctamente." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}








// Metodo para consultar un producto en la base de datos
void Producto::consultarProducto(int idProducto) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "SELECT IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD FROM PRODUCTO WHERE idProducto = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_int(stmt, 1, idProducto);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* nombre = (const char*)sqlite3_column_text(stmt, 1);
        const char* categoria = (const char*)sqlite3_column_text(stmt, 2);
        double precio = sqlite3_column_double(stmt, 3);
        int cantidad = sqlite3_column_int(stmt, 4);

        std::cout << "Producto encontrado:" << std::endl;
        std::cout << "ID: " << id << "\n"
                  << "Nombre: " << nombre << "\n"
                  << "Categoría: " << categoria << "\n"
                  << "Precio: " << precio << "\n"
                  << "Cantidad: " << cantidad << std::endl;
    } else {
        std::cout << "Producto con ID " << idProducto << " no encontrado." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}








// Metodo para listar todos los productos registrados en la base de datos
void Producto::listarProductos() {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "SELECT IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD FROM PRODUCTO";
    sqlite3_stmt* stmt;

    // Preparar la consulta SQL
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Ejecutar la consulta y obtener los resultados
    std::cout << "Lista de productos registrados en la base de datos:" << std::endl;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* nombre = (const char*)sqlite3_column_text(stmt, 1);
        const char* categoria = (const char*)sqlite3_column_text(stmt, 2);
        double precio = sqlite3_column_double(stmt, 3);
        int cantidad = sqlite3_column_int(stmt, 4);

        // Mostrar los detalles de cada producto
        std::cout << "ID: " << id << "\n"
                  << "Nombre: " << nombre << "\n"
                  << "Categoría: " << categoria << "\n"
                  << "Precio: " << precio << "\n"
                  << "Cantidad: " << cantidad << "\n"
                  << "-------------------------------" << std::endl;
    }

    // Finalizar el statement y cerrar la conexión
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}







void Producto::consultarProductoNom(const string& nombre) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    // Consulta SQL con filtro por nombre (usando LIKE para coincidencia parcial)
    std::string query = "SELECT IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD "
                        "FROM PRODUCTO WHERE NOMBRE LIKE ?";
    sqlite3_stmt* stmt;

    // Preparar la consulta
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Bind del parámetro (busca coincidencias parciales)
    std::string likePattern = "%" + nombre + "%";
    if (sqlite3_bind_text(stmt, 1, likePattern.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
        std::cerr << "Error al asignar el parámetro: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    // Ejecutar la consulta y mostrar los resultados
    bool hayResultados = false;
    std::cout << "Resultados de la búsqueda para \"" << nombre << "\":" << std::endl;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        hayResultados = true;
        int id = sqlite3_column_int(stmt, 0);
        const char* nombre = (const char*)sqlite3_column_text(stmt, 1);
        const char* categoria = (const char*)sqlite3_column_text(stmt, 2);
        double precio = sqlite3_column_double(stmt, 3);
        int cantidad = sqlite3_column_int(stmt, 4);

        std::cout << "ID: " << id << "\n"
                  << "Nombre: " << nombre << "\n"
                  << "Categoría: " << categoria << "\n"
                  << "Precio: " << precio << "\n"
                  << "Cantidad: " << cantidad << "\n"
                  << "-------------------------------" << std::endl;
    }

    if (!hayResultados) {
        std::cout << "No se encontraron productos que coincidan con \"" << nombre << "\"." << std::endl;
    }

    // Finalizar el statement y cerrar la conexión
    sqlite3_finalize(stmt);
    sqlite3_close(db);
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
