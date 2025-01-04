#include <iostream>

using namespace std;

int main()
{
        //variables que funcionan por cada jugador dentro del if
   int acumPuntosJug = 0;
    int dados[3];
    int jugada; //para seguir jugando valor 1 o 0;
    int sumaTotal = 0;
    return 0;


      tirarDados(dados);
        mostrarDados(dados);
        acumPuntosJug = sumarPuntos(dados);

        acumPuntosJug = sumarPuntos(dados); //suma puntos por ronda, se reinicia en cada comienzo de for
        sumaTotal+= acumPuntosJug; //suma todos los puntos de cada ronda
        tirada++; //dentro del while suma cada vez que suma

        cout << "Nro de Ronda: " << nroRonda << endl << "Tirada:" << tirada << endl; //Veo numero de ronda y tirada
        cout << "Puntos por ronda: " << acumPuntosJug << ". Puntos totales: " << sumaTotal << endl;

        mostrar puntos si los dados son distintos de la ronda
        sumarPuntos

        cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
        cin >> jugada;


 cout << "Puntos por ronda: " << acumPuntosJug << ". Puntos totales: " << sumaTotal << endl;
    cout << "Si desea seguir tirando presione 1 sino presione 0" << endl;
    cin >> jugada;n


         system("cls");
        //for de las rondas
        for(int x = 0; x < 12; x ++)
        {
            system("cls");

            if(comienzaElJuego == false) // comienza la primera ronda
            {
               // for (int i=0; i<6; i++)
                {
                    //sumaTotalJug1[i]=
                    jugarTurno(1);
                  //  cout<< sumaTotalJug1[i];
                }
            } // cierra if
            else
            {
               // for (int i=0; i<6; i++)
                {

                   // sumaTotalJug2[i] =
                    jugarTurno(1);
                   //  cout<< sumaTotalJug2[i];
                }
            } //cierra else del segundo jugador
        } //cierra for
        system("pause");

        // return 0;

}
