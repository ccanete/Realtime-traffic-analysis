


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

//----------------------------------------------------- Methodes publiques

int Sensor::GetId(){
    return   idSensor;
}


void Sensor::Add(Sensor theOneToAdd){
    NextSensor=&theOneToAdd;
}




void Sensor::StatsIdSensor()
// Display the current sensor's stats
{
    // calculing percentage in a tab
    float tab[4];
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

} //----- End of the Method



 void Sensor::SensorUpdate(time_t currentTime, int state)
 //adding the actived time by the current sensor in traffic[4] and updating LastTime
 {
    //testing if currentTime is bigger in order not to have a negative number
    if(currentTime<LastTime)
    {
        #ifdef MAP
        cout << "ERROR" << "\r\n";
        #endif
    }
    //if the sensor is still activated
    if (difftime(currentTime,LastTime)<300)
    {
        traffic[LastState]+=difftime(currentTime,LastTime);
    }
    //if the sensor has no add since 5 minutes
    else {
        traffic[LastState]+=300;
    }
    //updating LastTime and LastState
      LastTime=currentTime;
      LastState=state;

 }

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor ()
//Default constructor
{
    #ifdef MAP
    //cout << "Appel au constructeur de Sensor par default" << "\r\n";
    #endif

    NextSensor=NULL;
    LastState=-1;
}

Sensor::Sensor(int id)
//constructor using the new Id
{
#ifdef MAP
cout << "Appel au constructeur "<< "\r\n";
#endif
      idSensor=id;
      //Sensor * sensorTemp = new Sensor();
      //NextSensor=sensorTemp;
      NextSensor=NULL;
      traffic[0]=0;
      traffic[1]=0;
      traffic[2]=0;
      traffic[3]=0;
      //to avoid a problem at the first add
      LastState=-1;
      LastTime=0;
} //----- End of constructor


Sensor::~Sensor ( )
{
    #ifdef MAP
    //cout << "Appel au destructeur de <${file_base}>" << "\r\n";
    #endif
} //----- End of Destructor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
