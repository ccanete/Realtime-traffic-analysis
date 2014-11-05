/*************************************************************************
                           City  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <City> (fichier City.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "City.h"
#include "Sensor.h"
#include "Main.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type City::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
City & City::operator = ( const City & unCity )
// Algorithme :
//
{
} //----- Fin de operator =


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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
// type City::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

	void City::addState(int time, int day, int id, boolean traffic, int sensorState)
	{
		sensor cur = listSensors;
		while(cur.next!=null or cur.id!=id)
		{
			cur=cur.next;
		}
		//case the sensor doesn't already exist
		if(cur.next==null)
		{			
			sensor * newSensor = new sensor(id);
			cur.next=newSensor;
			cur=cur.next;
		}
		
		updateTraffic(traffic, time);
		
		updateSensor(id, time, day, sensorState);
		
		
		
		
		
			
		
