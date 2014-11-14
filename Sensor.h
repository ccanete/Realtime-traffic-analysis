/*************************************************************************
                           ${file_base}  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( Sensor_H )
#define Sensor_H

//--------------------------------------------------- Interfaces utilis�es
#include <time.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <${file_base}>
//
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:

    Sensor *  NextSensor;
    //pointer to the next sensor in the list of City
    int LastState;
    //State corresponding to the last add
    time_t LastTime;
    //date of the last add(seconde)



//----------------------------------------------------- M�thodes publiques
    void StatsIdSensor();
    // Display the current sensor's stats

    void SensorUpdate(time_t time,int state);
    //adding the actived time by the current sensor in traffic[4] and updating LastTime

    int GetId();
    // return the Id of the current Sensor

    void Add(Sensor theOneToAdd);
    // Add a new Sensor after the current Sensor

//------------------------------------------------- Surcharge d'op�rateurs
    //  ${file_base} & operator = ( const ${file_base} & un${file_base} );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Sensor();
    //default constructor

    Sensor(int id);
    //constructor using the new Id

    virtual ~Sensor();
    // destructor

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    float traffic [4];
    //time passed in each of the four state

    int idSensor;
    //Id identifing the Sensor
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <${file_base}>

#endif // Sensor_H
