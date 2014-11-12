
/*************************************************************************
                           City  -  description
                             -------------------
    d√©but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <City> (fichier City.cpp) --

using namespace std;
#include <iostream>
#include <string>
#include <time.h>

#include "City.h"
#include "Sensor.h"

//----------------------------------------------------- M√©thodes publiques

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
    
} //----- Fin de M√©thode

void City::AddState(time_t time, int day, int id, char Value)
{
	#ifdef MAP
	cout<< "Ajout d'un etat" << endl;
	#endif

	Sensor* cur = &(*listSensors);

    while(((*cur).GetNext())!=NULL and (*cur).GetId()!=id)
    {
        cur=(*cur).nextSensor;
    }
    
    //case the sensor doesn't already exist
    if((*cur).GetNext()==NULL and (*cur).GetId()!=id)
    {
		#ifdef MAP
		cout<< "Ajout d'un capteur" << endl;
		#endif
		
        Sensor * newSensor = new Sensor(id);
        (*cur).nextSensor = newSensor;
        cur=(*cur).nextSensor;
        howManySensors++;

    }


    (*cur).SensorUpdate(time, sensorStateToInt(Value));
    
    updateTraffic(time);
}

void City :: Max_TS(){
	cout << howManySensors << " ont ÈtÈ enreistrÈs" << endl;
	cout << "The max trafic was : "<<(int)(100*(maximumValues/howManySensors))<<" %."<<endl;
	cout << "It was at : "<< ctime(&trafficTime)<<endl;
}

void City :: Stats_C(int ID){
	
	Sensor* cur = listSensors;
    while((*cur).GetId()!=ID)
    {
        cur=(*cur).nextSensor;
    }
    
    (*cur).StatsIdSensor();   
	
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
	Sensor * sensorTemp = new Sensor();
    listSensors = sensorTemp;

    howManySensors=0;
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
    Sensor* cur;
    Sensor* nextcur=listSensors;
    while (nextcur==NULL){
        cur=nextcur;
        nextcur=nextcur->GetNext();
        cur->~Sensor();
    }
    listSensors=NULL;
    delete this;
} //----- Fin de ~City


//------------------------------------ Private methodes

int City :: sensorStateToInt (char Value)
{
	switch (Value)
		{
		case 'V':
			return 0;
			break;
		case 'J':
			return 1;
			break;
		case 'R':
			return 2;
			break;
		case 'N':
			return 3;
			break;
		default: 
			return -1;
		}
}

bool City :: isThereTraffic (int Value)
{
	switch (Value)
		{
		case 0:
			return false;
			break;
		case 1:
			return false;
			break;
		case 2:
			return true;
			break;
		case 3:
			return true;
			break;
		default: 
			return false;
		}
}

void City :: updateTraffic(time_t time)
{
	
    realTimeSensorState=0;
    
    Sensor* cur = listSensors;
    while(((*cur).GetNext())!=NULL) //declencher verif des 5 mins ?
    {
			
        if(isThereTraffic((*cur).lastState))
        {
			realTimeSensorState++;
        }
        cur=(*cur).nextSensor;

    }

    if(realTimeSensorState>maximumValues)
    {
		#ifdef MAP
		cout<<"trafic max atteind"<<endl;
		#endif
		
        maximumValues=realTimeSensorState;
        trafficTime=time;
    }
}



