#include <iostream>
#include <limits> // Para limpiar errores de entrada
using namespace std;

const int TAMANO_MAXIMO = 100;

class Pila {
private:
    int datos[TAMANO_MAXIMO];
    int tope;

public:
    Pila() {
        tope = -1;
    }

    bool estaVacia() {
        return tope == -1;
    }

    bool estaLlena() {
        return tope == TAMANO_MAXIMO - 1;
    }

    void agregar(int numero) {
        if (estaLlena()) {
            cout << "La pila esta llena, no se puede agregar mas.\n";
            return;
        }
        tope++;
        datos[tope] = numero;
        cout << "Número agregado a la pila.\n";
    }

    void quitar() {
        if (estaVacia()) {
            cout << "La pila esta vacia, no hay elementos para quitar.\n";
            return;
        }
        cout << "Numero " << datos[tope] << " eliminado de la pila.\n";
        tope--;
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacía.\n";
            return;
        }
        cout << "Elementos en la pila (de arriba hacia abajo):\n";
        for (int i = tope; i >= 0; i--) {
            cout << datos[i] << "\n";
        }
    }

    void borrarTodo() {
        char confirmacion;
        cout << "ADVERTENCIA: Esta accion borrara toda la pila. ¿Esta seguro? (s/n): ";
        cin >> confirmacion;
        if (confirmacion == 's' || confirmacion == 'S') {
            tope = -1;
            cout << "Toda la pila ha sido borrada.\n";
        }
        else {
            cout << "Operacion cancelada.\n";
        }
    }
};

// Función para evitar errores con letras u otros caracteres
int obtenerNumeroSeguro1() {
    int numero;
    while (true) {
        cin >> numero;
        if (!cin.fail()) {
            return numero;
        }
        else {
            cout << "Entrada invalida. Por favor ingrese un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void menuPila() {
    Pila pila;
    int opcion;

    do {
        cout << "\n--- MENU DE PILA ---\n";
        cout << "1. Insertar datos\n";
        cout << "2. Eliminar datos\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Borrar toda la pila\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        opcion = obtenerNumeroSeguro1();
        system("cls");
        switch (opcion) {
        case 1:
            cout << "Ingrese el numero a agregar: ";
            pila.agregar(obtenerNumeroSeguro1());
            break;
        case 2:
            pila.quitar();
            break;
        case 3:
            pila.mostrar();
            break;
        case 4:
            pila.borrarTodo();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    //return 0;
}
