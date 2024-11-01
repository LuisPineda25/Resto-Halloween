// Luis Ubaldo Flores Pineda - 223046

#include <iostream>     // Incluye la librería estándar de entrada y salida
#include <algorithm>    // Incluye la librería para utilizar la función max
using namespace std;

int main() {
    int T;  // Variable para almacenar el número de casos de prueba
    cout << "Ingresa el número de casos de prueba: ";
    cin >> T;  // Leemos el número de casos de prueba

    // Ciclo para procesar cada caso de prueba
    for (int t = 0; t < T; ++t) {
        int N;  // Variable para almacenar el número de casas
        cout << "\nIngresa el número de casas: ";
        cin >> N;  // Leemos el número de casas en el caso de prueba actual

        int dulces[N];  // Arreglo para almacenar la cantidad de dulces en cada casa
        cout << "Ingresa los dulces en cada casa separados por espacio: ";
        for (int i = 0; i < N; ++i) {
            cin >> dulces[i];  // Leemos la cantidad de dulces en cada casa y los guardamos en el arreglo
        }

        // Si solo hay una casa, el máximo de dulces es simplemente los dulces de esa casa
        if (N == 1) {
            cout << "Máximo dulces: " << dulces[0] << endl;  // Imprimimos los dulces de la única casa
            continue;  // Pasamos al siguiente caso de prueba
        }

        // Inicializamos las variables para calcular el máximo de dulces
        int maximoNoVisitoAnterior = dulces[0];                  // Máximo de dulces sin incluir la casa anterior
        int maximoVisitoAnterior = max(dulces[0], dulces[1]);    // Máximo de dulces incluyendo la casa anterior

        // Ciclo para evaluar cada casa a partir de la tercera
        for (int i = 2; i < N; ++i) {
            // Calculamos el máximo posible hasta la casa actual
            int nuevoMaximo = max(maximoVisitoAnterior, maximoNoVisitoAnterior + dulces[i]);
            
            // Actualizamos maximoNoVisitoAnterior para reflejar el máximo hasta la casa anterior
            maximoNoVisitoAnterior = maximoVisitoAnterior;
            
            // maximoVisitoAnterior se actualiza con el valor de nuevoMaximo
            maximoVisitoAnterior = nuevoMaximo;
        }

        // Imprimimos el máximo de dulces posibles para este caso de prueba
        cout << "Máximo dulces: " << maximoVisitoAnterior << endl;
    }

    return 0;  // Fin del programa
}

