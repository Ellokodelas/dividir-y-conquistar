#include <iostream>
#include <fstream>
#include <vector>

void guardarArraysEnArchivo(const std::vector<std::pair<int, std::vector<int>>>& arrays, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const auto& pair : arrays) {
            archivo << pair.first << "\n"; // Guardar la longitud del array
            for (int num : pair.second) {
                archivo << num << " "; // Guardar los elementos del array
            }
            archivo << "\n"; // Nueva línea después de cada array
        }
        archivo.close();
        std::cout << "Arrays guardados en " << nombreArchivo << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}
