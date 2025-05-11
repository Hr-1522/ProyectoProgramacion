#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MIN_DEGREE = 2; // El grado m�nimo de un �rbol B (n�mero m�nimo de hijos de un nodo)

struct NodoB {
    vector<int> keys;           // Claves del nodo
    vector<NodoB*> children;    // Punteros a los hijos
    bool leaf;                  // Si el nodo es hoja

    NodoB(bool isLeaf) : leaf(isLeaf) {}
};

class ArbolB {
private:
    NodoB* root;

    void insertarNoLleno(NodoB* node, int key) {
        int i = node->keys.size() - 1;

        if (node->leaf) {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            node->keys.insert(node->keys.begin() + i + 1, key);
        }
        else {
            while (i >= 0 && key < node->keys[i]) {
                i--;
            }
            i++;

            if (node->children[i]->keys.size() == 2 * MIN_DEGREE - 1) {
                dividirNodo(node, i);
                if (key > node->keys[i]) {
                    i++;
                }
            }
            insertarNoLleno(node->children[i], key);
        }
    }

    void dividirNodo(NodoB* parent, int index) {
        NodoB* node = parent->children[index];
        NodoB* newNode = new NodoB(node->leaf);
        int mid = node->keys.size() / 2;

        parent->keys.insert(parent->keys.begin() + index, node->keys[mid]);
        parent->children.insert(parent->children.begin() + index + 1, newNode);

        newNode->keys.assign(node->keys.begin() + mid + 1, node->keys.end());
        node->keys.resize(mid);

        if (!node->leaf) {
            newNode->children.assign(node->children.begin() + mid + 1, node->children.end());
            node->children.resize(mid + 1);
        }
    }

    void mostrarInOrden(NodoB* node) {
        if (node != nullptr) {
            int i = 0;
            while (i < node->keys.size()) {
                mostrarInOrden(node->children[i]);
                cout << node->keys[i] << " ";
                i++;
            }
            mostrarInOrden(node->children[i]);
        }
    }

public:
    ArbolB() {
        root = new NodoB(true);
    }

    void insertar(int key) {
        if (root->keys.size() == 2 * MIN_DEGREE - 1) {
            NodoB* newRoot = new NodoB(false);
            newRoot->children.push_back(root);
            dividirNodo(newRoot, 0);
            root = newRoot;
        }
        insertarNoLleno(root, key);
    }

    void mostrarInOrden() {
        mostrarInOrden(root);
        cout << endl;
    }
};

// Funci�n del submen� del �rbol B
void menuArbolB() {
    ArbolB arbol;
    int opcion;
    do {
        // system("cls"); // Puede no funcionar en sistemas no-Windows.
        cout << "--- MENU ARBOL B ---\n";
        cout << "1. Insertar valor\n";
        cout << "2. Recorrido Inorden\n";
        cout << "3. Regresar al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        // Validaci�n de entradas no num�ricas
        while (cin.fail()) {
            cout << "Opci�n inv�lida. Por favor ingrese un n�mero: ";
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la entrada
            cin >> opcion;
        }

        switch (opcion) {
        case 1: {
            int val;
            cout << "Ingrese valor: ";
            cin >> val;
            arbol.insertar(val);
            break;
        }
        case 2: arbol.mostrarInOrden(); break;
        case 3: cout << "Volviendo al men� principal...\n"; break;
        default: cout << "Opci�n inv�lida\n";
        }

        // system("pause"); // Alternativa: usar cin.get() para esperar la entrada.
        cout << "\nPresione Enter para continuar...";
        cin.ignore();
        cin.get();
    } while (opcion != 3);
}
