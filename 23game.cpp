#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Función para verificar si un número es primo
bool es_primo(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Función para lanzar dados
vector<int> lanzar_dados(int num_dados = 2) {
    vector<int> dados;
    for (int i = 0; i < num_dados; i++) {
        dados.push_back(rand() % 6 + 1);  // Número aleatorio entre 1 y 6
    }
    return dados;
}

// Función para jugar una ronda
int jugar_ronda() {
    int total = 0;

    // Lanzar dos dados inicialmente
    vector<int> dados = lanzar_dados(2);
    cout << "Lanzamiento inicial: [" << dados[0] << ", " << dados[1] << "]" << endl;

    // Sumar los valores de los dados
    total = dados[0] + dados[1];

    // Verificar si el jugador sacó dobles
    if (dados[0] == dados[1]) {
        cout << "¡Sacaste dobles! Lanzarás 3 dados adicionales." << endl;
        vector<int> dados_extra = lanzar_dados(3);
        cout << "Lanzamiento adicional con 3 dados: [" << dados_extra[0] << ", " << dados_extra[1] << ", " << dados_extra[2] << "]" << endl;
        total = dados_extra[0] + dados_extra[1] + dados_extra[2];
    }

    // Verificar si sacó 12
    if (total == 12) {
        char decision;
        cout << "Sacaste 12. ¿Deseas lanzar solo 1 dado adicional (S/N)? ";
        cin >> decision;
        if (decision == 'S' || decision == 's') {
            int dado_extra = lanzar_dados(1)[0];
            cout << "Lanzaste 1 dado adicional: " << dado_extra << endl;
            total += dado_extra;
        }
    }

    cout << "Total hasta ahora: " << total << endl;
    return total;
}

// Función para determinar el ganador de una ronda
int determinar_ganador(int total_jugador1, int total_jugador2) {
    // Comprobar si los números son primos
    bool primo_jugador1 = es_primo(total_jugador1);
    bool primo_jugador2 = es_primo(total_jugador2);

    if (primo_jugador1 && !primo_jugador2) {
        cout << "El jugador 1 gana con " << total_jugador1 << ", que es un número primo." << endl;
        return 1;
    } else if (primo_jugador2 && !primo_jugador1) {
        cout << "El jugador 2 gana con " << total_jugador2 << ", que es un número primo." << endl;
        return 2;
    } else if (primo_jugador1 && primo_jugador2) {
        if (total_jugador1 > total_jugador2) {
            cout << "El jugador 1 gana con " << total_jugador1 << ", que es un número primo mayor." << endl;
            return 1;
        } else {
            cout << "El jugador 2 gana con " << total_jugador2 << ", que es un número primo mayor." << endl;
            return 2;
        }
    } else {
        if (total_jugador1 <= 23 && total_jugador2 <= 23) {
            if (total_jugador1 > total_jugador2) {
                cout << "El jugador 1 gana con " << total_jugador1 << ", más cercano a 23." << endl;
                return 1;
            } else {
                cout << "El jugador 2 gana con " << total_jugador2 << ", más cercano a 23." << endl;
                return 2;
            }
        } else if (total_jugador1 <= 23) {
            cout << "El jugador 1 gana con " << total_jugador1 << ", más cercano a 23." << endl;
            return 1;
        } else if (total_jugador2 <= 23) {
            cout << "El jugador 2 gana con " << total_jugador2 << ", más cercano a 23." << endl;
            return 2;
        } else {
            cout << "Ambos jugadores superaron 23. No hay ganador." << endl;
            return 0;
        }
    }
}

// Función principal para jugar Prime Jack al mejor de 5
void jugar_prime_jack() {
    cout << "¡Bienvenidos a Prime Jack al mejor de 5!" << endl;

    int rondas_jugadas = 0;
    int puntos_jugador1 = 0;
    int puntos_jugador2 = 0;

    while (puntos_jugador1 < 3 && puntos_jugador2 < 3) {
        rondas_jugadas++;
        cout << "\n--- Ronda " << rondas_jugadas << " ---" << endl;

        cout << "\nJugador 1:" << endl;
        int total_jugador1 = jugar_ronda();

        cout << "\nJugador 2:" << endl;
        int total_jugador2 = jugar_ronda();

        // Determinar el ganador de la ronda
        int ganador = determinar_ganador(total_jugador1, total_jugador2);
        if (ganador == 1) {
            puntos_jugador1++;
            cout << "El Jugador 1 gana la ronda " << rondas_jugadas << "." << endl;
        } else if (ganador == 2) {
            puntos_jugador2++;
            cout << "El Jugador 2 gana la ronda " << rondas_jugadas << "." << endl;
        } else {
            cout << "No hay ganador en la ronda " << rondas_jugadas << "." << endl;
        }

        // Mostrar los puntos acumulados
        cout << "Puntos Jugador 1: " << puntos_jugador1 << endl;
        cout << "Puntos Jugador 2: " << puntos_jugador2 << endl;
    }

    // Declarar el ganador final
    if (puntos_jugador1 == 3) {
        cout << "\n¡El Jugador 1 ha ganado el juego al mejor de 5!" << endl;
    } else {
        cout << "\n¡El Jugador 2 ha ganado el juego al mejor de 5!" << endl;
    }
}

int main() {
    srand(time(0));  // Inicializar la semilla para números aleatorios
    jugar_prime_jack();
    return 0;
}