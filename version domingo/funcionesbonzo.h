#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

//Bonzo ve a dormir

bool bonzoVeADormir(int dados[], int dadosDisponibles){
    if(dadosDisponibles == 3) {
        if(dados[0]== dados[1] && dados[0] == dados[2]){
            return true;
        }
    }
    return false;
}
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
    //  dados[x] = 4;
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

//funcion suma puntos si evaluar dados == true
int sumarPuntos(int dados[], int dadosDisponiblesJug) //recibe un vector de dados y los dados disponibles
{
    int acu = 0; //acumula puntos y devuelve esta variable
    if(dadosDisponiblesJug == 3){
    for(int x =0; x < 3; x ++) //recorre los índices del vector dados
    {
        acu += dados[x]; //acumula el puntaje
        }
    }
    else if(dadosDisponiblesJug == 2){
     for( int x = 0; x < 2;x ++){
        acu+= dados[x];
     }
    }
    return acu ; //devuelve los puntos
}

//funcion dibujar dado. se la llama dentro de un for de 3 y devuelve el dibujo de cada dado

void dibujarDado (int dados[], int dadosDisponiblesJug)
{
    for (int x = 0; x < dadosDisponiblesJug; x++ ){

    if(dados[x] == 1)
    {
        cout << "+-----+" << endl;
        cout << "|  x  |" << endl;
        cout << "|     |" << endl;
        cout << "+-----+" << endl;
    }

    if(dados[x] == 2)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "|     |" << endl;
        cout << "+-----+" << endl;
    }

    if(dados[x] == 3)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "|  x  |" << endl;
        cout << "+-----+" << endl;
    }
    if(dados[x] == 4)
    {
        cout << "+-----+" << endl;
        cout << "| x x |" << endl;
        cout << "| x x |" << endl;
        cout << "+-----+" << endl;
    }
    if(dados[x] == 5)
    {
        cout << "+-----+" << endl;
        cout << "|x x x|" << endl;
        cout << "| x x |" << endl;
        cout << "+-----+" << endl;
    }
    if(dados[x] == 6)
    {
        cout << "+-----+" << endl;
        cout << "|x x x|" << endl;
        cout << "|x x x|" << endl;
        cout << "+-----+" << endl;
        }
    }
}

//funcion limpiar pantalla debería ejecutarse después de que el jugador decide seguir tirando dados

void limpiarPantalla(){
    system("CLS");
}

// funcion coincidencias
int coincidenciasDados(int dados[], int nroRonda, int dadosDisponiblesJug){
    int contador = 0;
    for(int x = 0; x < dadosDisponiblesJug; x++){
        if(dados[x]== nroRonda){
            contador++;
        }
    }
    return contador;
}

//funcion jugar turno

//int jugarTurno(int nroRonda)
 int jugarTurno(int nroRonda, string jugador, int& dadosDisponiblesJug, int puntosTotalesJugador,int& dadosDisponiblesOponente)
    {
    int acumPuntosJug = 0; //suma por tirada
    int sumaTotalRonda = 0; //por ronda
    int dados[3];
    int jugada; //para seguir jugando valor 1 o 0;
    int tirada = 0; //incrementa el numero tirada
    int coincidencia = 0; //nro prohibido con ronda

    do{
        tirada++; //dentro del while suma cada vez que tira. Al principio porque arranca en 1 afuera. acá arranca la segunda tirada.
        limpiarPantalla();

        cout << "Juega: " << jugador << ". " << endl;
        cout << "Nro de Ronda: " << nroRonda << endl << "Tirada:" << tirada << endl << endl; //Veo numero de ronda y tirada

        tirarDados(dados);
        //mostrarDados(dados,dadosDisponiblesJug);
        dibujarDado(dados,dadosDisponiblesJug);
        coincidencia =coincidenciasDados(dados, nroRonda,dadosDisponiblesJug);
        if (coincidencia == 0){
            if (bonzoVeADormir (dados,dadosDisponiblesJug) == true){
             int seleccion;
             cout << "Obtuviste un Bonzo ve a dormir; " << endl;
             cout << "Presiona 1 si queres duplicar los puntos o 2 si queres sacarle un dado a tu oponente. " << endl;
             cin >> seleccion;
                if(seleccion  == 1){
                acumPuntosJug = sumarPuntos(dados,dadosDisponiblesJug); //suma puntos por ronda, se reinicia en cada comienzo de for
                sumaTotalRonda+= acumPuntosJug; //duplica los puntos
                } else if(seleccion == 2){
                //quitar dado al oponente
                dadosDisponiblesOponente = 2;
                }
            }

            acumPuntosJug = sumarPuntos(dados,dadosDisponiblesJug); //suma puntos por ronda, se reinicia en cada comienzo de for
            sumaTotalRonda+= acumPuntosJug; //suma todos los puntos de cada ronda
            cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
        }
        else if (coincidencia == 1){
            acumPuntosJug = 0;
            sumaTotalRonda = 0;
            cout << "** Obtuviste el nro. prohibido, termina el turno." << endl;
             cout << "** Perdiste los puntos de esta ronda.**" << endl;
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
           return -1;
        }

        cout << endl << "Puntos por tirada: " << acumPuntosJug << ". Puntos Ronda: " << sumaTotalRonda << ". Puntos totales: " << (sumaTotalRonda + puntosTotalesJugador) << endl;

        cin >> jugada;
    } while (jugada != 0 && coincidencia == 0); //cierra while del primer jugador

    if(dadosDisponiblesJug == 2){
        dadosDisponiblesJug = 3;
    }

    return sumaTotalRonda;//retorna el total sumado de la ronda.
}


#endif // MISFUNCIONES_H_INCLUDED
