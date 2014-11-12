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
    void AddState(time_t time, int day, int id, char Value);


	void Max_TS();
	
	void Stats_C(int ID);



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

    void updateTraffic(time_t time);
    
    bool isThereTraffic (int Value);
    
	int sensorStateToInt (char Value);


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
