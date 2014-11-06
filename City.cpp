
/*************************************************************************
                           City  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <City> (fichier City.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "City.h"
#include "Sensor.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type City::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//City & City::operator = ( const City & unCity )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
City::City ( const City & unCity )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <City>" << endl;
#endif
} //----- Fin de City (constructeur de copie)


City::City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <City>" << endl;
#endif
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <City>" << endl;
#endif
} //----- Fin de ~City


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
// type City::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    void City::addState(int time, int day, int id, int traffic, int sensorState)
    {
        Sensor* cur = this->listSensors;
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

        this->updateTraffic(traffic, time);

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








