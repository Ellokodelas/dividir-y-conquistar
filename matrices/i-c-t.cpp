#include <vector>

using namespace std;

// Función para multiplicar dos matrices
void mulMat(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &rslt) {
    int filasMat1 = mat1.size();
    int columnasMat1 = mat1[0].size();
    int filasMat2 = mat2.size();
    int columnasMat2 = mat2[0].size();

    // Redimensionar la matriz resultado
    rslt.assign(filasMat1, vector<int>(columnasMat2, 0));

    // Realizar la multiplicación
    for (int i = 0; i < filasMat1; ++i) {
        for (int j = 0; j < columnasMat2; ++j) {
            for (int k = 0; k < columnasMat1; ++k) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}



