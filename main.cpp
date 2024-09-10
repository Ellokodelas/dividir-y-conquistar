#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>

// Declaraciones de funciones (prototipos)
//arrays.emplace_back(listSize, numbers);
void bubbleSort(int array[], int size);
void mergeSort(int array[],int initial, int size);
void quickSort(int array[], int low, int high);
std::vector<std::pair<int, std::vector<int>>> readArraysFromFile(const std::string& filename);
void guardarArraysEnArchivo(const std::vector<std::pair<int, std::vector<int>>>& arrays, const std::string& nombreArchivo);

int main() {
    std::vector<std::pair<int, std::vector<int>>> arrays = readArraysFromFile("dataset.txt");
    
    std::cout << "¿Cuál ordenamiento desea hacer?\n1. Estándar\n2. Bubble\n3. Merge\n4. Quick\nFavor de poner solo el número: ";
    int opcion;
    std::cin >> opcion;
    auto start = std::chrono::steady_clock::now();
    switch (opcion) {
    case 1:
        for (auto& pair : arrays) {
            std::sort(pair.second.begin(), pair.second.end());
        }
        break;
    case 2:
        for (auto& pair : arrays) {
            bubbleSort(pair.second.data(), pair.second.size());
        }
        break;
    case 3:
        for (auto& pair : arrays) {
            mergeSort(pair.second.data(), 0 ,pair.second.size());
        }
        break;
    case 4:
        for (auto& pair : arrays) {
            quickSort(pair.second.data(), 0 ,pair.second.size()-1);
        }
        break;
    default:
        std::cerr << "Opción no válida\n";
        return 1;
    }
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "Tiempo transcurrido: " << duration.count() << "ns\n";

    // Guardar cada array en el archivo
    guardarArraysEnArchivo(arrays, "resultados.txt");

    return 0;
}