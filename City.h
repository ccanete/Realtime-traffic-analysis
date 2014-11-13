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

    void AddState(time_t time, int id, char Value);
    // ADdState add a sensor object to the sensors array list if it still does not exist, update its state if it exists and update the statistics

    void STATS_D7_H24(int day,int hour);
    // STATS_D7_H24 displays the statistic of all the sensors for one hour on one day in the week (ex: what is the traffic the mondays at 14:00) with this syntax:
    //
    //	V <value>%
    //	J <value>%
    //	R <value>%
    //	N <value>%
    //

    void STATS_D7(int day);
    // STATS_D7_H24 displays the statistic of all the sensors for one day in the week (ex: what is the traffic the mondays) with this syntax:
    //
    //	V <value>%
    //	J <value>%
    //	R <value>%
    //	N <value>%
    //
    // @params : int day : 1:7 (1:monday..7:sunday), the day the user wants to display the stats.

    void Max_TS();
    // Max_TS displays the moment with the worse traffic reccord. It displays the date of the beginning of this state with this synthax:
    //
    //	<YYYY> <MM> <DD> <H> <M> <S> <value>%
    //

    void Stats_C(int ID);
    // Stats_C 
    //

//-------------------------------------------- Constructeurs - destructeur

    City ( );
    // Manual :
    // 
    //


    virtual ~City ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    void updateTraffic(time_t time);

    bool isThereTraffic (int Value);

    int sensorStateToInt (char Value);

    void sensorStateUpdate(float* timeActivate);

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    //sensors states classified by days and hours
    unsigned int sensorsState [7][24][4];

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
    unsigned int realTimeSensorState;
    //Time of the last state inserted
    unsigned int timeLastInsert;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <City>

#endif // XXX_H
