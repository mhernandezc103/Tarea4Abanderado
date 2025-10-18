#include <iostream>
#include <string>
#include <limits>
using namespace std;

// -------------------------
// Estructuras
// -------------------------
struct Carne {
    string code;
    int year;
    int number;
};

struct Note {
    int parcial1;
    int parcial2;
    int actividades;
    int examenfinal;
    int sumatoria;
};

struct Student {
    string name;
    string email;
    Note note;
    Carne carne;
};

// -------------------------
// Utilidades
// -------------------------
void printSeparator(char symbol = '=', int length = 50) {
    for (int i = 0; i < length; i++)
        cout << symbol;
    cout << endl;
}

// Entrada validada de nota con límite máximo
int leerNota(const string& etiqueta, int maxPuntos) {
    int nota;
    while (true) {
        cout << "   - " << etiqueta << " (0 - " << maxPuntos << " pts): ";
        cin >> nota;

        if (!cin.fail() && nota >= 0 && nota <= maxPuntos)
            return nota;

        cout << "Error: nota inválida. Ingrese un valor entre 0 y " << maxPuntos << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// -------------------------
// Programa principal
// -------------------------
int main() {
    int total;

    printSeparator('=');
    cout << "\tBIENVENIDO A LA CLASE DE STRUCT - UMG\n";
    printSeparator('=');
    cout << "\nCantidad de estudiantes a ingresar: ";
    cin >> total;
    cin.ignore();

    Student students[total];
    Student abanderado;
    int mayorNota = -1;

    for (int i = 0; i < total; i++) {
        printSeparator('-');
        cout << "Registro del estudiante #" << i + 1 << endl;
        printSeparator('-');

        Student student;

        cout << "Nombre completo: ";
        getline(cin, student.name);

        cout << "Correo electrónico: ";
        getline(cin, student.email);

        cout << "Código de carrera: ";
        getline(cin, student.carne.code);

        cout << "Año de carrera: ";
        cin >> student.carne.year;

        cout << "Número de estudiante: ";
        cin >> student.carne.number;
        cin.ignore();

        cout << "\nIngrese las notas de " << student.name << ":\n";

        // Rango de puntos actualizado
        student.note.parcial1 = leerNota("Primer parcial", 15);
        student.note.parcial2 = leerNota("Segundo parcial", 15);
        student.note.actividades = leerNota("Actividades", 35);
        student.note.examenfinal = leerNota("Examen final", 35);

        // Cálculo total
        student.note.sumatoria = student.note.parcial1 +
                                 student.note.parcial2 +
                                 student.note.actividades +
                                 student.note.examenfinal;

        students[i] = student;

        // Evaluación de abanderado
        if (student.note.sumatoria > mayorNota) {
            mayorNota = student.note.sumatoria;
            abanderado = student;
        }

        cout << "\nEstudiante registrado correctamente.\n\n";
    }

    // Listado general
    printSeparator('=');
    cout << "\tLISTADO DE ESTUDIANTES\n";
    printSeparator('=');

    for (int i = 0; i < total; i++) {
        Student s = students[i];
        cout << "\nEstudiante #" << i + 1 << endl;
        printSeparator('.');
        cout << "Nombre: " << s.name << endl;
        cout << "Correo: " << s.email << endl;
        cout << "Carné: " << s.carne.code << "-" << s.carne.year << "-" << s.carne.number << endl;
        cout << "Nota total: " << s.note.sumatoria << " / 100" << endl;
    }

    // Resultado del abanderado
    printSeparator('=');
    cout << "\tABANDERADO DEL GRUPO\n";
    printSeparator('=');
    cout << "Nombre: " << abanderado.name << endl;
    cout << "Correo: " << abanderado.email << endl;
    cout << "Carné: " << abanderado.carne.code << "-" << abanderado.carne.year << "-" << abanderado.carne.number << endl;
    cout << "Nota total: " << abanderado.note.sumatoria << " / 100" << endl;
    printSeparator('=');

    cout << "\nFin del programa.\n";

    return 0;
}
