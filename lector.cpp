#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::pair<int, std::vector<int>>> readArraysFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para leer.\n";
        return {};
    }

    std::vector<std::pair<int, std::vector<int>>> arrays;
    int listSize;

    // Leer hasta el final del archivo
    while (inFile >> listSize) {
        std::vector<int> numbers(listSize);
        for (int i = 0; i < listSize; ++i) {
            inFile >> numbers[i];
        }
        arrays.emplace_back(listSize, numbers); // Guardar el tamaño y el array leído como un par
    }

    inFile.close();
    return arrays;
}
