/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <City> (fichier City.h) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisées
#include "Sensor.h"
#include <time.h>


//------------------------------------------------------------------------
// Rôle de la classe <City>
//
//
//------------------------------------------------------------------------

class City
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AddState(time_t time, int id, char value);
    // ADdState add a sensor object to the sensors array list if it still does not exist, update its state if it exists and update the statistics

    void Stats_D7_H24(int day,int hour);
    // Stats_D7_H24 displays the statistic of all the sensors for one hour on one day in the week (ex: what is the traffic the mondays at 14:00) with this syntax:
    //
    //	V <value>%
    //	J <value>%
    //	R <value>%
    //	N <value>%
    //

    void Stats_D7(int day);
    // Stats_D7_H24 displays the statistic of all the sensors for one day in the week (ex: what is the traffic the mondays) with this syntax:
    //
    //	V <value>%
    //	J <value>%
    //	R <value>%
    //	N <value>%
    //
    // @params : int day : 1:7 (1:monday..7:sunday), the day the user wants to display the stats.

    void Max_Ts();
    // Max_Ts displays the moment with the worse traffic reccord. It displays the date of the beginning of this state with this synthax:
    //
    //	<YYYY> <MM> <DD> <H> <M> <S> <value>%
    //

    void Stats_C(int id);
    // Stats_C
    //

//-------------------------------------------- Constructeurs - destructeur

    City ( );
    // Manual :
    //
    //


    virtual ~City ( );
    //Destructor wich delete all the sensors of the city

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    void updateTraffic(time_t time);
    //calcul and stock the moment and the number of sensors corresponding to Max_Ts

    bool isThereTraffic (int value);
    //return true if value is R or N

    int sensorStateToInt (char value);
    //transform value char to a corresponding int
    //v->0    J->1    R->2    N->3

    void sensorStateUpdate(Sensor cur, time_t actualTime);
    //fill the tab with day hour and value with time spend actived for each Sensor

    int modifyDay(int value);
    //return the indice of the day in the bristish system

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    //sensors states classified by days and hours
    float sensorsState [7][24][4];

    //Array list of sensors
    Sensor* listSensors;
    //Number of sensors
    float howManySensors;

    //table of the maximum values
    float maximumValues;
    //date and state of the max traffic
    time_t trafficTime;
    unsigned int trafficDelay;

    //RealTime state
    time_t realTimeSensorState;
    //Time of the last state inserted
    time_t timeLastInsert;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <City>

#endif // XXX_H
