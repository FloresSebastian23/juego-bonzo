
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;


//funcion definir turnos
bool definirTurnos(){
    int numeroTurnos;
    numeroTurnos = rand()% 2 + 1;
    //cout << numeroTurnos << endl; //nos muestra el numero para corroborar que funcione
    if(numeroTurnos % 2 == 0) //evalúa si el nro es par o impar
    {
        return true; //devuelve true si es par
    }
    return false; //devuelve false si es impar
    }


//Funciones tirar dados
void tirarDados(int dados[]){ //recibe un vector vacío
    for (int x = 0; x < 3 ; x++) //recorre el vector vacío usando la x del for
    {
        dados[x] = rand()% 6 + 1;// carga cada índice del vector con la función rand.
    }
}
//mostrar dados dado de tres
void mostrarDados(int dados[]){
    int dado;
    for(int x = 0; x < 3; x++){
        dado = dados[x];
        cout << "dado "  << (x + 1) << ": " << dado<< endl;
        }
    }

// evaluarDados


//funcion suma puntos si evaluar dados == true
int sumarPuntos(int dados[]) //recibe un vector de dados
{
    int acu = 0; //acumula puntos y devuelve esta variable
    for(int x =0; x < 3; x ++) //recorre los índices del vector dados
    {
        acu += dados[x]; //acumula el puntaje

    }
    return acu ; //devuelve los puntos
}

//funcion dibujar dado. se la llama dentro de un for de 3 y devuelve el dibujo de cada dado

void dibujarDado (int numeroDado)
{
    if(numeroDado == 1)
    {
        cout << "+-----+" << endl;
        cout << "|  x  |" << endl;
        cout << "|     |" << endl;
        cout << "+-----+" << endl;
    }

    if(numeroDado == 2)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "|     |" << endl;
        cout << "+-----+" << endl;
    }

    if(numeroDado == 3)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "|  x  |" << endl;
        cout << "+-----+" << endl;
    }
    if(numeroDado == 4)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "| x x |" << endl;
        cout << "+-----+" << endl;
    }
    if(numeroDado == 5)
    {
        cout << "+-----+" << endl;
        cout << "|x x x|" << endl;
        cout << "| x x |" << endl;
        cout << "+-----+" << endl;
    }
    if(numeroDado == 6)
    {
        cout <<  "+-----+" << endl;
        cout << "|x x x|" << endl;
        cout << "|x x x|" << endl;
        cout << "+-----+" << endl;
    }
}
//funcion limpiar pantalla debería ejecutarse después de que el jugador decide seguir tirando dados

void limpiarPantalla(){
    system("CLS");
}

//funcion jugar turno

