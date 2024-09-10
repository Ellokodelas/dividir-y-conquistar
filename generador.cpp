#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para std::sort

int main() {
    const int max_size = 100000; // 10^5
    const int ordered_lists = 0; // Número de listas ordenadas a generar
    const int semi_ordered_lists = 0; // Número de listas semiordenadas a generar
    const int unordered_lists = 30; // Número de listas desordenadas a generar

    // Inicializa la semilla para la generación de números aleatorios
    srand(time(0));

    // Abrir el archivo una vez para todas las listas
    std::ofstream outFile("dataset.txt");
    if (!outFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
        return 1;
    }

    // Generar listas ordenadas
    for (int j = 0; j < ordered_lists; ++j) {
        int listSize = max_size ;

        std::list<int> lista;
        for (int i = 0; i < listSize; ++i) {
            lista.push_back(rand() % 1000000);
        }

        lista.sort(); // Ordena la lista

        outFile << listSize << "\n";
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            outFile << *it;
            if (std::next(it) != lista.end()) {
                outFile << " ";
            }
        }
        outFile << "\n";  
        std::cout << "Lista ordenada " << j + 1 << " (tamaño: " << listSize << ") guardada en 'dataset.txt'.\n";
    }

    // Generar listas semiordenadas
    for (int j = 0; j < semi_ordered_lists; ++j) {
        int listSize = max_size ;

        std::list<int> lista;
        for (int i = 0; i < listSize; ++i) {
            lista.push_back(rand() % 1000000);
        }

        // Ordenar la primera mitad
        int halfSize = listSize / 2;
        std::list<int> orderedPart(lista.begin(), std::next(lista.begin(), halfSize));
        orderedPart.sort();

        // Combinar la mitad ordenada con la mitad desordenada
        std::list<int> remainingPart(std::next(lista.begin(), halfSize), lista.end());
        orderedPart.splice(orderedPart.end(), remainingPart);

        outFile << listSize << "\n";
        for (auto it = orderedPart.begin(); it != orderedPart.end(); ++it) {
            outFile << *it;
            if (std::next(it) != orderedPart.end()) {
                outFile << " ";
            }
        }
        outFile << "\n";  
        std::cout << "Lista semiordenada " << j + 1 << " (tamaño: " << listSize << ") guardada en 'dataset.txt'.\n";
    }

    // Generar listas desordenadas
    for (int j = 0; j < unordered_lists; ++j) {
        int listSize = max_size ;

        std::list<int> lista;
        for (int i = 0; i < listSize; ++i) {
            lista.push_back(rand() % 1000000);
        }

        outFile << listSize << "\n";
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            outFile << *it;
            if (std::next(it) != lista.end()) {
                outFile << " ";
            }
        }
        outFile << "\n";  
        std::cout << "Lista desordenada " << j + 1 << " (tamaño: " << listSize << ") guardada en 'dataset.txt'.\n";
    }

    // Cerrar el archivo después de completar todas las iteraciones
    outFile.close();
    std::cout << "Todas las listas han sido guardadas en 'dataset.txt'.\n";

    return 0;
}