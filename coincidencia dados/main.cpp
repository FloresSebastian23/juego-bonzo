#include <iostream>

using namespace std;

// funcion coincidencias
int coincidenciasDados(int dados[], int nroRonda)
{
    int contador = 0;
    for(int x = 0; x < 3; x++)
    {
        if(dados[x]== nroRonda)
        {
            contador++;
        }
    }
    return contador;
}

int main()
{

    switch (coincidenciasDados)
    {

    case 1:
        if (coincidencia == 0)
        {
            acumPuntosJug = sumarPuntos(dados); //suma puntos por ronda, se reinicia en cada comienzo de for
            sumaTotal+= acumPuntosJug; //suma todos los puntos de cada ronda
        }
        cout << "no hubo ningun numero prohido"  << endl;
        break;

    case 2:
        if (coincidencia == 1)
        {
            acumPuntosJug = 0;
        }
        cout << "el jugador obtuvo 1 numero prohido" << "pierde los puntos acumulados"  << endl;
        break;

    case 3:
        if (coincidencia == 2)
        {
            acumPuntosJug = 0;
            bandera2dados = false;
        }
        cout << "el jugador obtuvo 2 numeros prohidos" << "proxima ronda tira con 2 dados" << endl;
        break;

    case 3:
        if (coincidencia == 3)
        {

            return 0;
        }
        cout << "el jugador obtuvo 3 numeros prohidos" << "game over" << endl;
        break;
    }

}
