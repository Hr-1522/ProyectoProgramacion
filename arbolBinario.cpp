#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), izq(nullptr), der(nullptr) {}
};

// Clase Árbol Binario
class ArbolBinario {
private:
    Nodo* raiz;

    void insertar(Nodo*& nodo, int val) {
        if (!nodo)
            nodo = new Nodo(val);
        else if (val < nodo->dato)
            insertar(nodo->izq, val);
        else
            insertar(nodo->der, val);
    }

    bool buscar(Nodo* nodo, int val) {
        if (!nodo) return false;
        if (nodo->dato == val) return true;
        return val < nodo->dato ? buscar(nodo->izq, val) : buscar(nodo->der, val);
    }

    void inOrden(Nodo* nodo) {
        if (!nodo) return;
        inOrden(nodo->izq);
        cout << nodo->dato << " ";
        inOrden(nodo->der);
    }

    void preOrden(Nodo* nodo) {
        if (!nodo) return;
        cout << nodo->dato << " ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }

    void postOrden(Nodo* nodo) {
        if (!nodo) return;
        postOrden(nodo->izq);
        postOrden(nodo->der);
        cout << nodo->dato << " ";
    }

    Nodo* encontrarMinimo(Nodo* nodo) {
        while (nodo && nodo->izq)
            nodo = nodo->izq;
        return nodo;
    }

    Nodo* eliminar(Nodo* nodo, int val) {
        if (!nodo) return nullptr;
        if (val < nodo->dato)
            nodo->izq = eliminar(nodo->izq, val);
        else if (val > nodo->dato)
            nodo->der = eliminar(nodo->der, val);
        else {
            if (!nodo->izq) {
                Nodo* temp = nodo->der;
                delete nodo;
                return temp;
            }
            else if (!nodo->der) {
                Nodo* temp = nodo->izq;
                delete nodo;
                return temp;
            }
            Nodo* sucesor = encontrarMinimo(nodo->der);
            nodo->dato = sucesor->dato;
            nodo->der = eliminar(nodo->der, sucesor->dato);
        }
        return nodo;
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(int val) { insertar(raiz, val); }

    bool buscar(int val) { return buscar(raiz, val); }

    void eliminar(int val) { raiz = eliminar(raiz, val); }

    void mostrarInOrden() { inOrden(raiz); cout << endl; }

    void mostrarPreOrden() { preOrden(raiz); cout << endl; }

    void mostrarPostOrden() { postOrden(raiz); cout << endl; }
};

// Función del submenú del árbol binario
void menuArbolBinario() {
    ArbolBinario arbol;
    int opcion;
    do {
        system("cls");
        cout << "--- MENU ARBOL BINARIO ---\n";
        cout << "1. Insertar valor\n";
        cout << "2. Buscar valor\n";
        cout << "3. Eliminar valor\n";
        cout << "4. Recorrido Inorden\n";
        cout << "5. Recorrido Preorden\n";
        cout << "6. Recorrido Postorden\n";
        cout << "7. Regresar al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int val;
            cout << "Ingrese valor: ";
            cin >> val;
            arbol.insertar(val);
            break;
        }
        case 2: {
            int val;
            cout << "Ingrese valor a buscar: ";
            cin >> val;
            cout << (arbol.buscar(val) ? "Encontrado\n" : "No encontrado\n");
            break;
        }
        case 3: {
            int val;
            cout << "Ingrese valor a eliminar: ";
            cin >> val;
            arbol.eliminar(val);
            break;
        }
        case 4: cout << "Inorden: "; arbol.mostrarInOrden(); break;
        case 5: cout << "Preorden: "; arbol.mostrarPreOrden(); break;
        case 6: cout << "Postorden: "; arbol.mostrarPostOrden(); break;
        case 7: cout << "Volviendo al menú principal...\n"; break;
        default: cout << "Opción inválida\n";
        }
        system("pause");
    } while (opcion != 7);
}
