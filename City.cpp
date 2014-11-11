
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
#include <time.h>

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

void City::AddState(time_t time, int day, int id, char Value)
{
	#ifdef MAP
	cout<< "Ajout d'un etat" << endl;
	#endif
	
	Sensor * cur = listSensors; //prblm pointeurs
	
    while(cur->GetId()!=id or cur->GetNext()!=NULL)
    {
        #ifdef MAP
        cout << "Je suis dans la boucle" << endl;
        #endif
        cur=cur->GetNext();
    }
    
    
    //case the sensor doesn't already exist
    if(cur->GetNext()==NULL and cur->GetId()!=id)
    {
		#ifdef MAP
		cout<< "Ajout d'un capteur" << endl;
		#endif
		
        Sensor * newSensor = new Sensor(id);
        cur->Add(*newSensor);
        cur=cur->GetNext();

    }

    updateTraffic(isThereTraffic(Value), time);

    cur->SensorUpdate(time, sensorStateToInt(Value)); //modifier sensor en consequence

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

bool City :: isThereTraffic (char Value)
{
	switch (Value)
		{
		case 'V':
			return false;
			break;
		case 'J':
			return false;
			break;
		case 'R':
			return true;
			break;
		case 'N':
			return true;
			break;
		default: 
			return false;
		}
}

void City :: updateTraffic(int traffic, time_t time)
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



