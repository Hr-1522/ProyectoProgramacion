#include <iostream>
using namespace std;

// Definición de un nodo de lista enlazada
struct Nodo {
    int dato;          // Valor del nodo
    Nodo* siguiente;   // Puntero al siguiente nodo

    // Constructor
    Nodo(int val) : dato(val), siguiente(nullptr) {}
};

// Clase Lista Enlazada Simple
class Lista {
private:
    Nodo* cabeza;

public:
    // Constructor
    Lista() : cabeza(nullptr) {}

    // Insertar al final
    void insertar(int val) {
        Nodo* nuevo = new Nodo(val);
        if (!cabeza) {
            cabeza = nuevo;
        }
        else {
            Nodo* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
    }

    // Mostrar la lista
    void mostrar() {
        Nodo* temp = cabeza;
        while (temp) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "NULL\n";
    }

    // Eliminar un nodo por valor
    void eliminar(int val) {
        if (!cabeza) return;

        if (cabeza->dato == val) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato != val) {
            actual = actual->siguiente;
        }

        if (actual->siguiente) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
        }
    }

    // Destructor: liberar la memoria
    ~Lista() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

// Función principal de prueba
int main() {
    Lista miLista;

    miLista.insertar(10);
    miLista.insertar(20);
    miLista.insertar(30);

    cout << "Lista inicial: ";
    miLista.mostrar();

    cout << "Eliminando 20...\n";
    miLista.eliminar(20);

    cout << "Lista después de eliminar: ";
    miLista.mostrar();

    return 0;
}
