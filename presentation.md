---
marp: true
author: Gabriel Erazo
theme: uncover
class: invert
---

# Juego del 3 en raya usando Minimax 🎭

Doménica Escobar, Julissa Ruales, Guillermo Álvarez, Gabriel Erazo

---

## Setup inicial 🛠

* Librerías
* Namespace
* Constantes

---

### Librerías 📚

```c++
#include<bits/stdc++.hpp>
```

* Librería que básicamente incluye todas las librerías estándares de C++.
* No es recomendable usarlo en entornos profesionales

---

### Namespace 📦

```c++
using namespace std;
```

* Permite usar los elementos del namespace `std` sin tener que escribir `std::` delante.

---

### Constantes 📝

```c++
#define COMPUTER 1
#define HUMAN 2

#define SIDE 3

#define COMPUTER_MOVE 'O'
#define HUMAN_MOVE 'X'
```

---

#### Lista de constantes 📝

* Definimos constantes para representar lo siguiente:
  * `COMPUTER`: El turno del ordenador.
  * `HUMAN`: El turno del humano.
  * `SIDE`: El tamaño del tablero.
  * `COMPUTER_MOVE`: Con qué ficha juega el ordenador.
  * `HUMAN_MOVE`: Con qué ficha juega el humano.

---

## Funciones 📜

* `int main(int argc, char const *argv[])`
* `void playTresEnRaya(int whoseTurn)`
* `int bestMove(char board[][SIDE], int moveIndex)`
* `int minimax(char board[][SIDE], int depth, bool isAI)`
* `bool gameOver(char board[][SIDE])`
* `bool diagonalCrossed(char board[][SIDE])`

---

* `bool columnCrossed(char board[][SIDE])`
* `bool rowCrossed(char board[][SIDE])`
* `void declareWinner(int whoseTurn)`
* `void initialize(char board[][SIDE])`
* `void showInstructions()`
* `void showBoard(char board[][SIDE])`

---

## El archivo `main.cpp` 📄

---

### Incluyendo las funciones en el archivo `main.cpp` 📂

```c++
#include "funciones3Raya.hpp"
```

Las funciones guardadas en el archivo `funciones3Raya.hpp` se las incluye en el archivo `main.cpp` como si incluyéramos una librería normal, pero cambiando el `<>` por `""`.

---

### La función `main` 🏠

```c++
int main(int argc, char const *argv[])
{
    int opt;

    while (true) {

        printf("1) Jugar\n2) Salir\nIngrese una opción: ");

        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("1) La máquina comienza\n2) El jugador comienza\nIngrese una opción: ");
                scanf("%d", &opt);

                if (opt < 1 || opt > 2) {
                    printf("Opción no valida\n");
                    break;
                }

                playTresEnRaya(opt);
                break;

            case 2:
                printf("Gracias por jugar\n");
                return 0;

            default:
                printf("Opción no valida\n");
                break;
        }

    }
}
```

---

```c++
int main(int argc, char const *argv[]) {
    int opt;
}
```

Creamos la variable para guardar la opción ingresada por el usuario.

---

```c++
int main(int argc, char const *argv[]) {
    int opt;

    while (true) {
        // ...
    }
}
```

Creamos un ciclo infinito para que el programa no termine hasta que el usuario decida salir.

---

```c++
int main(int argc, char const *argv[]) {
    int opt;

    while (true) {
        printf("1) Jugar\n2) Salir\nIngrese una opción: ");
        scanf("%d", &opt);
    }
}
```

Pedimos al usuario que ingrese una opción.

---

```c++
int main(int argc, char const *argv[]) {
    int opt;

    while (true) {
        printf("1) Jugar\n2) Salir\nIngrese una opción: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                // ...
                break;

            case 2:
                // ...
                break;

            default:
                // ...
                break;
        }
    }
}
```

Usamos un `switch` para manejar las opciones ingresadas por el usuario.

---

```c++
case 1:
    printf("1) La máquina comienza\n2) El jugador comienza\nIngrese una opción: ");
    scanf("%d", &opt);

    if (opt < 1 || opt > 2) {
        printf("Opción no valida\n");
        break;
    }

    playTresEnRaya(opt);
    break;
```

