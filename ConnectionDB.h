//
// Created by XSF on 11/19/2024.
//
#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include "sqlite/sqlite3.h"
int initBD();
sqlite3* obtenerConexion();

#endif //CONNECTIONDB_H
