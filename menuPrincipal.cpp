#include <iostream>
using namespace std;

// Declaración de submenus
//void menuLista();
//void menuCola();
//void menuPila();
//void menuArbol();
void menuArbolBinario();
//void menuArbolAVL();
//void menuArbolB();
//void menuHash();

int main() {
    int opcion;
    do {
        cout << "\n=====================================\n";
        cout << "        SISTEMA DE ESTRUCTURAS       \n";
        cout << "=====================================\n";
        cout << "| 1. Lista                          |\n";
        cout << "| 2. Cola                           |\n";
        cout << "| 3. Pila                           |\n";
        cout << "| 4. Arbol                          |\n";
        cout << "| 5. Arbol Binario                  |\n";
        cout << "| 6. Arbol AVL                      |\n";
        cout << "| 7. Arbol B                        |\n";
        cout << "| 8. Tabla Hash                     |\n";
        cout << "| 9. Salir                          |\n";
        cout << "=====================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        // Validacion de entrada
        while (cin.fail() || opcion < 1 || opcion > 9) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcion invalida. Ingrese un numero entre 0 y 8: ";
            cin >> opcion;
        }

        system("cls");

        switch (opcion) {
            //case 1: menuLista(); break;
           // case 2: menuCola(); break;
           // case 3: menuPila(); break;
           // case 4: menuArbol(); break;
        case 5: menuArbolBinario(); break;
            //case 6: menuArbolAVL(); break;
           // case 7: menuArbolB(); break;
           // case 8: menuHash(); break;
        case 9:
            char confirm;
            cout << "¿Esta seguro que desea salir? (s/n): ";
            cin >> confirm;
            if (confirm == 's' || confirm == 'S') {
                cout << "Hasta luego...\n";
                return 0;
            }
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (true);

    return 0;
}
