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

Sensor *  nextSensor;

int lastState;



//----------------------------------------------------- M�thodes publiques
void StatsIdSensor();
    // Mode d'emploi :
    //
    // Contrat :return the sensors stats in a string
    //

void SensorUpdate(time_t time,int state);
    //Mode d'emploi : update tab traffic[4] and lastTime
Sensor* GetNext();// send next sensor
int GetId();// send the id of a sensor
void Add(Sensor theOneToAdd);// to add a sensor if there is no next

//------------------------------------------------- Surcharge d'op�rateurs
  //  ${file_base} & operator = ( const ${file_base} & un${file_base} );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Sensor( const Sensor  & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor(); //contructeur par defautmake
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor(int Id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
time_t lastTime;//date of the last add(seconde)
float traffic [4];// time passed in each state
int idSensor;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <${file_base}>

#endif // Sensor_H

