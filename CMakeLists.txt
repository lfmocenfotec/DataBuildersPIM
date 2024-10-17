cmake_minimum_required(VERSION 3.29)
project(DataBuildersPIM)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD

=======
# Añadir todos los archivos fuente al ejecutable
>>>>>>> origin/main
add_executable(DataBuildersPIM
        main.cpp
        Categoria.cpp
        Categoria.h
<<<<<<< HEAD
        Categoria.h
        Categoria.h
        Categoria.h)

# Establecer que se trata de una aplicación de consola
set(CMAKE_WIN32_EXECUTABLE OFF)

add_executable(DataBuildersPIM main.cpp
        Producto.h
        Producto.cpp
        Categoria.h
        Categoria.h
        Categoria.h
        Categoria.h)  # Agrega otros archivos si es necesario

=======
        Producto.cpp
        Producto.h)  # Agrega otros archivos si es necesario

# Establecer que se trata de una aplicación de consola
set(CMAKE_WIN32_EXECUTABLE OFF)
>>>>>>> origin/main
