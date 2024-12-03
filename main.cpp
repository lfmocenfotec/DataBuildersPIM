#include <iostream>
#include <string>
#include <limits>
#include "Categoria.h"
#include "sqlite/sqlite3.h"
#include "ConnectionDB.h"
#include "Producto.h"
#include <cstdlib>


using namespace std;

void menuBusqueda() {
    int option;

    do {
        std::cout << "\n===========================================" << std::endl;
        std::cout << "Menu de busqueda y filtrado " << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "1. Buscar producto por nombre." << std::endl;
        std::cout << "2. Buscar Categoria por nombre" << std::endl;
        std::cout << "3. Buscar producto por categoria." << std::endl;
        std::cout << "4. Buscar producto por precio." << std::endl;
        std::cout << "0. Volver al menu principal" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "\nSeleccione una opcion: "<<std::endl;
        std::cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intentelo de nuevo." << endl;
            continue;
        }
        std::string nombre;

        switch (option) {
            case 1:
                cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            Producto::consultarProductoNom(nombre);
            break;

            case 2:
                cout << "Ingrese el nombre de la categoria: ";
            cin >> nombre;
            Categoria::consultaCategoriaNom(nombre);
            break;

            case 3:
                cout << "Ingrese el nombre de la catergoria: ";
                cin >> nombre;
                Producto::filtrarPorCategoria(nombre);
            break;

            case 4:
                double preciomin;
                double preciomax;
                cout << "Ingrese el precio minimo: ";
                cin >> preciomin;
                cout << "Ingrese el precio maximo: ";
                cin >> preciomax;
            Producto::filtrarPorPrecio(preciomin, preciomax);
            break;

            case 0:
                std::cout << "Saliendo..." << std::endl;
            break;
            default:
                std::cout << "Opción invalida, inténtelo de nuevo." << std::endl;
            break;
        }
    } while (option != 0);
}

void mensajeSalida() {
    cout << "Saliendo del programae..." << endl;

}


