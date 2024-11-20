#include <iostream>
#include <string>
#include <limits>

#include "Categoria.h"

using namespace std;
#include "Producto.h"
#include <vector>

#include <iostream>
#include <string>
std::vector<Producto> productos; // Vector para almacenar productos

//Douglas Manases

std::vector<Categoria> categorias; // Vector para almacenar categorias

using namespace std;

void menuBusqueda() {
    int option;

    do {
        std::cout << "\n===========================================" << std::endl;
        std::cout << "Menú de búsqueda y filtrado " << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "1. Buscar producto por nombre." << std::endl;
        std::cout << "2. Filtrar producto por nombre" << std::endl;
        std::cout << "0. Volver al menu principal" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "\nSeleccione una opción: "<<std::endl;
        std::cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Inténtelo de nuevo." << endl;
            continue;
        }

        switch (option) {
            case 1:
            break;

            case 2:
            break;

            case 0:
                std::cout << "Saliendo..." << std::endl;
            break;
            default:
                std::cout << "Opción inválida, inténtelo de nuevo." << std::endl;
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
        cout << "Categorías:" << endl;
        cout << "===========================================" << endl;
        cout << "1. Crear categoría" << endl;
        cout << "2. Editar categoría" << endl;
        cout << "3. Eliminar categoría" << endl;
        cout << "4. Consultar lista de categorías" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "6. Salir" << endl;
        cout << "=========================================" << endl;
        cout << "\nSeleccione una opción: "<<endl;
        cin >> option;

            // Verificar entrada inválida
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Inténtelo de nuevo." << endl;
                continue;
            }

            std::string nombre, nuevoNombre;

            switch (option) {
                case 1: // Agregar categoría
                    cout << "Ingrese el nombre de la nueva categoría: ";
                    cin >> nombre;
                    Categoria::agregarCategoria(nombre);
                break;

                case 2: // Modificar categoría
                    cout << "Ingrese el nombre de la categoría a modificar: ";
                    cin >> nombre;
                    cout << "Ingrese el nuevo nombre de la categoría: ";
                    cin >> nuevoNombre;
                    Categoria::modificarCategoria(nombre, nuevoNombre);
                break;

                case 3: // Eliminar categoría
                    cout << "Ingrese el nombre de la categoría a eliminar: ";
                    cin >> nombre;
                    Categoria::eliminarCategoria(nombre);
                break;

                case 4: // Visualizar todas las categorías
                    Categoria::visualizarCategorias();
                break;

                case 5: // Volver al menú principal
                    cout << "Volviendo al menú principal..." << endl;
                    exit = true;
                break;

                case 6: // Salir
                    cout << "Saliendo..." << endl;
                    exit = true;
                break;

                default:
                    cout << "Opción inválida, inténtelo de nuevo." << endl;
                break;
            }
        }
}
//Laura Fernanda Monge
void menuProducto() {
    int option;

    do {
        std::cout << "\n===========================================" << std::endl;
        std::cout << "Menu Producto" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "1. Agregar nuevos productos" << std::endl;
        std::cout << "2. Modificar productos existentes" << std::endl;
        std::cout << "3. Eliminar productos" << std::endl;
        std::cout << "4. Consultar productos" << std::endl;
        std::cout << "0. Volver al menu principal" << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "\nSeleccione una opción: "<<std::endl;
        std::cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Inténtelo de nuevo." << endl;
            continue;
        }

        switch (option) {
            case 1: { // Agregar producto
                int id, cantidad;
                std::string nombre, categoria;
                double precio;

                std::cout << "Ingrese ID del producto: "<< std::endl;
                std::cin >> id;
                std::cout << "Ingrese nombre del producto: "<< std::endl;
                std::cin>> nombre;
                std::cout << "Ingrese categoría del producto: "<< std::endl;
                std::cin>> categoria;
                std::cout << "Ingrese precio del producto: "<< std::endl;
                std::cin >> precio;
                std::cout << "Ingrese cantidad del producto: "<< std::endl;
                std::cin >> cantidad;

                Producto::agregarProducto(id, nombre, categoria, precio, cantidad);
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
                int id;
                std::cout << "Ingrese ID del producto a consultar: "<< std::endl;
                std::cin >> id;
                Producto::consultarProducto(id);
                break;
            }
            case 0:
                std::cout << "Volviendo al menú principal..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida, inténtelo de nuevo." << std::endl;
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
                throw invalid_argument("Entrada inválida. Por favor, ingrese un número.");
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

