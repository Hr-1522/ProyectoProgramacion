#include <iostream>
using namespace std;

// Declaración de submenús (los que vayas usando)
void menuArbolBinario();

int main() {
    int opcion;
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Cola\n";
        cout << "2. Pila\n";
        cout << "3. Arbol Binario\n";
        cout << "4. Arbol AVL\n";
        cout << "5. Arbol B\n";
        cout << "6. Arreglos\n";
        cout << "7. Tablas Hash\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            // case 1: menuCola(); break;
            // case 2: menuPila(); break;
        case 3: menuArbolBinario(); break;
            // case 4: menuArbolAvl(); break;
            // case 5: menuArbolB(); break;
            // case 6: menuArreglo(); break;
            // case 7: menuHash(); break;
        case 0: cout << "Hasta luego...\n"; break;
        default: cout << "Opción invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
