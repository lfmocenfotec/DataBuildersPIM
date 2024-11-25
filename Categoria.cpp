
// Created by XSF on 10/16/2024.
//
// //Laura Fernanda Monge

#include "Categoria.h"
#include "sqlite/sqlite3.h"
#include <iostream>
using namespace std;



Categoria::Categoria(const string& nombre) : nombre(nombre) {}

// Agregar una categoría
void Categoria::agregarCategoria(const std::string& nombre) {


    // Conexión a la base de datos
    sqlite3* db;
    int rc = sqlite3_open("PIM.db", &db);
    if (rc) {
        std::cerr << "No se pudo conectar a la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Preparar la consulta SQL
    const char* sql = "INSERT INTO CATEGORIA (NOMBRE) VALUES (?);";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Vincular el valor de nombre al parámetro
    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);

    // Ejecutar la consulta
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_DONE) {
        std::cout << "Categoria agregada a la base de datos: " << nombre << std::endl;
    } else {
        std::cerr << "Error al agregar la categoria a la base de datos: " << sqlite3_errmsg(db) << std::endl;
    }

    // Finalizar y cerrar la conexión
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}








bool Categoria::modificarCategoria(const string& nombreActual, const string& nuevoNombre) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    bool exito = false;

    // Abre la conexión con la base de datos
    int rc = sqlite3_open("PIM.db", &db);
    if (rc != SQLITE_OK) {
        cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Consulta SQL para actualizar el nombre de la categoría
    string query = "UPDATE CATEGORIA SET nombre = ? WHERE nombre = ?";

    // Prepara la consulta SQL
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Vincula los parámetros (nuevo nombre y nombre actual)
    sqlite3_bind_text(stmt, 1, nuevoNombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, nombreActual.c_str(), -1, SQLITE_STATIC);

    // Ejecuta la consulta
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        exito = true; // La operación fue exitosa
    } else {
        std::cerr << "Error al ejecutar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
    }

    // Limpia los recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return exito;
}












// Eliminar una categoría
bool Categoria::eliminarCategoria(const string& nombre) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    bool exito = false;

    // Abre la conexión con la base de datos
    int rc = sqlite3_open("PIM.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Consulta SQL para eliminar la categoría
    std::string query = "DELETE FROM CATEGORIA WHERE nombre = ?";

    // Prepara la consulta SQL
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Vincula el parámetro (nombre de la categoría)
    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);

    // Ejecuta la consulta
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        exito = true; // La operación fue exitosa
    } else {
        std::cerr << "Error al ejecutar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
    }

    // Limpia los recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return exito;
}







// Visualizar todas las categorías
void Categoria::visualizarCategorias() {
    sqlite3* db;
    int rc = sqlite3_open("PIM.db", &db);

    if (rc) {
        std::cerr << "No se pudo conectar a la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    const char* sql = "SELECT NOMBRE FROM CATEGORIA;";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al preparar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    std::cout << "Lista de categorias en la base de datos:" << std::endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        std::string nombre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::cout << "- " << nombre << std::endl;
    }

    if (rc != SQLITE_DONE) {
        std::cerr << "Error al recuperar las categorias: " << sqlite3_errmsg(db) << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

// Verificar si una categoría existe
bool Categoria::existeCategoria(const std::string& nombre) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    bool existe = false;

    // Abre la conexión con la base de datos
    int rc = sqlite3_open("PIM.db", &db);
    if (rc != SQLITE_OK) {
        // Manejo de error al abrir la base de datos
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    // Consulta SQL para verificar la existencia de la categoría
    std::string query = "SELECT COUNT(*) FROM CATEGORIA WHERE nombre = ?";

    // Prepara la consulta SQL
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Manejo de error al preparar la consulta
        std::cerr << "Error al preparar la consulta SQL: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    // Vincula el nombre de la categoría como parámetro
    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);

    // Ejecuta la consulta y verifica si hay resultados
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int count = sqlite3_column_int(stmt, 0);
        existe = (count > 0); // Si el conteo es mayor que 0, existe la categoría
    }

    // Limpia los recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return existe;
}

// Getters y Setters
std::string Categoria::getNombre() const { return nombre; }
void Categoria::setNombre(const std::string& nombre) { this->nombre = nombre; }
