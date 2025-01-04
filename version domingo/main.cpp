#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include "funcionesbonzo.h"

using namespace std;
//bonzoVe a dormir
//

int main()
{
    //Tildes en espaniol
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
        while (true){
        cout << "BIENVENIDO A BONZO" << endl << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << "1- JUGAR" << endl;
        cout << "2- ESTADISTICAS" << endl;
        cout << "3- CREDITOS" << endl;
        cout << "--------------------------------" << endl;
        cout << "4- SALIR DEL JUEGO" << endl;
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
            {
                //define la ronda
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
            for(int x = 0; x < 12; x ++)
            {
                if(x%2==0) // pregunta por el valor de x para las 6 rondas.
                    nroRonda++; //pregunnta si la vuelta del indice es par o impar y suma rondas del 1 al 6.


                if(comienzaElJuego == false) //Juega JUGADOR 1
                {
                    //cambio el valor de la variable para que en la próxima vuelta del ciclo vaya al siguiente jugador.
                    comienzaElJuego = true;
                    //juego el turno.

                    puntosRonda = jugarTurno(nroRonda, jugador1, dadosDisponiblesJug1, sumaTotalJug1, dadosDisponiblesJug2);//recibe la ronda, el jugador1 y sus puntos hasta el momento.
                    //hay 3 opciones para puntosRonda:
                    //1. trae puntos porque sumó ok.
                    //2. trae cero porque perdió los puntos.
                    //3. trae -1 porque perdió el juego, en el caso que saque triple nro prohibido.
                    if(puntosRonda > 0)
                    {
                        sumaTotalJug1 += puntosRonda; //acumula los puntos de las rondas
                    }
                    else if(puntosRonda < 0)    //vuelve el con un numero negativo, suma -1 y cambia el valor a la x para que no entre en el for
                    {
                        sumaTotalJug1 = -1;
                        x = 12;
                    }
                } // cierra if de jugador 1
                else  //Juega JUGADOR 2
                {
                    comienzaElJuego = false;//vuelvo a cambiar el estado para que después de pasar por acá, vaya a jugar el otro jugador.
                    puntosRonda = jugarTurno(nroRonda, jugador2, dadosDisponiblesJug2,sumaTotalJug2, dadosDisponiblesJug1);
                    if(puntosRonda > 0)
                    {
                        sumaTotalJug2 += puntosRonda;
                    }
                    else if(puntosRonda < 0)   //vuelve el con un numero negativo, suma -1 y cambia el valor a la x para que no entre en el for
                    {
                        sumaTotalJug2 = -1;
                        x = 12;
                    }
                }//cierra else de jugador 2

            } //cierra for de Rondas.

            cout << endl << endl << "* JUEGO TERMINADO *" << endl << endl;
            cout << "Total " << jugador1 << ": " << sumaTotalJug1 << " || " << "Total " << jugador2 << ": " << sumaTotalJug2 << endl;
            if(sumaTotalJug1 > sumaTotalJug2)
            {
                int ganador = sumaTotalJug1;
                string vencedor = jugador1;
                cout << "Gana " << jugador1 << " con " << sumaTotalJug1 << " puntos. " << endl;
            }
            else
            {
                cout << "Gana " << jugador2 << " con " << sumaTotalJug2 << " puntos. " << endl;
                int ganador = sumaTotalJug2;
                string vencedor = jugador2;
            }   // return 0;
               system("pause");
               limpiarPantalla();

            //return 0;

            break;
        case 2:
            cout << "campo vacio" << endl;
            system("pause");
            limpiarPantalla();
            break;
        case 3:
            cout << "Flores Sebastián " << "Número de legajo: 31865" << endl;
            cout << "Navarrete Solange " << "Número de legajo: 31957" << endl;
            cout << "Vizcarra Pamela " << "Número de legajo: 31719 " << endl;
            cout << "Grupo número 21" << endl;
            system("pause");
            limpiarPantalla();
            break;
        case 4:
            cout << "¿Seguro desea salir del juego?" << endl << "marque 4 para confirmar" << endl;
            cin >> opcion;
            return 0;
            break;
        default:
            cout << "OPCIóN INCORRECTA" << endl;
            break;
        }
    }
}