//Jocelyn Miranda H.
void menuCategoria() {
    int option;
    bool exit = false;

    while (!exit) {
        cout << "\n===========================================" << endl;
        cout << "Categorias:" << endl;
        cout << "===========================================" << endl;
        cout << "1. Crear categoria" << endl;
        cout << "2. Editar categoria" << endl;
        cout << "3. Eliminar categoria" << endl;
        cout << "4. Consultar lista de categorias" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "6. Salir" << endl;
        cout << "=========================================" << endl;
        cout << "\nSeleccione una opcion: "<<endl;
        cin >> option;

            // Verificar entrada inválida
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Intentelo de nuevo." << endl;
                continue;
            }

            std::string nombre, nuevoNombre;

            switch (option) {
                case 1: // Agregar categoría
                    cout << "Ingrese el nombre de la nueva categoria: ";
                    cin >> nombre;
                    Categoria::agregarCategoria(nombre);
                break;

                case 2: // Modificar categoría
                    cout << "Ingrese el nombre de la categoria a modificar: ";
                    cin >> nombre;
                    cout << "Ingrese el nuevo nombre de la categoria: ";
                    cin >> nuevoNombre;
                    Categoria::modificarCategoria(nombre, nuevoNombre);
                break;

                case 3: // Eliminar categoría
                    cout << "Ingrese el nombre de la categoria a eliminar: ";
                    cin >> nombre;
                    Categoria::eliminarCategoria(nombre);
                break;

                case 4: // Visualizar todas las categorías
                    Categoria::visualizarCategorias();
                break;

                case 5: // Volver al menú principal
                    cout << "Volviendo al menu principal..." << endl;
                    exit = true;
                break;

                case 6: // Salir
                    cout << "Saliendo..." << endl;
                    exit = true;
                break;

                default:
                    cout << "Opción invalida, intentelo de nuevo." << endl;
                break;
            }
        }
}
void menuProducto() {
    int option;

    do {
        cout << "\n===========================================" << endl;
        cout << "Menu Producto" << endl;
        cout << "===========================================" << endl;
        cout << "1. Agregar nuevos productos" << endl;
        cout << "2. Modificar productos existentes" << endl;
        cout << "3. Eliminar productos" << std::endl;
        cout << "4. Listar todos los productos" << endl;
        cout << "5. Consultar producto por id" << std::endl;
        cout << "6. Registrar detalles de un producto" << std::endl;
        cout << "7. Ver detalles de un producto" << std::endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "=========================================" << endl;
        cout << "\nSeleccione una opcion: "<<endl;
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intentelo de nuevo." << endl;
            continue;
        }

        switch (option) {
            case 1: { // Agregar producto
                int cantidad;
                string nombre, categoria;
                double precio;

                std::cout << "Ingrese nombre del producto: "<< std::endl;
                std::cin>> nombre;
                std::cout << "Ingrese categoria del producto: "<< std::endl;
                std::cin>> categoria;
                std::cout << "Ingrese precio del producto: "<< std::endl;
                std::cin >> precio;
                std::cout << "Ingrese cantidad del producto: "<< std::endl;
                std::cin >> cantidad;

                Producto::agregarProducto(nombre, categoria, precio, cantidad);
                break;
            }
            case 2: { // Modificar producto
                int id;
                std::string nuevoNombre, nuevaCategoria;
                double nuevoPrecio;
                int nuevaCantidad;

                std::cout << "Ingrese ID del producto a modificar: "<< std::endl;
                std::cin >> id;
                std::cout << "Ingrese nuevo nombre: "<< std::endl;
                std::cin >> nuevoNombre;
                std::cout << "Ingrese nueva categoría: "<< std::endl;
                std::cin >> nuevaCategoria;
                std::cout << "Ingrese nuevo precio: "<< std::endl;
                std::cin >> nuevoPrecio;
                std::cout << "Ingrese nueva cantidad: "<< std::endl;
                std::cin >> nuevaCantidad;

                Producto::modificarProducto(id, nuevoNombre, nuevaCategoria, nuevoPrecio, nuevaCantidad);
                break;
            }
            case 3: { // Eliminar producto
                int id;
                std::cout << "Ingrese ID del producto a eliminar: "<< std::endl;
                std::cin >> id;
                Producto::eliminarProducto(id);
                break;
            }
            case 4: { // Consultar producto
                Producto::listarProductos();
                break;
            }
            case 5: { // Consultar producto
                int id;
                std::cout << "Ingrese ID del producto a consultar: "<< std::endl;
                std::cin >> id;
                Producto::consultarProducto(id);
                break;
            }
            case 6: { // Registrar detalles de un producto
                int idProducto;
                std::string detalles;

                std::cout << "Ingrese el ID del producto: ";
                std::cin >> idProducto;
                std::cin.ignore();  // Para limpiar el buffer de entrada
                std::cout << "Ingrese los detalles del producto: ";
                std::getline(std::cin, detalles);

                Producto::agregarDetalles(idProducto, detalles);
                break;
            }
            case 7: { // Consultar producto
                int id;
                std::cout << "Ingrese ID del producto a consultar detalles: "<< std::endl;
                std::cin >> id;
                Producto::verDetalles(id);
                break;
            }
            case 0:
                std::cout << "Volviendo al menú principal..." << std::endl;
                break;
            default:
                std::cout << "Opcion inválida, intentelo de nuevo." << std::endl;
                break;
        }
    } while (option != 0);
}

//Ignacio Molina A.
void menuPrincipal() {
    int option;
    bool exit = false;

    while (!exit) {
        try {
            cout << "\n===========================================" << endl;
            cout << "Administrador de información de productos" << endl;
            cout << "==========================================" << endl;
            cout << "1. Administrar productos" << endl;
            cout << "2. Administrar categorias" << endl;
            cout << "3. Buscar y filtrar productos" << endl;
            cout << "4. Salir" << endl;
            cout << "=========================================" << endl;
            cout << "\nSeleccione una opcion: "<<endl;
            cin >> option;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Entrada invalida. Por favor, ingrese un numero.");
            }

            switch (option) {
                case 1:
                    menuProducto();
                break;
                case 2:
                    menuCategoria();
                break;
                case 3:
                    menuBusqueda();
                break;
                case 4:
                    mensajeSalida();
                exit = true;
                break;
                default:
                    cout << "Opcion invalida, intentelo de nuevo." << endl;
                break;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;

        }
    }
}



int main() {
    if (initBD() == 0) {

        menuPrincipal();
        cerr << "Base de datos configurada correctamente." << endl;
        return -1;

    }

    cout << "Hubo un problema al inicializar la base de datos." << endl;

    return 0;
}
