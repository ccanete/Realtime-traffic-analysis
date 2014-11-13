
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

 void City::STATS_D7_H24(int day, int hour){
     int stats[4];
     int sum;
     
     for (int i=0;i<4;i++)
     {
		 sum = sensorsState[day-1][hour][i];
	 }
    //day-1 becauseday=[1:7]

     stats[0]=sensorsState[day-1][hour][0];
     stats[1]=sensorsState[day-1][hour][1];
     stats[2]=sensorsState[day-1][hour][2];
     stats[3]=sensorsState[day-1][hour][3];
     if (sum!=0){
     stats[0]=stats[0]/sum;
     stats[1]=stats[1]/sum;
     stats[2]=stats[2]/sum;
     stats[3]=stats[3]/sum;
     }
     cout<<"V "<<stats[0]<<"%"<<endl;
     cout<<"J "<<stats[1]<<"%"<<endl;
     cout<<"R "<<stats[2]<<"%"<<endl;
     cout<<"N "<<stats[3]<<"%"<<endl;
 }

 void City::STATS_D7(int day){

     int stats[4];
     stats[0]=0;
     stats[1]=0;
     stats[2]=0;
     stats[3]=0;
     int sum;

     for (int hour=0;hour<24;hour++){
        stats[0]+=sensorsState[day-1][hour][0];
        stats[1]+=sensorsState[day-1][hour][1];
        stats[2]+=sensorsState[day-1][hour][2];
        stats[3]+=sensorsState[day-1][hour][3];
     }
     sum= stats[0]+ stats[1]+ stats[2]+ stats[3];
     if (sum!=0){
     stats[0]=stats[0]/sum;
     stats[1]=stats[1]/sum;
     stats[2]=stats[2]/sum;
     stats[3]=stats[3]/sum;
     }

     cout<<"V "<<stats[0]<<"%"<<endl;
     cout<<"J "<<stats[1]<<"%"<<endl;
     cout<<"R "<<stats[2]<<"%"<<endl;
     cout<<"N "<<stats[3]<<"%"<<endl;
 }



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
    cout << howManySensors << " ont ÈtÈ enregistrÈs" << endl;
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
    for(int i=0;i<7;i++){
        for(int j=0;j<24;j++){
            for(int k =0;k<4;k++){
                sensorsState[i][j][k]=0;
            }
        }
    }


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



