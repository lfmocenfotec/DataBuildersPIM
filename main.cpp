//
// Created by NachoM on 14/10/2024.
//

#include <iostream>
#include <string>

using namespace std;

void menuPrincipal() {
    int option;
    bool exit = false;

    while (!exit) {
        cout << "===========================================" << endl;
        cout << "Administrador de información de productos" << endl;
        cout << "==========================================" << endl;
        cout << "1. Administrar productos" << endl;
        cout << "2. Administrar categorias" << endl;
        cout << "3. Buscar y filtrar productos" << endl;
        cout << "4. Salir" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion (1-4): ";
        cin >> option;

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
    }
}

void menuProducto() {
    int option;

    do {
        std::cout << "\nMenu Producto" <<std::endl;
        std::cout << "\n1. Agregar nuevos productos" <<std::endl;
        std::cout << "2: Modificar productos existentes" <<std::endl;
        std::cout << "3: Eliminar productos" <<std::endl;
        std::cout << "4: Consultar productos" <<std::endl;
        std::cout << "0: Volver al menu principal" <<std::endl;
        std::cin >>option;

        switch (option) {
            case 1: agregarProducto();
            break;
            case 2: modificarProducto();
            break;
            case 3: eliminarProducto();
            break;
            case 4: consultarProcuto();
            break;
            break;
            case 0:
                std::cout << "Saliendo..." <<std::endl;
            break;
        }
    }
        while (option !=0);

}