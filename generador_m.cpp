#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función para generar una matriz aleatoria
vector<int> generarMatriz(int filas, int columnas) {
    vector<int> matriz(filas * columnas);
    for (int i = 0; i < filas * columnas; ++i) {
        matriz[i] = rand() % 1000; // Números aleatorios entre 0 y 999
    }
    return matriz;
}

// Función para guardar la matriz en el archivo
void guardarMatriz(ofstream &archivo, int filas, int columnas, const vector<int> &matriz) {
    archivo << filas << " " << columnas << "\n";
    for (int i = 0; i < filas * columnas; ++i) {
        archivo << matriz[i] << " ";
    }
    archivo << "\n";
}

int main() {
    srand(time(0));
    ofstream archivo("dataset_m.txt");

    // Dimensiones específicas de las matrices
    int filas1 = 1000;
    int columnas1 = 512;
    int filas2 = 512;
    int columnas2 = 300;
    int n_matrices=10;

    for (int i = 0; i < n_matrices; ++i) {
        // Generación de matrices cuadradas
        vector<int> matriz1 = generarMatriz(filas1, columnas1);
        vector<int> matriz2 = generarMatriz(filas2, columnas2);

        guardarMatriz(archivo, filas1, columnas1, matriz1);
        guardarMatriz(archivo, filas2, columnas2, matriz2);
    }
    archivo.close();
    cout << "Dataset generado en dataset_m.txt" << endl;

    return 0;
}


