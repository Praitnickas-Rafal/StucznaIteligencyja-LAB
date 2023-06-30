#include <stdio.h>

// Funkcja do obliczania regresji liniowej
void linearRegression(double x[], double y[], int n, double *slope, double *intercept) {
    double sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;

    // Obliczanie sum potrzebnych do wyznaczenia współczynników regresji
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumXX += x[i] * x[i];
    }

    // Wyznaczanie współczynników regresji
    double meanX = sumX / n;
    double meanY = sumY / n;
    double numerator = (n * sumXY) - (sumX * sumY);
    double denominator = (n * sumXX) - (sumX * sumX);

    *slope = numerator / denominator;
    *intercept = meanY - (*slope * meanX);
}

int main() {
    // Dane wejściowe
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    int n = 5;

    // Współczynniki regresji
    double slope, intercept;

    // Wywołanie funkcji regresji liniowej
    linearRegression(x, y, n, &slope, &intercept);

    // Wyświetlanie wyników
    printf("Wspolczynnik nachylenia (slope): %.1f\n", slope);
    printf("Wspolczynnik przesuniecia (intercept): %.1f\n", intercept);

    return 0;
}