Si el usuario ingresa `1`, le pedimos que ingrese si quiere que la máquina o el jugador comience, validamos que la opción sea válida y comenzamos el juego.

---

```c++
case 2:
    printf("Gracias por jugar\n");
    return 0;
```

Si el usuario ingresa `2`, le decimos que gracias por jugar y terminamos el programa.

---

```c++
default:
    printf("Opción no valida\n");
    break;
```

Si el usuario ingresa cualquier otra opción, le decimos que la opción no es válida y volvemos a pedirle que ingrese una opción.

---

## El archivo `funciones3Raya.hpp` 📄

---

### La función `playTresEnRaya` 🎮

```c++
void playTresEnRaya(int whoseTurn)
{
    char board[SIDE][SIDE];
    int moveIndex, x, y;
    moveIndex = x = y = 0;

    initialize(board);
    showInstructions();

    while (gameOver(board) == false && moveIndex != SIDE*SIDE)
    {
        int n;
        if (whoseTurn == COMPUTER)
        {
            n = bestMove(board, moveIndex);
            x = n / SIDE;
            y = n % SIDE;
            board[x][y] = COMPUTER_MOVE;
            printf("COMPUTER ha puesto un %c en la celda %d\n\n", COMPUTER_MOVE, n+1);
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }
        else
        {
            printf("Puede insertar en las siguientes posiciones : ");
            for(int i=0; i<SIDE; i++)
                for (int j = 0; j < SIDE; j++)
                    if (board[i][j] == ' ')
                        printf("%d ", (i * 3 + j) + 1);
            printf("\n\nIngrese la posición = ");
            scanf("%d",&n);
            n--;
            x = n / SIDE;
            y = n % SIDE;
            if(board[x][y] == ' ' && n<9 && n>=0)
            {
                board[x][y] = HUMAN_MOVE;
                printf ("\nHUMANO a puesto un %c en la celda %d\n\n", HUMAN_MOVE, n+1);
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            }
            else if(board[x][y] != ' ' && n<9 && n>=0)
            {
                printf("\nLa posición está ocupada, seleccione una casilla cualquiera de las disponibles\n\n");
            }
            else if(n<0 || n>8)
            {
                printf("Posición invalida\n");
            }
        }
    }

    if (gameOver(board) == false && moveIndex == SIDE * SIDE)
        printf("EMPATE\n");
    else
    {
        if (whoseTurn == COMPUTER)
            whoseTurn = HUMAN;
        else if (whoseTurn == HUMAN)
            whoseTurn = COMPUTER;

        declareWinner(whoseTurn);
    }
}
```

---

```c++
void playTresEnRaya(int whoseTurn)
{
    char board[SIDE][SIDE];
    int moveIndex, x, y;
    moveIndex = x = y = 0;

    initialize(board);
    showInstructions();
}
```

Creamos un tablero, un contador de movimientos, dos variables para guardar la posición de la jugada y inicializamos el tablero y mostramos las instrucciones.

---

```c++
while (gameOver(board) == false && moveIndex != SIDE*SIDE)
{
    int n;
    if (whoseTurn == COMPUTER)
    {
        // ...
    }
}
```

Mientras el juego no haya terminado y no se hayan hecho todos los movimientos, si es el turno de la máquina, la máquina juega.

---

```c++
while (gameOver(board) == false && moveIndex != SIDE*SIDE)
{
    int n;
    if (whoseTurn == COMPUTER)
    {
        n = bestMove(board, moveIndex);
        x = n / SIDE;
        y = n % SIDE;
        board[x][y] = COMPUTER_MOVE;
    }
}
```

Creamos una variable `n` para guardar la posición de la jugada, obtenemos la mejor jugada con la función `bestMove`, obtenemos la posición de la jugada, y colocamos la jugada en el tablero.

---

```c++
while (gameOver(board) == false && moveIndex != SIDE*SIDE)
{
    int n;
    if (whoseTurn == COMPUTER)
    {
        n = bestMove(board, moveIndex);
        x = n / SIDE;
        y = n % SIDE;
        board[x][y] = COMPUTER_MOVE;
        printf("COMPUTER ha puesto un %c en la celda %d\n\n", COMPUTER_MOVE, n+1);
        showBoard(board);
        moveIndex++;
        whoseTurn = HUMAN;
    }
}
```

