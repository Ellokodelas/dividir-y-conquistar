#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> leerTodasLasMatrices(const string& filename);
void guardarMatrices(const vector<vector<vector<int>>> &matriz, const string &filename);
void mulMat(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &rslt);
void mulMat2(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2, vector<vector<int>> &rslt);
vector<vector<int>> strassen(const vector<vector<int>> &a, const vector<vector<int>> &b);

int main() {
    // Leer todas las matrices desde el archivo "dataset_m.txt"
    vector<vector<vector<int>>> matrices = leerTodasLasMatrices("dataset_m.txt");

    if (matrices.size() < 2) {
        cout << "Se requieren al menos dos matrices para realizar las multiplicaciones." << endl;
        return 1;
    }

    cout << "Que algoritmo de multiplicar matrices quieres usar?\n1. Normal\n2. Optimizado\n3. Strassen" << endl;
    int opcion;
    cin >> opcion;

    vector<vector<vector<int>>> resultados; // Contendrá todas las matrices resultado
    auto start = std::chrono::steady_clock::now();

    switch(opcion) {
        case 1:
            cout << "Usando el algoritmo normal" << endl;
            for (size_t i = 0; i + 1 < matrices.size(); i += 2) {
                vector<vector<int>> mat1 = matrices[i];
                vector<vector<int>> mat2 = matrices[i + 1];
                vector<vector<int>> resultado;
                
                mulMat(mat1, mat2, resultado);
                resultados.push_back(resultado);
            }
            break;

        case 2:
            cout << "Usando el algoritmo optimizado" << endl;
            for (size_t i = 0; i + 1 < matrices.size(); i += 2) {
                vector<vector<int>> mat1 = matrices[i];
                vector<vector<int>> mat2 = matrices[i + 1];
                vector<vector<int>> resultado;
                
                mulMat2(mat1, mat2, resultado);
                resultados.push_back(resultado);
            }
            break;

        case 3:
            cout << "Usando el algoritmo de Strassen" << endl;
            for (size_t i = 0; i + 1 < matrices.size(); i += 2) {
                vector<vector<int>> mat1 = matrices[i];
                vector<vector<int>> mat2 = matrices[i + 1];
                
                vector<vector<int>> resultado = strassen(mat1, mat2);
                resultados.push_back(resultado);
            }
            break;

        default:
            cout << "Opción no válida" << endl;
            return 1;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Tiempo transcurrido: " << duration.count() << "ns\n";

    // Guardar todos los resultados en un archivo
    guardarMatrices(resultados, "resultados_m.txt");

    return 0;
}
