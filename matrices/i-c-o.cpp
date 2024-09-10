#include <vector>

using namespace std;

// Función para multiplicar dos matrices, transponiendo la segunda automáticamente
void mulMat2(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &rslt) {
    int filasMat2 = mat2.size();
    int columnasMat2 = mat2[0].size();
    vector<vector<int>> transposedMat2(columnasMat2, vector<int>(filasMat2));

    // Transponer la segunda matriz
    for (int i = 0; i < filasMat2; ++i) {
        for (int j = 0; j < columnasMat2; ++j) {
            transposedMat2[j][i] = mat2[i][j];
        }
    }

    int filasMat1 = mat1.size();
    int columnasMat1 = mat1[0].size();
    int columnasResultado = transposedMat2.size();

    // Redimensionar la matriz resultado
    rslt.assign(filasMat1, vector<int>(columnasResultado, 0));

    // Realizar la multiplicación
    for (int i = 0; i < filasMat1; ++i) {
        for (int j = 0; j < columnasResultado; ++j) {
            for (int k = 0; k < columnasMat1; ++k) {
                rslt[i][j] += mat1[i][k] * transposedMat2[j][k];
            }
        }
    }
}



