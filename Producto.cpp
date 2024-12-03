
// Created by jocel on 16/10/2024.
//Jocelyn Miranda H


#include "Producto.h"
#include "Categoria.h"
#include "sqlite/sqlite3.h"
#include "ConnectionDB.h"

using namespace std;


// Constructor
Producto::Producto( const string &nombre, const string &categoria, double precio, int cantidad)
    : nombre(nombre), categoria(categoria), precio(precio), cantidad(cantidad) {}








// Metodo para agregar un producto a la base de datos
void Producto::agregarProducto( const std::string& nombre, const std::string& categoria, double precio, int cantidad) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    std::string query = "INSERT INTO PRODUCTO (NOMBRE, CATEGORIA, PRECIO, CANTIDAD) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, categoria.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 3, precio);
    sqlite3_bind_int(stmt, 4, cantidad);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error al insertar el producto: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Producto agregado correctamente." << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}




void Producto::agregarDetalles(int idProducto, const std::string& detalles) {
    // Conexión a la base de datos
    sqlite3* db;
    char* errorMessage = nullptr;

    // Preparamos la consulta SQL para actualizar los detalles del producto
    std::string sql = "UPDATE PRODUCTO SET DETALLES = ? WHERE IDPRODUCTO = ?;";

    // Abrimos la base de datos
    int rc = sqlite3_open("PIM.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Preparamos la consulta
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Bind de los parámetros: el nuevo detalle y el ID del producto
    sqlite3_bind_text(stmt, 1, detalles.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, idProducto);

    // Ejecutar la consulta
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Error al modificar los detalles del producto: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Detalles del producto con ID " << idProducto << " modificados correctamente." << std::endl;
    }

    // Limpiar recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}





void Producto::verDetalles(int idProducto) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "SELECT DETALLES FROM PRODUCTO WHERE IDPRODUCTO = ?;"; // Consulta SELECT

    // Abrir la base de datos
    int rc = sqlite3_open("PIM.db", &db);
    if (rc) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Preparar la consulta SQL
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Vincular el parámetro del ID del producto
    sqlite3_bind_int(stmt, 1, idProducto);

    // Ejecutar la consulta y obtener los resultados
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        // Obtener el valor del campo DETALLES
        const char* detalles = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::cout << "Detalles del producto con ID " << idProducto << ": " << detalles << std::endl;
    } else if (rc == SQLITE_DONE) {
        std::cout << "No se encontraron detalles para el producto con ID " << idProducto << std::endl;
    } else {
        std::cerr << "Error al ejecutar la consulta: " << sqlite3_errmsg(db) << std::endl;
    }

    // Finalizar la sentencia y cerrar la base de datos
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

    std::string query = "SELECT IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD, DETALLES FROM PRODUCTO WHERE idProducto = ?";
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


// Filtrar productos por categoría
void Producto::filtrarPorCategoria(const string& categoria) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    string query = "SELECT IDPRODUCTO, NOMBRE, PRECIO, CANTIDAD FROM PRODUCTO WHERE CATEGORIA = ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, categoria.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* nombre = (const char*)sqlite3_column_text(stmt, 1);
        double precio = sqlite3_column_double(stmt, 2);
        int cantidad = sqlite3_column_int(stmt, 3);

        cout << "ID: " << id << "\n"
             << "Nombre: " << nombre << "\n"
             << "Precio: " << precio << "\n"
             << "Cantidad: " << cantidad << "\n"
             << "-------------------------------" << endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

// Filtrar productos por precio
void Producto::filtrarPorPrecio(double minPrecio, double maxPrecio) {
    sqlite3* db = obtenerConexion();
    if (!db) return;

    string query = "SELECT IDPRODUCTO, NOMBRE, CATEGORIA, PRECIO, CANTIDAD FROM PRODUCTO WHERE PRECIO >= ? AND PRECIO <= ?";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_double(stmt, 1, minPrecio);
    sqlite3_bind_double(stmt, 2, maxPrecio);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* nombre = (const char*)sqlite3_column_text(stmt, 1);
        const char* categoria = (const char*)sqlite3_column_text(stmt, 2);
        double precio = sqlite3_column_double(stmt, 3);
        int cantidad = sqlite3_column_int(stmt, 4);

        cout << "ID: " << id << "\n"
             << "Nombre: " << nombre << "\n"
             << "Categoría: " << categoria << "\n"
             << "Precio: " << precio << "\n"
             << "Cantidad: " << cantidad << "\n"
             << "-------------------------------" << endl;
    }

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
