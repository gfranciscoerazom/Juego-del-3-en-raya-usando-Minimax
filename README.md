# Juego del tres en raya  
Integrantes: Doménica Escobar, Julissa Ruales, Guillermo Álvarez, Gabriel Erazo  
## Descripcion del juego  
El juego de tres en raya es uno de los juegos m'as comunes que existen a nivel mundial, consiste en tener un espacio con tres filas y tres columnas dando como resultado una cuadricula con nueve cuadros vacios, se deben tener dos jugadores qu tomen roles diferentes puede ser por medio de X o de circulos (O) cada jugador elegira un simbolo y se turnaran para colocar el simbolo en un cuadro en blanco, el juego termina cuando uno de los simbolos consiga colocarse en tres espacios seguidos en cualquier direccion. Se declara un empate cuando ninguno de los simbolos o jugadores logro colocar seguidamente el simbolo que se encuentr utilizando.  
## Principales rutinas  
- ***Función playTresEnRaya:*** Crea un tablero, un contador de movimientos, dos variables para guardar la posición de la jugada y inicializamos el tablero y mostramos las instrucciones.Mientras el juego no haya terminado y no se hayan hecho todos los movimientos, si es el turno de la máquina, la máquina juega.  
- ***Función showInstructions:*** Esta función muestra las instrucciones del juego, mostrando un tablero con los números del 1 al 9. (Los tabs son para centrar el tablero)  
- ***Función gameOver:*** Esta función retorna true si alguno de los jugadores ha ganado, o false si no ha ganado nadie. Para esto, se evalúa si alguna fila, columna o diagonal ha sido completada por un jugador.  
- ***Función rowCrossed:*** Esta función recorre cada fila y se evalúa si la primera, segunda y tercera celda son iguales y no están vacías, en ese caso retorna true, si no retorna false.  
- ***Función columnCrossed:*** Aquí recorre cada columna y se evalúa si la primera, segunda y tercera celda son iguales y no están vacías, en ese caso retorna true, si no retorna false.  
- ***Función diagonalCrossed:*** Esta función evalúa si la primera, segunda y tercera celda de la diagonal principal son iguales y no están vacías, o si la primera, segunda y tercera celda de la diagonal secundaria son iguales y no están vacías, en ese caso retorna true, si no retorna false.  
- ***Función bestMove:*** Si el resultado de la función minimax es mayor que el mejor resultado hasta el momento, se guarda el resultado en la variable bestScore, y se guardan las coordenadas de la celda en las variables x y y. Al final de la función, se retorna la posición de la celda en el tablero, que es el resultado de multiplicar la coordenada x por el tamaño del tablero y sumarle la coordenada y.  
- ***Función minimax:*** La función minimax recibe el tablero, la profundidad y un booleano que indica si es el turno del computador o del jugador.  
- ***Función showBoard:*** La función showBoard recibe el tablero y muestra el tablero en la consola.  
- ***Función declareWinner:*** La función declareWinner recibe el turno actual y muestra en la consola el ganador.  
## Tabla de tiempos mejores y peores casos  
Dentro de la experiencia de máquina vs humano existen varias posibilidades dondr la maquina puede ser mejor que el humano o viceversa, de tal manera existen casos peores y mejores de cada uno, dentro de la historia las primeras maquinas no mantenian un tiempo vorto ni estandarizadoby la mayoria de desiciones que tomaba el computador dentro de un juego de logica lo llevaba a la perfida del mismo haciendo que el ganador sea el humano, esto ha ido cambiando con el pasar de los años y en la actualidad gracias a la inteligencia artificial se ha podido ver como las máquinas han mejorado tanto su tiempo de desición y la efectividad de la misma al punto de que en algunas partidas o juegos completos de lógica las máquinashan salido victoriosas.  
- ***Computadora:*** Las máquinas en la actualidad se puede decir que han mejorado en todo sentido pero cuando se trata de juegos de lógica como el tres en raya muestra que su tiempo al tomar la desicion de realizar un movimiento es de 1 segundo e incluso menos dependiendo de la situación, lo que quiere decir que toma desiciones rápidas pero eso no quiere decir que sea la desicion correcta o efectiva necesariamente. Todo esto se da gracias a que existen algoritmos programados para la computadora en donde verifica los peores y mejores casos o respuestas de una manera rápida pero no necesariamente efectiva.  
- ***Humano:*** Los humanos no necesariamente mantienen un ritmo seguro o estático esto varía dependiendo de las personas que realicenla actividad aun así en términos generales estadísticos en el mejor de los casos se tiene una respuesta de movimiento en los primeros 10 o 20 segundos, mientras que en el peor de los casos el tiempo de respuesta puede llegar a tardar entre 1 o 2 minutos, cabe recalcar que aun así la respuesta no siempre es correcta o efectiva.  
## Arbol de posibilidades  
Un árbol de juego completo es un árbol que comienza desde la posición inicial y contiene todos los movimientos posibles desde cada posición; el árbol completo es el mismo árbol obtenido al renderizar todo el juego. Más específicamente, un juego completo es una especificación de un juego en teoría de juegos. En él se pueden formular muchos aspectos importantes. Por ejemplo, la secuencia de acciones que pueden realizar las partes interesadas, sus elecciones en cada punto de decisión, información sobre las acciones que han realizado otras partes interesadas mientras cada parte interesada tomaba una decisión y los beneficios de todos los posibles resultados del juego.  

