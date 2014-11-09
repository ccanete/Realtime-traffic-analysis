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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    void DisplayStats(int tab[4]);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void DisplayMax(int tab[7]);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void addState(int time, int day, int id, int traffic,int sensorState);

    void updateTraffic(int traffic, int time);


//------------------------------------------------- Surcharge d'opérateurs
    City & operator = ( const City & unCity );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    City ( const City & unCity );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    City ( );
    // Mode d'emploi :
    //
    // Contrat :
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



    //string max_TS();

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    //sensors states classified by days and hours
    unsigned int sensorsState [7][24][4];

    //Array list of sensors
    Sensor* listSensors;
    //Number of sensors
    int howManySensors;

    //table of the maximum values
    unsigned int maximumValues;
    //date and state of the max traffic
    unsigned int trafficTime;
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
