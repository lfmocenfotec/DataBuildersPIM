//
// Created by NachoM on 14/10/2024.
//

#include <iostream>
#include <string>
#include <limits>

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


void menuCategoria() {
    int option;
    bool exit = false;

    while (!exit) {
        cout << "===========================================" << endl;
        cout << "Categorías:" << endl;
        cout << "===========================================" << endl;
        cout << "1. Crear categoría" << endl;
        cout << "2. Editar categoría" << endl;
        cout << "3. Eliminar categoría" << endl;
        cout << "4. Consultar lista de categorías" << endl;
        cout << "5. Volver al menú principal" << endl;
        cout << "6. Salir" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opción (1-6): ";

        try {
            cin >> option;

            if (cin.fail()) {
                throw invalid_argument("Entrada inválida. Por favor, ingrese un número.");
            }

            switch (option) {
                case 1:
                    cout << "Crear categoría seleccionada." << endl;

                break;
                case 2:
                    cout << "Modificar categoría seleccionada." << endl;

                break;
                case 3:
                    cout << "Eliminar categoría seleccionada." << endl;

                break;
                case 4:
                    cout << "Consultar lista de categorías seleccionada." << endl;

                break;
                case 5:
                    cout << "Volviendo al menú principal..." << endl;
                exit = true;
                break;
                case 6:
                    cout << "Saliendo del sistema..." << endl;
                exit = true;
                break;
                default:
                    cout << "Opción inválida, inténtelo de nuevo." << endl;
                break;
            }
        } catch (const invalid_argument &e) {
            cout << e.what() << endl;
            cin.clear();  // Limpia el error del flujo
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta el resto de la entrada
        }
    }
}
