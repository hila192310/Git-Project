#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
    string prioridad;
};

// Prototipos de las funciones
void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion = 0;

    while (opcion != 4) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;

            case 2:
                mostrarTareas(tareas);
                break;

            case 3:
                completarTarea(tareas);
                break;

            case 4:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// Agrega una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    Tarea nueva;

    cout << "Ingrese la tarea: ";
    getline(cin, nueva.descripcion);

    if (nueva.descripcion == "") {
        cout << "La tarea no puede estar vacía.\n";
        return;
    }

    cout << "Ingrese la prioridad (Alta, Media o Baja): ";
    getline(cin, nueva.prioridad);

    nueva.completada = false;

    tareas.push_back(nueva);

    cout << "Tarea agregada correctamente.\n";
}

// Muestra todas las tareas
void mostrarTareas(const vector<Tarea>& tareas) {
    cout << "\nTAREAS\n";

    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }

    for (int i = 0; i < tareas.size(); i++) {
        cout << i + 1 << ". ";

        if (tareas[i].completada == true) {
            cout << "[Completada] ";
        } else {
            cout << "[Pendiente] ";
        }

        cout << "[" << tareas[i].prioridad << "] ";
        cout << tareas[i].descripcion << endl;
    }
}

// Marca una tarea como completada
void completarTarea(vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "No hay tareas registradas.\n";
        return;
    }

    mostrarTareas(tareas);

    int numeroTarea;

    cout << "Seleccione la tarea: ";
    cin >> numeroTarea;

    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "La opción no es válida.\n";
        return;
    }

    tareas[numeroTarea - 1].completada = true;

    cout << "Tarea marcada como completada.\n";
}