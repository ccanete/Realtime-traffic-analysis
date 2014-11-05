/*************************************************************************
                           City  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <City> (fichier City.h) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <City>
//
//
//------------------------------------------------------------------------ 

class City : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

AddState

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

	//sensors states classified by days and hours
	unsigned int sensorsState [7][24][4];

	//Array list of sensors
	sensor listSensors ();

	//table of the maximum values
	unsigned int maximumValues [3];
	//date and state of the max traffic
	unsigned int trafficTie;
	unsigned int trafficDelay;

	//RealTime state
	unsigned int realTimeSensorState;
	//Time of the last state inserted
	unsigned int timeLastInsert;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <City>

#endif // XXX_H
