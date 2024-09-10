#include <fstream>
#include <vector>

using namespace std;

// Función para leer una matriz del archivo en el nuevo formato
vector<vector<int>> leerMatriz(ifstream &archivo, int &filas, int &columnas) {
    archivo >> filas >> columnas;
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }
    return matriz;
}

// Función para leer todas las matrices del archivo
vector<vector<vector<int>>> leerTodasLasMatrices(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo!");
    }

    int filas, columnas;
    vector<vector<vector<int>>> matrices; // Contendrá todas las matrices leídas

    while (archivo >> filas >> columnas) { // Intentamos leer filas y columnas directamente
        vector<vector<int>> matriz(filas, vector<int>(columnas));
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                archivo >> matriz[i][j];
            }
        }
        matrices.push_back(matriz);
    }

    archivo.close();
    return matrices;
}


