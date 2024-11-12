
#include <Windows.h>  // Asegúrate de que tienes acceso a este encabezado

#include <sql.h>
#include <sqlext.h>
#include <string>
#include <cstdint>  // Para int64_t
#ifndef INT64
#define INT64 __int64
#endif

#ifndef UINT64
#define UINT64 unsigned __int64
#endif

int main() {
    // Define los detalles de conexión
    std::string server = "srv-db-jmmirandah202401";  // Dirección del servidor
    std::string database = "AssetsDB";               // Nombre de la base de datos
    std::string username = "Sysman";                 // Usuario
    std::string password = "Cenfotec123!";           // Contraseña
    std::string port = "1433";                       // Puerto por defecto de SQL Server

    // Crear la cadena de conexión ODBC
    std::string connectionString = 
        "Driver={ODBC Driver 18 for SQL Server};"      // Asegúrate de que coincide con el nombre del controlador instalado
        "Server=" + server + "," + port + ";"
        "Database=" + database + ";"
        "Uid=" + username + ";"
        "Pwd=" + password + ";"
        "Encrypt=yes;TrustServerCertificate=no;Connection Timeout=30;";

    // Mostrar la cadena de conexión configurada
    std::cout << "Cadena de conexión configurada: " << connectionString << std::endl;

    // Variables para manejar la conexión ODBC
    SQLHENV env; // Manejador de entorno
    SQLHDBC dbc; // Manejador de conexión
    SQLRETURN ret; // Variable para almacenar el resultado de las operaciones ODBC

    // Inicializar el entorno ODBC
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "Error al asignar el manejador de entorno." << std::endl;
        return -1;
    }

    // Configurar el entorno ODBC para la versión de SQL Server
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "Error al configurar la versión de ODBC." << std::endl;
        return -1;
    }

    // Asignar el manejador de conexión
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        std::cerr << "Error al asignar el manejador de conexión." << std::endl;
        return -1;
    }

    // Conectar a la base de datos usando la cadena de conexión
    ret = SQLDriverConnect(dbc, NULL, (SQLCHAR*)connectionString.c_str(), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
        std::cout << "Conexión exitosa a la base de datos." << std::endl;
    } else {
        std::cerr << "Error al conectar a la base de datos." << std::endl;
        return -1;
    }

    // Cerrar la conexión y liberar los recursos
    SQLDisconnect(dbc);
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);

    return 0;
}
