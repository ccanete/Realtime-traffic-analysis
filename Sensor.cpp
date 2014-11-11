


/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    debut                : ${date}
    copyright         1   : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

int Sensor::GetId(){
    return   idSensor;
}

void Sensor::Add(Sensor& theOneToAdd){
    if (  nextSensor==NULL){
        *nextSensor=theOneToAdd;
    }
}




void Sensor::StatsIdSensor()
// Algorithme :
{
    // calculing percentage in a tab
    int tab[4];//!!!! a changer car on ne peut renvoyer un tab qui se supprime a la fin de la methode
    tab[0]=   traffic[0]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]);
    tab[1]=   traffic[1]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]);
    tab[2]=   traffic[2]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]);
    tab[3]=   traffic[3]/(  traffic[0]+  traffic[1]+  traffic[2]+  traffic[3]);

    // to display stats of this sensor
    cout<<"V "<<tab[0]<<"%"<<endl;
    cout<<"J "<<tab[1]<<"%"<<endl;
    cout<<"R "<<tab[2]<<"%"<<endl;
    cout<<"N "<<tab[3]<<"%"<<endl;

} //----- Fin de M�thode

Sensor* Sensor::GetNext()
{

    return   nextSensor;

}

 void Sensor::SensorUpdate(int currentTime, int state)
 //
 {
     // updating traffic[4]
    if (currentTime -   lastTime<300){
          traffic[lastState]=+currentTime -   lastTime;
        }
    else {
          traffic[lastState]=+300;
    }
    //updating lastTime and lastState
      lastState=currentTime;
      lastState=state;

 }

//------------------------------------------------- Surcharge d'op�rateurs
//${file_base} & ${file_base}::operator = ( const ${file_base} & un${file_base} )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <${file_base}>" << endl;
#endif
} //----- Fin de ${file_base} (constructeur de copie)

Sensor::Sensor ()
//Alorithme :
{
	#ifdef MAP
	cout << "Appel au constructeur de Sensor par default" << endl;
	#endif
	nextSensor=NULL;
}

Sensor::Sensor(int Id)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <${file_base}>" << endl;
#endif
      idSensor=Id;
      nextSensor=NULL;
      traffic[0]=0;
      traffic[1]=0;
      traffic[2]=0;
      traffic[3]=0;
      //to avoid a problem at the first add
      lastState=-1;
      lastTime=0;
} //----- Fin de ${file_base}


Sensor::~Sensor ( )
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

