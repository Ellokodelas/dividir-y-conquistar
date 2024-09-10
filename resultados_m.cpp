#include <fstream>
#include <vector>
#include <iomanip> // Para std::setw

using namespace std;

// Función para guardar múltiples matrices en un archivo con formato específico
void guardarMatrices(const vector<vector<vector<int>>> &matrices, const string &nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo para escritura!");
    }

    // Iterar sobre cada matriz
    for (const auto &matriz : matrices) {
        // Escribir la matriz en el formato requerido
        int filas = matriz.size();
        int columnas = matriz[0].size();
        
        archivo << filas << " " << columnas << endl; // Escribir filas y columnas

        for (const auto &fila : matriz) {
            for (const auto &elem : fila) {
                archivo << setw(5) << elem << " "; // Ajustar el ancho según sea necesario
            }
            archivo << endl;
        }
        archivo << endl; // Línea en blanco entre matrices
    }

    archivo.close();
}

