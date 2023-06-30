#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Funkcja do tworzenia macierzy sąsiedztwa
void createAdjacencyMatrix(int adjacencyMatrix[][MAX_VERTICES], int numVertices,
                           int numEdges, int edges[][2]) {
  int i, j;

  // Inicjalizacja macierzy sąsiedztwa
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      adjacencyMatrix[i][j] = 0;
    }
  }

  // Dodawanie krawędzi do macierzy sąsiedztwa
  for (i = 0; i < numEdges; i++) {
    int source = edges[i][0];
    int destination = edges[i][1];
    adjacencyMatrix[source][destination] = 1;
  }
}

// Funkcja do tworzenia macierzy incydencji
void createIncidenceMatrix(int incidenceMatrix[][MAX_VERTICES], int numVertices,
                           int numEdges, int edges[][2]) {
  int i, j;

  // Inicjalizacja macierzy incydencji
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numEdges; j++) {
      incidenceMatrix[i][j] = 0;
    }
  }

  // Dodawanie krawędzi do macierzy incydencji
  for (i = 0; i < numEdges; i++) {
    int source = edges[i][0];
    int destination = edges[i][1];
    incidenceMatrix[source][i] = 1;
    incidenceMatrix[destination][i] = -1;
  }
}

// Funkcja do tworzenia listy sąsiedztwa
void createAdjacencyList(int adjacencyList[][MAX_VERTICES], int numVertices,
                         int numEdges, int edges[][2]) {
  int i, j;

  // Inicjalizacja listy sąsiedztwa
  for (i = 0; i < numVertices; i++) {
    adjacencyList[i][0] = 0;
  }

  // Dodawanie krawędzi do listy sąsiedztwa
  for (i = 0; i < numEdges; i++) {
    int source = edges[i][0];
    int destination = edges[i][1];

    // Dodawanie do listy wierzchołka docelowego jako sąsiada dla wierzchołka
    // źródłowego
    j = ++adjacencyList[source][0];
    adjacencyList[source][j] = destination;
  }
}

// Funkcja do wypisywania macierzy
void printMatrix(int matrix[][MAX_VERTICES], int numRows, int numCols) {
  int i, j;

  for (i = 0; i < numRows; i++) {
    for (j = 0; j < numCols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Funkcja do wypisywania listy sąsiedztwa
void printAdjacencyList(int adjacencyList[][MAX_VERTICES], int numVertices) {
  int i, j;

  for (i = 0; i < numVertices; i++) {
    printf("%d: ", i);
    for (j = 1; j <= adjacencyList[i][0]; j++) {
      printf("%d ", adjacencyList[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int numVertices = 4; // liczba wierzchołków
  int numEdges = 5;    // liczba krawędzi
  int edges[MAX_VERTICES][2] = {
      {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3} // definicja krawędzi
  };
  int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
  int incidenceMatrix[MAX_VERTICES][MAX_VERTICES];
  int adjacencyList[MAX_VERTICES][MAX_VERTICES];

  // Tworzenie macierzy sąsiedztwa
  createAdjacencyMatrix(adjacencyMatrix, numVertices, numEdges, edges);

  // Tworzenie macierzy incydencji
  createIncidenceMatrix(incidenceMatrix, numVertices, numEdges, edges);

  // Tworzenie listy sąsiedztwa
  createAdjacencyList(adjacencyList, numVertices, numEdges, edges);

  // Wypisanie macierzy sąsiedztwa
  printf("\nMacierz sąsiedztwa:\n");
  printMatrix(adjacencyMatrix, numVertices, numVertices);

  // Wypisanie macierzy incydencji
  printf("\nMacierz incydencji:\n");
  printMatrix(incidenceMatrix, numVertices, numEdges);

  // Wypisanie listy sąsiedztwa
  printf("\nLista sąsiedztwa:\n");
  printAdjacencyList(adjacencyList, numVertices);

  return 0;
}
