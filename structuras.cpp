#include <iostream>
#include <string>
#include <limits> // Para limpiar el buffer correctamente
using namespace std;

// -------------------------
// Estructuras principales
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
// Funciones auxiliares
// -------------------------

// Imprime líneas decorativas
void printSeparator(char symbol = '=', int length = 50) {
    for (int i = 0; i < length; i++)
        cout << symbol;
    cout << endl;
}

// Lee y valida una nota con un rango máximo permitido
int leerNota(const string& etiqueta, int maxPuntos) {
    int nota;
    while (true) {
        cout << "   • " << etiqueta << " (0 - " << maxPuntos << " pts): ";
        cin >> nota;

        if (!cin.fail() && nota >= 0 && nota <= maxPuntos)
            return nota;

        cout << "⚠️  Nota inválida. Por favor ingresa un valor entre 0 y " << maxPuntos << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// -------------------------
// Programa principal
// -------------------------
int main() {
    int total;

    cout << "\n";
    printSeparator('=');
    cout << "\t🎓 BIENVENIDO A LA CLASE DE STRUCT - UMG 🎓\n";
    printSeparator('=');
    cout << "\n¿Cuántos estudiantes desea ingresar?: ";
    cin >> total;
    cin.ignore();

    Student students[total];
    Student abanderado;
    int mayorNota = -1;

    // Ciclo para ingresar estudiantes
    for (int i = 0; i < total; i++) {
        printSeparator('-');
        cout << "📘 Ingreso de datos del alumno #" << i + 1 << endl;
        printSeparator('-');

        Student student;

        cout << "🧍 Nombre completo: ";
        getline(cin, student.name);

        cout << "📧 Correo electrónico: ";
        getline(cin, student.email);

        cout << "🏫 Código de carrera: ";
        getline(cin, student.carne.code);

        cout << "📅 Año de carrera: ";
        cin >> student.carne.year;

        cout << "🔢 Número de estudiante: ";
        cin >> student.carne.number;
        cin.ignore();

        cout << "\n🧾 Ingrese las notas de " << student.name << ":\n";

        // Validación según nuevo sistema de puntos
        student.note.parcial1 = leerNota("Primer parcial", 15);
        student.note.parcial2 = leerNota("Segundo parcial", 15);
        student.note.actividades = leerNota("Actividades", 35);
        student.note.examenfinal = leerNota("Examen final", 35);

        // Calcular total
        student.note.sumatoria = student.note.parcial1 +
                                 student.note.parcial2 +
                                 student.note.actividades +
                                 student.note.examenfinal;

        // Guardar estudiante
        students[i] = student;

        // Actualizar abanderado
        if (student.note.sumatoria > mayorNota) {
            mayorNota = student.note.sumatoria;
            abanderado = student;
        }

        cout << "\n✅ Alumno registrado con éxito.\n\n";
    }

    // Mostrar listado de estudiantes
    cout << "\n\n";
    printSeparator('=');
    cout << "\t📄 LISTADO DE ESTUDIANTES 📄\n";
    printSeparator('=');

    for (int i = 0; i < total; i++) {
        Student s = students[i];
        cout << "\n👨‍🎓 Alumno #" << i + 1 << endl;
        printSeparator('.');
        cout << "Nombre: " << s.name << endl;
        cout << "Correo: " << s.email << endl;
        cout << "Carné: " << s.carne.code << "-" << s.carne.year << "-" << s.carne.number << endl;
        cout << "Nota total: " << s.note.sumatoria << " / 100" << endl;
    }

    // Mostrar abanderado
    cout << "\n\n";
    printSeparator('=');
    cout << "\t🏅 ABANDERADO DEL GRUPO 🏅\n";
    printSeparator('=');
    cout << "👑 Nombre: " << abanderado.name << endl;
    cout << "📧 Correo: " << abanderado.email << endl;
    cout << "🏷️  Carné: " << abanderado.carne.code << "-" << abanderado.carne.year << "-" << abanderado.carne.number << endl;
    cout << "📊 Nota total: " << abanderado.note.sumatoria << " / 100" << endl;
    printSeparator('=');

    cout << "\n🎉 ¡Felicidades al abanderado del grupo! 🎉\n\n";

    return 0;
}