int jugarTurno(int nroRonda, string jugador, int puntosTotalesJugador){
    //variables que funcionan por cada jugador dentro del if
    int acumPuntosJug = 0; //suma por tirada
    int dados[3];
    int jugada; //para seguir jugando valor 1 o 0;
    int sumaTotalRonda = 0; //por ronda
    int tirada = 1;

    limpiarPantalla();
    cout << "Juega: " << jugador << ". " << endl;
    cout << "Nro de Ronda: " << nroRonda << endl << "Tirada:" << tirada << endl << endl; //Veo numero de ronda y tirada

    tirarDados(dados);
    mostrarDados(dados);
    acumPuntosJug = sumarPuntos(dados); //suma puntos por ronda, se reinicia en cada comienzo de for
    sumaTotalRonda += acumPuntosJug; //suma todos los puntos de cada ronda


    cout << endl << "Puntos por ronda: " << acumPuntosJug << ". Puntos totales: " << (sumaTotalRonda + puntosTotalesJugador) << endl;
    cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
    cin >> jugada;

    while (jugada != 0){ //comienza while
        tirada++; //dentro del while suma cada vez que suma. Al principio porque arranca en 1 afuara. acá arranca la segunda tirada.
        limpiarPantalla();

        cout << "Juega: " << jugador << ". " << endl;
        cout << "Nro de Ronda: " << nroRonda << endl << "Tirada:" << tirada << endl << endl; //Veo numero de ronda y tirada

        tirarDados(dados);
        mostrarDados(dados);
        acumPuntosJug = sumarPuntos(dados);

        acumPuntosJug = sumarPuntos(dados); //suma puntos por ronda, se reinicia en cada comienzo de for
        sumaTotalRonda += acumPuntosJug; //suma todos los puntos de cada ronda

        cout << endl << "Puntos por ronda: " << acumPuntosJug << ". Puntos totales: " << (sumaTotalRonda + puntosTotalesJugador) << endl;

    //mostrar puntos si los dados son distintos de la ronda
    //sumarPuntos

        cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
        cin >> jugada;
    } //cierra while del primer jugado

    return sumaTotalRonda;//retorna el total sumado de la ronda.
}
int main()
{
     //Inicialización de la función random
    srand(time(NULL));

    // jugadores y vector de dados
    string jugador1, jugador2;
    //int dados [3];

    //acumula puntos por Ronda y se reinicia en cada ronda
    //int acumPuntosJug1;
    //int acumPuntosJug2;
    int nroRonda = 0; //se tiene que incrementar a medida que pasan las rondas
    int puntos;
    int tirada; // suma tiradas por ronda
    //define quien comienza el juego
    bool comienzaElJuego;

    // Acumulador puntos por cada ronda y se va sumando con cada cambio de turno.No se reinicia.
    int sumaTotalJug1 = 0;
    int sumaTotalJug2 = 0;

    //mostrar los numeros del dado
    //variable ronda de juego
    bool rondaJuego = true;


    cout << "BIENVENIDO A BONZO" << endl << "-------------------------------------------------------------" << endl;
    cout << "Antes de jugar deben registrar sus nombres" << endl;
    cout << "Jugador 1" << endl;
    cin >> jugador1;
    cout << "Jugador 2" << endl;
    cin >> jugador2;

    if (definirTurnos() == true){
        //define la ronda
        cout << "comienza el jugador: " << jugador2 << endl << endl;
        comienzaElJuego = true;//verdadero -> comienza el 2
    }
    else
    {
        cout << "Comienza el jugador: " << jugador1 << endl << endl;
        comienzaElJuego = false;//falso -> comienza el 1
        //define ronda
    }
    cout << endl << "presione una tecla para continuar...";
    _getch();//hace una pausa hasta que toques una letra. Tuve que incluir conio.h al comienzo. Ver si mostraron otra alternativa para la pausa.

    int puntosRonda; //variable temporal para capturar los puntos que hace un jugador en una ronda.

    //for de las rondas
    for(int x = 0; x < 6; x ++){//***dejo ciclo en 6, juegan 3 rondas cada uno. Para pruebas más cortas.
        if(x%2==0)
            nroRonda++;

        if(comienzaElJuego == false){//Juega JUGADOR 1
            //cambio el valor de la variable para que en la próxima vuelta del ciclo vaya al siguiente jugador.
            comienzaElJuego = true;
            //juego el turno.
            puntosRonda = jugarTurno(nroRonda, jugador1, sumaTotalJug1);//recibe la ronda, el jugador1 y sus puntos hasta el momento.
            //hay 3 opciones para puntosRonda:
            //1. trae puntos porque sumó ok.
            //2. trae cero porque perdió los puntos.
            //3. trae -1 porque perdió el juego, en el caso que saque triple nro prohibido.
            if(puntosRonda > 0)
                sumaTotalJug1 += puntosRonda;

        } // cierra if de jugador 1
        else {//Juega JUGADOR 2
            comienzaElJuego = false;//vuelvo a cambiar el estado para que después de pasar por acá, vaya a jugar el otro jugador.
            puntosRonda = jugarTurno(nroRonda, jugador2, sumaTotalJug2);
            if(puntosRonda > 0)
                sumaTotalJug2 += puntosRonda;
        }//cierra else de jugador 2

    } //cierra for de Rondas.

    //limpio pantalla y muestro el final.
    limpiarPantalla();
    cout << endl << endl << "** JUEGO TERMINADO **" << endl << endl;
    cout << "Total " << jugador1 << ": " << sumaTotalJug1 << " || " << "Total " << jugador2 << ": " << sumaTotalJug2 << endl;
    if(sumaTotalJug1 > sumaTotalJug2)
        cout << "Gana " << jugador1 << " con " << sumaTotalJug1 << " puntos. " << endl;
    else
        cout << "Gana " << jugador2 << " con " << sumaTotalJug2 << " puntos. " << endl;

    return 0;



    return 0;
}
