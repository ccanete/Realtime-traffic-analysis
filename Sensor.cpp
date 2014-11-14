


/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright         1   : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <time.h>


//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

int Sensor::GetId(){
    return   idSensor;
}


void Sensor::Add(Sensor theOneToAdd){
    nextSensor=&theOneToAdd;
}




void Sensor::StatsIdSensor()
// Algorithme :
{
    // calculing percentage in a tab
    float tab[4];//!!!! a changer car on ne peut renvoyer un tab qui se supprime a la fin de la methode
    float somme = traffic[0]+  traffic[1]+  traffic[2]+  traffic[3];
    tab[0]=100*(traffic[0]/somme);
    tab[1]=100*(traffic[1]/somme);
    tab[2]=100*(traffic[2]/somme);
    tab[3]=100*(traffic[3]/somme);

    // to display stats of this sensor
    cout<<"V "<<(int)tab[0]<<"%"<<"\r\n";
    cout<<"J "<<(int)tab[1]<<"%"<<"\r\n";
    cout<<"R "<<(int)tab[2]<<"%"<<"\r\n";
    cout<<"N "<<(int)tab[3]<<"%"<<"\r\n";

} //----- Fin de Methode

Sensor* Sensor::GetNext()
{

    return   nextSensor;

}

 void Sensor::SensorUpdate(time_t currentTime, int state)
 {
    if(currentTime<lastTime)
    {
        #ifdef MAP
        cout << "ATTENTION ERREUR" << "\r\n";
        #endif
    }
    if (difftime(currentTime,lastTime)<300)
    {
      traffic[lastState]+=difftime(currentTime,lastTime);
    }
    else {
          traffic[lastState]+=300;
    }
    //updating lastTime and lastState
      lastTime=currentTime;
      lastState=state;

 }

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
//Alorithme :
{
    #ifdef MAP
    //cout << "Appel au constructeur de Sensor par default" << "\r\n";
    #endif

    nextSensor=NULL;
    lastState=-1;
}

Sensor::Sensor(int Id)
// Algorithme :
//
{
#ifdef MAP
    //cout << "Appel au constructeur de <${file_base}>" << "\r\n";
#endif
      idSensor=Id;
      //Sensor * sensorTemp = new Sensor();
      //nextSensor=sensorTemp;
      nextSensor=NULL;
      traffic[0]=0;
      traffic[1]=0;
      traffic[2]=0;
      traffic[3]=0;
      //to avoid a problem at the first add
      lastState=-1;
      lastTime=0;
} //----- Fin de ${file_base}


Sensor::~Sensor ( )
// Algorithme :
//
{

#ifdef MAP
    //cout << "Appel au destructeur de <${file_base}>" << "\r\n";
#endif
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
