//
// Created by XSF on 11/19/2024.
//
#include <cstdio>
#include <iostream>

#include "sqlite/sqlite3.h"

using namespace std;

int initBD() {
    sqlite3* db;
    char* zErrMsg = nullptr;
    int rc;

    // Abrir la base de datos
    rc = sqlite3_open("PIM.db", &db);
    if (rc) {
        fprintf(stderr, "no se pudo conectar a la base de datos: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Base de datos abierta\n");
    }

    // Crear tabla CATEGORIA
    const char* sqlCreateCategoria =
        "CREATE TABLE IF NOT EXISTS CATEGORIA ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "NOMBRE TEXT NOT NULL);";

    rc = sqlite3_exec(db, sqlCreateCategoria, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla CATEGORIA: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return -1;
    } else {
        cout << "Tabla CATEGORIA creada correctamente.\n";
    }

    // Crear tabla PRODUCTO
    const char* sqlCreateProducto =
        "CREATE TABLE IF NOT EXISTS PRODUCTO ("
        "IDPRODUCTO INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
        "NOMBRE TEXT NOT NULL, "
        "CATEGORIA TEXT NOT NULL, "
        "PRECIO REAL NOT NULL, "
        "CANTIDAD INT NOT NULL, "
        "DETALLES TEXT);"; // Campo para agregar los atributos personalizables


    rc = sqlite3_exec(db, sqlCreateProducto, nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al crear la tabla PRODUCTO: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return -1;
    } else {
        cout << "Tabla PRODUCTO creada correctamente.\n";
    }

    // Cerrar la base de datos
    sqlite3_close(db);
    cout << "Base de datos cerrada exitosamente.\n";
    return 0;
}

sqlite3* obtenerConexion() {
    sqlite3* db;
    // Intentamos abrir la base de datos
    if (sqlite3_open("PIM.db", &db)) {
        std::cerr << "No se pudo abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;  // Si no se puede abrir, retornamos un puntero nulo
    }
    return db;  // Si se pudo abrir correctamente, retornamos el puntero de conexión
}


