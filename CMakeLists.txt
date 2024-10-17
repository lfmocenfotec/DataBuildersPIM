cmake_minimum_required(VERSION 3.29)
project(DataBuildersPIM)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
add_executable(DataBuildersPIM
    main.cpp
        Categoria.cpp
        Categoria.h)
=======
# Establecer que se trata de una aplicación de consola
set(CMAKE_WIN32_EXECUTABLE OFF)

add_executable(DataBuildersPIM main.cpp
        Producto.h
        Producto.cpp)  # Agrega otros archivos si es necesario
>>>>>>> main
