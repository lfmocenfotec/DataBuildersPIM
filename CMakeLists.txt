cmake_minimum_required(VERSION 3.29)
project(DataBuildersPIM)

set(CMAKE_CXX_STANDARD 14)


add_executable(DataBuildersPIM
        main.cpp
        Categoria.cpp
        Categoria.h
        Producto.cpp
        Producto.h
        ConnectionSQL.cpp

)

# Establecer que se trata de una aplicación de consola
set(CMAKE_WIN32_EXECUTABLE OFF)

