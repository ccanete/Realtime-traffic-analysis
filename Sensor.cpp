
/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright         1   : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
 int[] Sensor::StatsIdSensor()
// Algorithme :
{
	// calculing percentage in a tab
	int tab[4];
	tab[0]= this.traffic[0]/(this.traffic[0]+this.traffic[1]+this.traffic[2]+this.traffic[3]);
	tab[1]= this.traffic[1]/(this.traffic[0]+this.traffic[1]+this.traffic[2]+this.traffic[3]);
	tab[2]= this.traffic[2]/(this.traffic[0]+this.traffic[1]+this.traffic[2]+this.traffic[3]);
	tab[3]= this.traffic[3]/(this.traffic[0]+this.traffic[1]+this.traffic[2]+this.traffic[3]);
	return tab;
} //----- Fin de M�thode

Sensor* Sensor::GetNext()
{
	
	return this.nextSensor;
	
}

 void Sensor::SensorUpdate(int currentTime,int state)
 //
 {
	 // updating traffic[4]
	if (currentTime - this.lastTime<300){
		this.traffic[lastState]=+currentTime - this.lastTime; 
		}
	else { 
		this.traffic[lastState]=+300;
	}
	//updating lastTime and lastState
	this.lastState=currentTime;
	this.lastState=state;

 }

//------------------------------------------------- Surcharge d'op�rateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//${file_base}::${file_base} ( const ${file_base} & un${file_base} )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <${file_base}>" << endl;
#endif
} //----- Fin de ${file_base} (constructeur de copie)


Sensor::Sensor(int Id)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <${file_base}>" << endl;
#endif
    this->idSensor=id;
    this->nextSensor=null;


} //----- Fin de ${file_base}


$//{file_base}::~${file_base} ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <${file_base}>" << endl;
#endif
} //----- Fin de ~${file_base}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