Mostramos un mensaje diciendo que la máquina ha jugado, mostramos el tablero, aumentamos el contador de movimientos y cambiamos el turno.

---

```c++
else
{
    printf("Puede insertar en las siguientes posiciones : ");
    for(int i=0; i<SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (board[i][j] == ' ')
                printf("%d ", (i * 3 + j) + 1);
    printf("\n\nIngrese la posición = ");
    scanf("%d",&n);
}
```

Si es el turno del humano, le pedimos que ingrese una posición y mostramos las posiciones disponibles.

---

```c++
else
{
    printf("Puede insertar en las siguientes posiciones : ");
    for(int i=0; i<SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (board[i][j] == ' ')
                printf("%d ", (i * 3 + j) + 1);
    printf("\n\nIngrese la posición = ");
    scanf("%d",&n);
    n--;
    x = n / SIDE;
    y = n % SIDE;
}
```

Guardamos la posición ingresada en la variable `n`, restamos 1 porque los índices empiezan en 0, y obtenemos la posición de la jugada.

---

```c++
else
{
    printf("Puede insertar en las siguientes posiciones : ");
    for(int i=0; i<SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (board[i][j] == ' ')
                printf("%d ", (i * 3 + j) + 1);
    printf("\n\nIngrese la posición = ");
    scanf("%d",&n);
    n--;
    x = n / SIDE;
    y = n % SIDE;
    if(board[x][y] == ' ' && n<9 && n>=0)
    {
        // ...
    }
    else if(board[x][y] != ' ' && n<9 && n>=0)
    {
        // ...
    }
    else if(n<0 || n>8)
    {
        // ...
    }
}
```

Evaluamos tres casos, si la posición está vacía, si la posición no está vacía, y si la posición es inválida.

---

```c++
else
{
    if(board[x][y] == ' ' && n<9 && n>=0)
    {
        board[x][y] = HUMAN_MOVE;
        printf ("\nHUMANO a puesto un %c en la celda %d\n\n", HUMAN_MOVE, n+1);
        showBoard(board);
        moveIndex++;
        whoseTurn = COMPUTER;
    }
}
```

Si la posición está vacía, colocamos la jugada en el tablero, mostramos un mensaje diciendo que el humano ha jugado, mostramos el tablero, aumentamos el contador de movimientos y cambiamos el turno.

---

```c++
else if(board[x][y] != ' ' && n<9 && n>=0)
{
    printf("La celda %d está ocupada, intente de nuevo\n", n+1);
}
```

Si la posición no está vacía, mostramos un mensaje diciendo que la posición está ocupada.

---

```c++
else if(n<0 || n>8)
{
    printf("Posición inválida, intente de nuevo\n");
}
```

Si la posición es inválida, mostramos un mensaje diciendo que la posición es inválida.

---

```c++
if (gameOver(board) == false && moveIndex == SIDE*SIDE)
{
    printf("EMPATE\n");
}
```

En la siguiente parte de la función si ninguno de los jugadores ha ganado y se han realizado el mismo número de movimientos que el número de celdas, entonces es un empate y mostramos un mensaje diciendo que es un empate.

---

```c++
else
{
    if (whoseTurn == COMPUTER)
        whoseTurn = HUMAN;
    else if (whoseTurn == HUMAN)
        whoseTurn = COMPUTER;

    declareWinner(whoseTurn);
}
```

Si el juego no fue un empate, es que alguien ganó, entonces cambiamos el turno y mostramos un mensaje diciendo quién ganó.

---

### La función `initialize` 📑

```c++
void initialize(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
        for (int j=0; j<SIDE; j++)
            board[i][j] = ' ';
}
```

Esta función inicializa el tablero, colocando un espacio en cada celda la cual se las recorre con dos ciclos `for`.

---

### La función `showInstructions` 🪧

```c++
void showInstructions()
{
    printf("\nElija una celda del 1 al 9 como se indica a continuación y juegue\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");
}
```

