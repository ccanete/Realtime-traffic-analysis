
/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <City> (fichier City.cpp) --

using namespace std;
#include <iostream>
#include <string>

#include "City.h"
#include "Sensor.h"

//----------------------------------------------------- Méthodes publiques

void City::DisplayStats(int tab[4])
// Algorithme :
{
    cout<<"V "<<tab[0]<<"%"<<endl;
    cout<<"J "<<tab[1]<<"%"<<endl;
    cout<<"R "<<tab[2]<<"%"<<endl;
    cout<<"N "<<tab[3]<<"%"<<endl;
} //----- Fin de Methode

void City::DisplayMax(int tab[7])
// Algorithme :
{
    cout<<tab[0]<<" "<<tab[1]<<" "<<tab[2]<<" "<<tab[3]<<" "<<tab[4]<<" "<<tab[5]<<" "<<tab[6]<<"%"<<endl;
    
} //----- Fin de Méthode

void City::addState(int time, int day, int id, int traffic, int sensorState)
{
    Sensor* cur =  listSensors;
    while(cur->GetNext()!=NULL or cur->GetId()!=id)
    {
        cur=cur->GetNext();
    }
    //case the sensor doesn't already exist
    if(cur->GetNext()==NULL)
    {
        Sensor * newSensor = new Sensor(id);
        cur->Add(*newSensor);
        cur=cur->GetNext();
    }

    updateTraffic(traffic, time);

    cur->SensorUpdate(time, sensorState);

}

void City::updateTraffic(int traffic, int time)
{
    realTimeSensorState=0;
    Sensor* cur = listSensors;
    while(cur->GetNext()!=NULL)
    {
        if(traffic)
        {
            realTimeSensorState++;
        }
    }

    if(realTimeSensorState>maximumValues)
    {
        maximumValues=realTimeSensorState;
        trafficTime=time;
    }
}



//-------------------------------------------- Constructeurs - destructeur
City::City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <City>" << endl;
#endif

	//sensors states classified by days and hours
	sensorsState [7][24][4];

    //table of the maximum values
	maximumValues=0;
    //date and state of the max traffic
	trafficTime=0;
	trafficDelay=0;

    //RealTime state
    realTimeSensorState=0;
    //Time of the last state inserted
    timeLastInsert=0;
    
	//Sensors
    listSensors=NULL;
    howManySensors=0;
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
} //----- Fin de ~City








