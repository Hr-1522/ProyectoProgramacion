#include <iostream>
#include <limits> // Para limpiar errores de entrada
using namespace std;

const int TAMANO_MAXIMO = 100;

class Cola {
private:
    int datos[TAMANO_MAXIMO];
    int frente, final;

public:
    Cola() {
        frente = 0;
        final = -1;
    }

    bool estaVacia() {
        return frente > final;
    }

    bool estaLlena() {
        return final == TAMANO_MAXIMO - 1;
    }

    void agregar(int numero) {
        if (estaLlena()) {
            cout << "La cola esta llena. No se puede agregar mas.\n";
            return;
        }
        final++;
        datos[final] = numero;
        cout << "Número agregado a la cola.\n";
    }

    void quitar() {
        if (estaVacia()) {
            cout << "La cola esta vacía. No hay elementos para quitar.\n";
            return;
        }
        cout << "Numero " << datos[frente] << " eliminado de la cola.\n";
        frente++;
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        cout << "Elementos en la cola (de primero a último):\n";
        for (int i = frente; i <= final; i++) {
            cout << datos[i] << " ";
        }
        cout << "\n";
    }

    void borrarTodo() {
        char confirmacion;
        cout << "ADVERTENCIA: Esta accion borrara toda la cola. ¿Está seguro? (s/n): ";
        cin >> confirmacion;
        if (confirmacion == 's' || confirmacion == 'S') {
            frente = 0;
            final = -1;
            cout << "Toda la cola ha sido borrada.\n";
        }
        else {
            cout << "Operación cancelada.\n";
        }
    }
};

// Función que asegura solo ingresar números válidos
int obtenerNumeroSeguro() {
    int numero;
    while (true) {
        cin >> numero;
        if (!cin.fail()) {
            return numero;
        }
        else {
            cout << "Entrada inválida. Por favor ingrese un número: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void menuCola() {
    Cola cola;
    int opcion;

    do {
        cout << "\n--- MENU DE COLA ---\n";
        cout << "1. Insertar datos\n";
        cout << "2. Eliminar datos\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Borrar toda la cola\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        opcion = obtenerNumeroSeguro();
        system("cls");

        switch (opcion) {
        case 1:
            cout << "Ingrese el numero a agregar: ";
            cola.agregar(obtenerNumeroSeguro());
            break;
        case 2:
            cola.quitar();
            break;
        case 3:
            cola.mostrar();
            break;
        case 4:
            cola.borrarTodo();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

   // return 0;
}
