#include <vector>
#include <iostream>

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Función para restar dos matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Función para multiplicar dos matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    int m = B[0].size();
    int l = B.size();
    vector<vector<int>> C(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < l; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Función para dividir una matriz en cuatro submatrices
void splitMatrix(const vector<vector<int>> &M, vector<vector<int>> &A, vector<vector<int>> &B,
                 vector<vector<int>> &C, vector<vector<int>> &D) {
    int n = M.size();
    int m = M[0].size();
    int midN = n / 2;
    int midM = m / 2;

    A.resize(midN, vector<int>(midM));
    B.resize(midN, vector<int>(midM));
    C.resize(midN, vector<int>(midM));
    D.resize(midN, vector<int>(midM));

    for (int i = 0; i < midN; ++i) {
        for (int j = 0; j < midM; ++j) {
            A[i][j] = M[i][j];
            B[i][j] = M[i][j + midM];
            C[i][j] = M[i + midN][j];
            D[i][j] = M[i + midN][j + midM];
        }
    }
}

// Función principal de Strassen
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    int m = B[0].size();
    int l = B.size();

    // Caso base para matrices 1x1
    if (n == 1 || l == 1 || m == 1) {
        return multiplyMatrices(A, B);
    }

    // Dividir las matrices
    vector<vector<int>> A11, A12, A21, A22;
    vector<vector<int>> B11, B12, B21, B22;

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    // Calcular las matrices intermedias
    vector<vector<int>> M1 = strassen(addMatrices(A11, A22), addMatrices(B11, B22));
    vector<vector<int>> M2 = strassen(addMatrices(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtractMatrices(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtractMatrices(B21, B11));
    vector<vector<int>> M5 = strassen(addMatrices(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtractMatrices(A21, A11), addMatrices(B11, B12));
    vector<vector<int>> M7 = strassen(subtractMatrices(A12, A22), addMatrices(B21, B22));

    // Calcular los bloques de la matriz resultado
    vector<vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = addMatrices(M3, M5);
    vector<vector<int>> C21 = addMatrices(M2, M4);
    vector<vector<int>> C22 = subtractMatrices(subtractMatrices(addMatrices(M1, M3), M2), M6);

    // Reconstruir la matriz resultado
    vector<vector<int>> C(n, vector<int>(m));
    int midN = n / 2;
    int midM = m / 2;

    for (int i = 0; i < midN; ++i) {
        for (int j = 0; j < midM; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + midM] = C12[i][j];
            C[i + midN][j] = C21[i][j];
            C[i + midN][j + midM] = C22[i][j];
        }
    }

    return C;
}
