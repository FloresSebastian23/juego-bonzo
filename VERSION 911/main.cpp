#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
using namespace std;

//funcion definir turnos
bool definirTurnos()
{   int numeroTurnos;
    numeroTurnos = rand()% 2 + 1;
    cout << "el numero tirado fue:" << endl << numeroTurnos << endl; //nos muestra el numero para corroborar que funcione
    if(numeroTurnos % 2 == 0) //evalúa si el nro es par o impar
    {
        return true; //devuelve true si es par
    }
    return false; //devuelve false si es impar
}

//Funciones tirar dados
void tirarDados(int dados[])  //recibe un vector vacío
{    for (int x = 0; x < 3 ; x++) //recorre el vector vacío usando la x del for
    {
      dados[x] = rand()% 6 + 1;// carga cada índice del vector con la función rand.
    }
}
//mostrar dados dado de tres
void mostrarDados(int dados[], int &dadosDisponiblesJug)
{   int dado;
    for(int x = 0; x < dadosDisponiblesJug; x++)
    {        dado = dados[x];
        cout << "dado "  << (x + 1) << ": " << dado<< endl;
    }
}

// evaluarDados


//funcion suma puntos si evaluar dados == true
int sumarPuntos(int dados[], int dadosDisponibles) //recibe un vector de dados y los dados disponibles
{
    int acu = 0; //acumula puntos y devuelve esta variable
    if(dadosDisponibles == 3){
    for(int x =0; x < 3; x ++) //recorre los índices del vector dados
    {
        acu += dados[x]; //acumula el puntaje
        }
    }
    else if(dadosDisponibles == 2){
     for( int x = 0; x < 2;x ++){
        acu+= dados[x];
     }
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

// funcion coincidencias
int coincidenciasDados(int dados[], int nroRonda, int dadosDisponiblesJug){
    int contador = 0;
    for(int x = 0; x < 3; x++){
        if(dados[x]== nroRonda){
            contador++;
        }
    }
    return contador;
}

//funcion jugar turno

//int jugarTurno(int nroRonda)
 int jugarTurno(int nroRonda, string jugador, int & dadosDisponiblesJug, int puntosTotalesJugador)
    {
    int acumPuntosJug = 0; //suma por tirada
    int dados[3];
    int jugada; //para seguir jugando valor 1 o 0;
    int sumaTotalRonda = 0; //por ronda
    int tirada = 0;
    int coincidencia = 0;

    do{
        tirada++; //dentro del while suma cada vez que suma. Al principio porque arranca en 1 afuara. acá arranca la segunda tirada.
        limpiarPantalla();

        cout << "Juega: " << jugador << ". " << endl;
        cout << "Nro de Ronda: " << nroRonda << endl << "Tirada:" << tirada << endl << endl; //Veo numero de ronda y tirada

        tirarDados(dados);
        mostrarDados(dados,dadosDisponiblesJug);
        coincidencia =coincidenciasDados(dados, nroRonda,dadosDisponiblesJug);
        if (coincidencia == 0){
            acumPuntosJug = sumarPuntos(dados,dadosDisponiblesJug); //suma puntos por ronda, se reinicia en cada comienzo de for
            sumaTotalRonda+= acumPuntosJug; //suma todos los puntos de cada ronda
            cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
        }
        else if (coincidencia == 1){
            acumPuntosJug = 0;
            sumaTotalRonda = 0;
            cout << "** Obtuviste el nro. prohibido, termina el turno." << endl;
            system("pause");
            return 0;
        }
        else if (coincidencia == 2){
            acumPuntosJug = 0;
            dadosDisponiblesJug = 2;

            cout << "****Obtuviste dos nros prohibidos, termina el turno." << endl;
            cout << " Proxima ronda jugará con dos dados. " << endl;
            system("pause");
            return 0;
        }
        else if (coincidencia == 3){
            cout << "Sacaste tres dados con el número prohibido: Fin del juego. " << endl;
            system("pause");
          //  return -1;

        }

        cout << endl << "Puntos por tirada: " << acumPuntosJug << ". Puntos Ronda: " << sumaTotalRonda << ". Puntos totales: " << (sumaTotalRonda + puntosTotalesJugador) << endl;

        cin >> jugada;
    } while (jugada != 0 && coincidencia == 0); //cierra while del primer jugador

    if(dadosDisponiblesJug == 2){
        dadosDisponiblesJug = 3;
    }

    return sumaTotalRonda;//retorna el total sumado de la ronda.
}

int main()
{ //tildes en español
    setlocale(LC_ALL,"spanish");

  //Inicialización de la función random
    srand(time(NULL));

    //jugadores
    string jugador1, jugador2;

    //variablaes que se mandan desde el main
    int nroRonda = 0; //se tiene que incrementar a medida que pasan las rondas
    int puntos;
    int tirada; // suma tiradas por ronda
    //define quien comienza el juego con una variable booleana
    bool comienzaElJuego;


    // Acumulador puntos por cada ronda y se va sumando con cada cambio de turno.No se reinicia.
    int sumaTotalJug1 = 0;
    int sumaTotalJug2 = 0;

    //Sirve para los dados disponibles

    int dadosDisponiblesJug1 = 3;
    int dadosDisponiblesJug2 = 3;

    //variable ronda de juego
    bool rondaJuego = true;

    //Mostrar por con consola
    //menu principal
    int opcion;

    cout << "BIENVENIDO A BONZO" << endl << "-------------------------------------------------------------" << endl;
    cout << endl;
    cout << "1- JUGAR" << endl;
    cout << "2- ESTADISTICAS" << endl;
    cout << "3- CREDITOS" << endl;
    cout << "--------------------------------" << endl;
    cout << "0- SALIR DEL JUEGO" << endl;
    cout << "OPCION:";
    cin >> opcion;

    switch (opcion)
    {

    case 1:
        system("cls");

        cout << "Antes de jugar deben registrar sus nombres" << endl;
        cout << "Jugador 1" << endl;
        cin >> jugador1;
        cout << "Jugador 2" << endl;
        cin >> jugador2;

        if (definirTurnos() == true)
        {            //define la ronda
            cout << "comienza el jugador: " << jugador2 << endl;
            comienzaElJuego = true;
        }
        else
        {
            cout << "Comienza el jugador: " << jugador1 << endl;
            comienzaElJuego = false;
            //define ronda
        }
       //  cout << endl << "presione una tecla para continuar...";
        system("pause");
       int puntosRonda; //variable temporal para capturar los puntos que hace un jugador en una ronda.

        //for de las rondas
    for(int x = 0; x < 12; x ++){
        if(x%2==0) // pregunta por el valor de x para las 6 rondas.
            nroRonda++; //pregunnta si la vuelta del indice es par o impar y suma rondas del 1 al 6.


        if(comienzaElJuego == false){//Juega JUGADOR 1
            //cambio el valor de la variable para que en la próxima vuelta del ciclo vaya al siguiente jugador.
            comienzaElJuego = true;
            //juego el turno.

            puntosRonda = jugarTurno(nroRonda, jugador1, dadosDisponiblesJug1, sumaTotalJug1);//recibe la ronda, el jugador1 y sus puntos hasta el momento.
            //hay 3 opciones para puntosRonda:
            //1. trae puntos porque sumó ok.
            //2. trae cero porque perdió los puntos.
            //3. trae -1 porque perdió el juego, en el caso que saque triple nro prohibido.
            if(puntosRonda > 0){
                sumaTotalJug1 += puntosRonda; //acumula los puntos de las rondas
            } else if (puntosRonda < 0 ){
                sumaTotalJug1=-1;
        } // cierra if de jugador 1
        else {//Juega JUGADOR 2
            comienzaElJuego = false;//vuelvo a cambiar el estado para que después de pasar por acá, vaya a jugar el otro jugador.
            puntosRonda = jugarTurno(nroRonda, jugador2, dadosDisponiblesJug2,sumaTotalJug2);
            if(puntosRonda > 0)else if (puntosRonda < 0 ){
                sumaTotalJug1=-1;
        } // cierra if de jugador 1
                sumaTotalJug2 += puntosRonda;
        }        //cierra else de jugador 2

    } //cierra for de Rondas.

    cout << endl << endl << "* JUEGO TERMINADO *" << endl << endl;
    cout << "Total " << jugador1 << ": " << sumaTotalJug1 << " || " << "Total " << jugador2 << ": " << sumaTotalJug2 << endl;
    if(sumaTotalJug1 > sumaTotalJug2)
        cout << "Gana " << jugador1 << " con " << sumaTotalJug1 << " puntos. " << endl;
    else
        cout << "Gana " << jugador2 << " con " << sumaTotalJug2 << " puntos. " << endl;

    return 0;

        break;
    case 2:
        cout << "campo vacio" << endl;
        break;
    case 3:
        cout << "Flores Sebastian " << "Número de legajo: 31865" << endl;
        cout << "Navarrete Solange " << "Número de legajo: 31957" << endl;
        cout << "Vizcarra Pamela " << "Número de legajo: 31719 " << endl;
        cout << "Grupo número 21" << endl;
        break;
    case 0:
        cout << "¿seguro desea salir del juego?" << endl << "marque 0 para confirmar" << endl;
        cin >> opcion;
        return 0;
        break;
    default:
        cout << "OPCION INCORRECTA" << endl;
        break;
    }

    return 0;
}
