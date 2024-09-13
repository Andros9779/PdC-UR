import random

# Función para verificar si un número es primo
def es_primo(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

# Función para lanzar dados
def lanzar_dados(num_dados=2):
    return [random.randint(1, 6) for _ in range(num_dados)]

# Función para jugar una ronda
def jugar_ronda():
    total = 0
    
    # Lanzar dos dados inicialmente
    dados = lanzar_dados(2)
    print(f"Lanzamiento inicial: {dados}")

    # Sumar los valores de los dados
    total = sum(dados)

    # Verificar si el jugador sacó dobles
    if dados[0] == dados[1]:
        print("¡Sacaste dobles! Lanzarás 3 dados adicionales.")
        dados_extra = lanzar_dados(3)
        print(f"Lanzamiento adicional con 3 dados: {dados_extra}")
        total = sum(dados_extra)
    
    # Verificar si sacó 12
    if total == 12:
        decision = input("Sacaste 12. ¿Deseas lanzar solo 1 dado adicional (S/N)? ").strip().lower()
        if decision == 's':
            dado_extra = lanzar_dados(1)[0]
            print(f"Lanzaste 1 dado adicional: {dado_extra}")
            total += dado_extra

    print(f"Total hasta ahora: {total}")
    return total

# Función para determinar el ganador de una ronda
def determinar_ganador(total_jugador1, total_jugador2):
    # Comprobar si los números son primos
    primo_jugador1 = es_primo(total_jugador1)
    primo_jugador2 = es_primo(total_jugador2)
    
    if primo_jugador1 and not primo_jugador2:
        print(f"El jugador 1 gana con {total_jugador1}, que es un número primo.")
        return 1
    elif primo_jugador2 and not primo_jugador1:
        print(f"El jugador 2 gana con {total_jugador2}, que es un número primo.")
        return 2
    elif primo_jugador1 and primo_jugador2:
        if total_jugador1 > total_jugador2:
            print(f"El jugador 1 gana con {total_jugador1}, que es un número primo mayor.")
            return 1
        else:
            print(f"El jugador 2 gana con {total_jugador2}, que es un número primo mayor.")
            return 2
    else:
        if total_jugador1 <= 23 and total_jugador2 <= 23:
            if total_jugador1 > total_jugador2:
                print(f"El jugador 1 gana con {total_jugador1}, más cercano a 23.")
                return 1
            else:
                print(f"El jugador 2 gana con {total_jugador2}, más cercano a 23.")
                return 2
        elif total_jugador1 <= 23:
            print(f"El jugador 1 gana con {total_jugador1}, más cercano a 23.")
            return 1
        elif total_jugador2 <= 23:
            print(f"El jugador 2 gana con {total_jugador2}, más cercano a 23.")
            return 2
        else:
            print("Ambos jugadores superaron 23. No hay ganador.")
            return 0

# Función principal para jugar Prime Jack al mejor de 5
def jugar_prime_jack():
    print("¡Bienvenidos a Prime Jack al mejor de 5!")

    rondas_jugadas = 0
    puntos_jugador1 = 0
    puntos_jugador2 = 0

    while puntos_jugador1 < 3 and puntos_jugador2 < 3:
        rondas_jugadas += 1
        print(f"\n--- Ronda {rondas_jugadas} ---")

        print("\nJugador 1:")
        total_jugador1 = jugar_ronda()

        print("\nJugador 2:")
        total_jugador2 = jugar_ronda()

        # Determinar el ganador de la ronda
        ganador = determinar_ganador(total_jugador1, total_jugador2)
        if ganador == 1:
            puntos_jugador1 += 1
            print(f"El Jugador 1 gana la ronda {rondas_jugadas}.")
        elif ganador == 2:
            puntos_jugador2 += 1
            print(f"El Jugador 2 gana la ronda {rondas_jugadas}.")
        else:
            print(f"No hay ganador en la ronda {rondas_jugadas}.")

        # Mostrar los puntos acumulados
        print(f"Puntos Jugador 1: {puntos_jugador1}")
        print(f"Puntos Jugador 2: {puntos_jugador2}")

    # Declarar el ganador final
    if puntos_jugador1 == 3:
        print("\n¡El Jugador 1 ha ganado el juego al mejor de 5!")
    else:
        print("\n¡El Jugador 2 ha ganado el juego al mejor de 5!")

# Ejecutar el juego
jugar_prime_jack()