Esta función muestra las instrucciones del juego, mostrando un tablero con los números del 1 al 9. (Los tabs son para centrar el tablero)

---

### La función `gameOver` 🎲

```c++
bool gameOver(char board[][SIDE])
{
    return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}
```

Esta función retorna `true` si alguno de los jugadores ha ganado, o `false` si no ha ganado nadie. Para esto, se evalúa si alguna fila, columna o diagonal ha sido completada por un jugador.

---

### La función `rowCrossed` 📏

```c++
bool rowCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return (true);

    return(false);
}
```

Esta función recorre cada fila y se evalúa si la primera, segunda y tercera celda son iguales y no están vacías, en ese caso retorna `true`, si no retorna `false`.

---

### La función `columnCrossed` 🏛️

```c++
bool columnCrossed(char board[][SIDE])
{
    for (int i=0; i<SIDE; i++)
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return (true);

    return(false);
}
```

Aquí recorre cada columna y se evalúa si la primera, segunda y tercera celda son iguales y no están vacías, en ese caso retorna `true`, si no retorna `false`.

---

### La función `diagonalCrossed` 📐

```c++
bool diagonalCrossed(char board[][SIDE])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return(true);

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return(true);

    return(false);
}
```

Esta función evalúa si la primera, segunda y tercera celda de la diagonal principal son iguales y no están vacías, o si la primera, segunda y tercera celda de la diagonal secundaria son iguales y no están vacías, en ese caso retorna `true`, si no retorna `false`.

---

### La función `bestMove` 🎯

```c++
int bestMove(char board[][SIDE], int moveIndex)
{
    int x, y;
    int score = 0, bestScore = -999;

    x = y = -1;
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (board[i][j] == ' ')
            {
                board[i][j] = COMPUTER_MOVE;
                score = minimax(board, moveIndex+1, false);
                board[i][j] = ' ';
                if(score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }

    return x*3+y;
}
```

---

```c++
int bestMove(char board[][SIDE], int moveIndex)
{
    int x, y;
    int score = 0, bestScore = -999;

    x = y = -1;
}
```

Inicializamos las variables `x`, `y`, `score` y `bestScore` con los valores que se muestran.

---

```c++
int x, y;
int score = 0, bestScore = -999;

x = y = -1;
for (int i = 0; i < SIDE; i++)
    for (int j = 0; j < SIDE; j++)
```

Inicializado las variables, recorremos el tablero con dos ciclos `for`.

---

```c++
for (int i = 0; i < SIDE; i++)
    for (int j = 0; j < SIDE; j++)
        if (board[i][j] == ' ')
        {
            // ...
        }
```

Por cada celda vacía del tablero, se realiza lo siguiente:

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = COMPUTER_MOVE;
    score = minimax(board, moveIndex+1, false);
    board[i][j] = ' ';
    // ...
}
```

Se coloca la jugada del computador en la celda vacía, se evalúa el tablero con la función `minimax` y se guarda el resultado en la variable `score` y se vuelve a dejar la celda vacía.

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = COMPUTER_MOVE;
    score = minimax(board, moveIndex+1, false);
    board[i][j] = ' ';
    if(score > bestScore)
    {
        bestScore = score;
        x = i;
        y = j;
    }
}
```

Si el resultado de la función `minimax` es mayor que el mejor resultado hasta el momento, se guarda el resultado en la variable `bestScore`, y se guardan las coordenadas de la celda en las variables `x` y `y`.

---

```c++
return x*SIDE+y;
```

Al final de la función, se retorna la posición de la celda en el tablero, que es el resultado de multiplicar la coordenada `x` por el tamaño del tablero y sumarle la coordenada `y`.

---

### La función `minimax` 🤖

```c++
int minimax(char board[][SIDE], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    if (gameOver(board) == true)
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if(depth < 9)
        {
            if(isAI == true)
            {
                bestScore = -999;
                for(int i=0; i<SIDE; i++)
                {
                    for(int j=0; j<SIDE; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = COMPUTER_MOVE;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = ' ';
                            if(score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 999;
                for (int i = 0; i < SIDE; i++)
                    for (int j = 0; j < SIDE; j++)
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = HUMAN_MOVE;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = ' ';
                            if (score < bestScore)
                                bestScore = score;
                        }

                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}
```

