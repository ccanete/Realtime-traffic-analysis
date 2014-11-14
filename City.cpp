
/*************************************************************************
                           City  -  description
                             -------------------
    dÃ©but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <City> (fichier City.cpp) --

using namespace std;
#include <iostream>
#include <string>
#include <time.h>

#include "City.h"
#include "Sensor.h"

//----------------------------------------------------- Methodes publiques

 void City::STATS_D7_H24(int day, int hour){

     day=modifyDay(day);
     float stats[4];
     stats[0]=0;
     stats[1]=0;
     stats[2]=0;
     stats[3]=0;
     float sum;


    stats[0]+=sensorsState[day][hour][0];
    stats[1]+=sensorsState[day][hour][1];
    stats[2]+=sensorsState[day][hour][2];
    stats[3]+=sensorsState[day][hour][3];

     sum= stats[0]+stats[1]+ stats[2]+ stats[3];
     if (sum!=0){
     stats[0]=(stats[0]/sum)*100;
     stats[1]=(stats[1]/sum)*100;
     stats[2]=(stats[2]/sum)*100;
     stats[3]=(stats[3]/sum)*100;
     }

     cout<<"V "<<(int)(stats[0])<<"%"<<"\r\n";
     cout<<"J "<<(int)(stats[1])<<"%"<<"\r\n";
     cout<<"R "<<(int)(stats[2])<<"%"<<"\r\n";
     cout<<"N "<<(int)(stats[3])<<"%"<<"\r\n";
     //cout<<"SUM "<<sum<<"\r\n";


 }

 void City::STATS_D7(int day){

     day=modifyDay(day);
     float stats[4];
     stats[0]=0;
     stats[1]=0;
     stats[2]=0;
     stats[3]=0;
     float sum;

     for (int hour=0;hour<24;hour++){
        stats[0]+=sensorsState[day][hour][0];
        stats[1]+=sensorsState[day][hour][1];
        stats[2]+=sensorsState[day][hour][2];
        stats[3]+=sensorsState[day][hour][3];
     }
     sum= stats[0]+stats[1]+ stats[2]+ stats[3];
     if (sum!=0){
     stats[0]=(stats[0]/sum)*100;
     stats[1]=(stats[1]/sum)*100;
     stats[2]=(stats[2]/sum)*100;
     stats[3]=(stats[3]/sum)*100;
     }

     cout<<"V "<<(int)(stats[0])<<"%"<<"\r\n";
     cout<<"J "<<(int)(stats[1])<<"%"<<"\r\n";
     cout<<"R "<<(int)(stats[2])<<"%"<<"\r\n";
     cout<<"N "<<(int)(stats[3])<<"%"<<"\r\n";
 }



void City::AddState(time_t time, int id, char Value)
{
    #ifdef MAP
    cout<< "Ajout d'un etat" << "\r\n";
    #endif

    Sensor* cur = &(*listSensors);

    //searching for the sensor with id or the end of list
    while(((*cur).GetNext())!=NULL and (*cur).GetId()!=id)
    {
        cur=(*cur).nextSensor;
    }

    //case the sensor doesn't already exist
    if((*cur).GetNext()==NULL and (*cur).GetId()!=id)
    {
        #ifdef MAP
        cout<< "Ajout d'un capteur" << "\r\n";
        #endif
        Sensor * newSensor = new Sensor(id);
        (*cur).nextSensor = newSensor;
        cur=(*cur).nextSensor;
        howManySensors++;

    }

    if ((*cur).lastState!=-1)
    {
        sensorStateUpdate(*cur, time);
    }

    (*cur).SensorUpdate(time, sensorStateToInt(Value));

    updateTraffic(time);

    //delete timeActivate;
}

void City :: Max_TS(){
    if(howManySensors!=0)
    {
        struct tm traficStruct; //structure tm
        traficStruct=*localtime(&trafficTime); //create structure of the trafic date
        int year=traficStruct.tm_year+1900;
        int month=traficStruct.tm_mon+1;
        int hour=traficStruct.tm_hour;
        int day=traficStruct.tm_mday;
        int minute=traficStruct.tm_min;
        int seconde=traficStruct.tm_sec;

        //	<YYYY> <MM> <DD> <H> <M> <S> <value>%
        cout<<year<<" "<<month<<" "<<day<<" "<<hour<<" "<<minute<<" "<<seconde<<" "<<(int)(100*(maximumValues/howManySensors))<<"%"<<"\r\n";
    }
    else{
        cout<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<"%"<<"\r\n";
    }
}

void City :: Stats_C(int ID){

    Sensor* cur = listSensors;
    while((*cur).GetId()!=ID and ((*cur).GetNext())!=NULL)
    {
        cur=(*cur).nextSensor;
    }
    if((*cur).GetId()==ID)
    {
        (*cur).StatsIdSensor();
    }
    else{
        // to display stats of this sensor
        cout<<"V "<<0<<"%"<<"\r\n";
        cout<<"J "<<0<<"%"<<"\r\n";
        cout<<"R "<<0<<"%"<<"\r\n";
        cout<<"N "<<0<<"%"<<"\r\n";
    }
}


//-------------------------------------------- Constructeurs - destructeur
City::City ( )
// Algorithme :
//
{
#ifdef MAP
    //cout << "Appel au constructeur de <City>" << "\r\n";
#endif

    //sensors states classified by days and hours
    //sensorsState[7][24][4];
    for(int i=0;i<7;i++){
        for(int j=0;j<24;j++){
            for(int k =0;k<4;k++){
                sensorsState[i][j][k]=0;
            }
        }
    }


    //table of the maximum values
    maximumValues=0;
    //date and state of the max traffic
    trafficTime=0;
    trafficDelay=0;

    //RealTime state
    realTimeSensorState=0;
    //Time of the last state inserted
    timeLastInsert=0;

    //Sensors
    Sensor * sensorTemp = new Sensor();
    listSensors = sensorTemp;

    howManySensors=0;
} //----- Fin de City


City::~City ( )
// Algorithme :
//
{
#ifdef MAP
    //cout << "Appel au destructeur de <City>" << "\r\n";
#endif
    Sensor* cur;
    Sensor* nextcur=listSensors;
    while (nextcur!=NULL){
        cur=nextcur;
        nextcur=nextcur->GetNext();
        delete cur;
    }
    listSensors=NULL;

} //----- Fin de ~City


//------------------------------------ Private methodes

int City :: sensorStateToInt (char Value)
{
    switch (Value)
        {
        case 'V':
            return 0;
            break;
        case 'J':
            return 1;
            break;
        case 'R':
            return 2;
            break;
        case 'N':
            return 3;
            break;
        default:
            return -1;
        }
}

bool City :: isThereTraffic (int Value)
{
    switch (Value)
        {
        case 0:
            return false;
            break;
        case 1:
            return false;
            break;
        case 2:
            return true;
            break;
        case 3:
            return true;
            break;
        default:
            return false;
        }
}

void City :: updateTraffic(time_t time)
{

    realTimeSensorState=0;

    Sensor* cur = listSensors;
    while(((*cur).GetNext())!=NULL)
    {
        if(isThereTraffic((*cur).lastState) and difftime(time,(*cur).lastTime)<300)
        {
            realTimeSensorState++;
        }
        cur=(*cur).nextSensor;
    }

    if(realTimeSensorState>maximumValues)
    {
        maximumValues=realTimeSensorState;
        trafficTime=time;
    }


}
void City::sensorStateUpdate(Sensor cur, time_t actualTime){

    struct tm lastAdd;
    time_t temps=cur.lastTime; //lastDate reccord
    lastAdd=*localtime(&temps); //create structure of the last creation date
    int hour=lastAdd.tm_hour;
    int day=modifyDay(lastAdd.tm_wday);
    int minute=lastAdd.tm_min;
    int seconde=lastAdd.tm_sec;
    float timeActiv = difftime(actualTime, temps);

    #ifdef MAP
    cout<< "Date d'ajout : " << ctime(&temps) << "\r\n";
    cout<< "temps : "<< timeActiv << "\r\n";
    cout << difftime(actualTime, temps) << "\r\n";
    #endif



if (minute<55){
    sensorsState[day][hour][cur.lastState]+=timeActiv;
    #ifdef MAP
    cout<< "Temps ajoute : " << timeActiv << "\r\n";
    #endif

}

else{



    if(hour!=23){
        //case between two hours
        if(seconde+minute*60+timeActiv>3600)
        {
            sensorsState[day][hour][cur.lastState]+=3600-seconde-minute*60;
            sensorsState[day][hour+1][cur.lastState]+=seconde+minute*60+timeActiv-3600;
        }
        //case only over one hour
        else
        {
            sensorsState[day][hour][cur.lastState]+=timeActiv;
        }

    }
    //bewteen two days
    else
    {
        //case between two hours
        if(seconde+minute*60+timeActiv>3600)
        {
            //not sunday
            if (day!=6)
            {
                sensorsState[day][hour][cur.lastState]+=3600-seconde-minute*60;
                sensorsState[day+1][0][cur.lastState]+=seconde+minute*60+timeActiv-3600;
            }
            //case sunday
            else{
                sensorsState[day][hour][cur.lastState]+=3600-seconde-minute*60;
                sensorsState[0][0][cur.lastState]+=seconde+minute*60+timeActiv-3600;
            }
        }
        //case only over one hour
        else{
            sensorsState[day][hour][cur.lastState]+=timeActiv;
        }

    }
}

}

int City :: modifyDay(int Value)
{
    switch (Value)
        {
        case 7:
            return 0;
            break;
        default:
            return Value;
        }
}