Diagrama que muestra los dos primeros niveles o capas del árbol de tres en raya. Los reflejos de rotación y posición son equivalentes, por lo que el primer jugador tiene tres opciones de movimiento: centro, lateral o esquina. Si el primer jugador está en el medio, el segundo jugador tiene dos opciones, de lo contrario el jugador tiene cinco opciones.  

El número de nodos hoja en el árbol del juego completo es el número de posibles tipos diferentes de juegos. Por ejemplo, un árbol de Tic Tac Toe tiene 255.168 nodos de hoja.  

El algoritmo Minimax crea un árbol basado en el estado actual del juego. Digamos que es el turno de la computadora para pasar al siguiente turno. Con base en el estado actual del juego, crea un nodo derivado para todas las posibles acciones legales que puede tomar la computadora (se refiere la computadora como el jugador MAX). En el siguiente nivel, para cada posible movimiento del ordenador, generamos los posibles movimientos legales que debe realizar el jugador (se llama al jugador usuario MIN), y así hasta llegar al nodo con el resultado. La computadora gana, el jugador gana, o es un empate. En otras palabras, en cada nivel del árbol, los jugadores MAX se alternan con los jugadores MIN (de ahí el nombre de estrategia minimax). Si marcamos los nodos MAX con cuadrados y los nodos MIN con círculos, el posible árbol minimax se ve así.  

![minimax](https://user-images.githubusercontent.com/87248845/210288400-3e04c69b-62b7-4a02-ab12-a179b72327cd.png)  

De esta forma, cuando se llega a un nodo final, se utiliza una función de evaluación que evalúa las probabilidades y les asigna un valor numérico. En el caso del tres en raya, la funcionalidad es muy sencilla. Por ejemplo, podemos asignar 1 a un nodo terminal donde gana la computadora, 0 a un empate y -1 a que gane un jugador humano. El algoritmo evalúa cada nivel del árbol de abajo hacia arriba, en el nivel MAX elige caminos que conducen a puntajes más altos que son beneficiosos para la computadora, y en el nivel MIN intenta elegir caminos con puntajes más bajos, ya que penalizaría un jugador humano.  

![minimax_tres_raya](https://user-images.githubusercontent.com/87248845/210288650-bdbc7cd0-3c38-404f-a183-02202ec045bb.png)


## Instrucciones Windows  
- IDE: Para poder compilar el programa una opción puede ser descargar un IDE como Visual Studio Code con todas las configuraciones necesarias, por medio del IDE abrir el documento, verificar que este configurado los plugins del lenguaje en este caso C++ y luego compilarlo.  

- CMD: Para compilar el código desde el cmd se recomienda usar un compilador externo como Mingw que se lo puede descargar desde el navegador, una vez instalado en la cmd se puede escribir el siguiente comando "g++ nombreArchivo -o nombredelejecutable".

Si no se desea instalar aplicaciones dentro del computador existen las opciones de compiladores online en este caso se recomienda dos compiladores como:  

- ***OnlineGDB***  
1 Abrir el navegador y buscar online GDB.  
2 Registrarse si no tiene una cuenta.  
3 Abrir o cargar el documento.  
4 Verificar que en la parte superior izquierda esté el lenguaje de C++.  
5 Compilar el programa.  

- ***Replit***  
1 Abrir el navegador y buscar replit.  
2 Registrarse si no tiene una cuenta.  
3 Abrir o cargar el documento.  
4 Verificar el lenguaje de C++.  
5 Compilar el programa.  
## Instrucciones Linux  
- IDE: Para poder compilar el programa una opción puede ser descargar un IDE como Visual Studio Code con todas las configuraciones necesarias, por medio del IDE abrir el documento, verificar que este configurado los plugins del lenguaje en este caso C++ y luego compilarlo.  

- CMD: Para compilar el código desde el cmd se recomienda realizar una instalación desde el cmd colocando "sudo apt install gcc", luego escribir "sudo apt get install g++", una vez instalado en la cmd se puede escribir el siguiente comando "g++ main.cpp funciones3Raya.hpp -o nombreCompilacion".  

Si no se desea instalar aplicaciones dentro del computador existen las opciones de compiladores online en este caso se recomienda dos compiladores como:  

- ***OnlineGDB***  
1 Abrir el navegador y buscar online GDB.  
2 Registrarse si no tiene una cuenta.  
3 Abrir o cargar el documento.  
4 Verificar que en la parte superior izquierda esté el lenguaje de C++.  
5 Compilar el programa.  

- ***Replit***  
1 Abrir el navegador y buscar replit.  
2 Registrarse si no tiene una cuenta.  
3 Abrir o cargar el documento.  
4 Verificar el lenguaje de C++.