---

```c++

int minimax(char board[][SIDE], int depth, bool isAI)
{
    int score = 0;
    int bestScore = 0;
    // ...
}
```

La función `minimax` recibe el tablero, la profundidad y un booleano que indica si es el turno del computador o del jugador.

Inicializamos las variables `score`, `bestScore` y `depth` con los valores que se muestran.

---

```c++
if (gameOver(board) == true)
{
    if (isAI == true)
        return -1;
    if (isAI == false)
        return +1;
}
```

Si el juego ha terminado, verificamos si es el turno del computador o del jugador, y retornamos el valor correspondiente.

---

```c++
if (gameOver(board) == true)
{
    if (isAI == true)
        return -1;
    if (isAI == false)
        return +1;
}
else
{
    // ...
}
```

Si el juego no ha terminado, hacemos los siguiente:

---

```c++
if (depth < 9)
{
    if (isAI == true)
    {
        // ...
    }
    else
    {
        // ...
    }
}
else
{
    return 0;
}
```

Si la profundidad es menor que 9 verificamos si es el turno del computador o del jugador, y hacemos lo siguiente:

---

```c++
bestScore = -999;
for (int i = 0; i < SIDE; i++)
    for (int j = 0; j < SIDE; j++)
        if (board[i][j] == ' ')
        {
            // ...
        }

// ...
```

Si es el turno del computador, inicializamos la variable `bestScore` con el valor `-999`, recorremos el tablero con dos ciclos `for` y por cada celda vacía del tablero, hacemos lo siguiente:

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = COMPUTER_MOVE;
    score = minimax(board, depth + 1, false);
    board[i][j] = ' ';
    // ...
}
```

Se coloca la jugada del computador en la celda vacía, se evalúa el tablero con la función `minimax` y se guarda el resultado en la variable `score` y se vuelve a dejar la celda vacía. Este es un paso recursivo, ya que la función `minimax` se llama a sí misma.

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = COMPUTER_MOVE;
    score = minimax(board, depth + 1, false);
    board[i][j] = ' ';
    if (score > bestScore)
        bestScore = score;
}
```

Si el resultado de la función `minimax` es mayor que el mejor resultado hasta el momento, se guarda el resultado en la variable `bestScore`.

---

```c++
return bestScore;
```

Al final de la función, se retorna el mejor resultado.

---

```c++
else
{
    bestScore = 999;
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            // ...

    return bestScore;
}
```

Si es el turno del jugador, inicializamos la variable `bestScore` con el valor `999`, recorremos el tablero con dos ciclos `for`...

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = HUMAN_MOVE;
    score = minimax(board, depth + 1, true);
    board[i][j] = ' ';
    // ...
}
```

Se coloca la jugada del jugador en la celda vacía, se evalúa el tablero con la función `minimax` y se guarda el resultado en la variable `score` y se vuelve a dejar la celda vacía. Este es un paso recursivo, ya que la función `minimax` se llama a sí misma.

---

```c++
if (board[i][j] == ' ')
{
    board[i][j] = HUMAN_MOVE;
    score = minimax(board, depth + 1, true);
    board[i][j] = ' ';
    if (score < bestScore)
        bestScore = score;
}
```

Si el resultado de la función `minimax` es menor que el mejor resultado hasta el momento, se guarda el resultado en la variable `bestScore`.

---

```c++
return bestScore;
```

Al final de la función, se retorna el mejor resultado.

---

```c++
else
{
    return 0;
}
```

Si la profundidad es igual a 9 o mayor, se retorna el valor `0`.

---

### La función `showBoard` 📊

```c++
void showBoard(char board[][SIDE])
{
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t-----------\n");
    printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}
```

La función `showBoard` recibe el tablero y muestra el tablero en la consola.

---

### La función `declareWinner` 🏆🏁

```c++
void declareWinner(int whoseTurn)
{
    if (whoseTurn == COMPUTER)
        printf("La computadora GANO\n");
    else
        printf("Humano GANO\n");
}
```

La función `declareWinner` recibe el turno actual y muestra en la consola el ganador.
