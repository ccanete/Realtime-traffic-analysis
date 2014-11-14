#include <iostream>
#include <string>
#include <ctime>

#include "Sensor.h"
#include "City.h"

using namespace std;

int main(void)
{


    //create a city
    City* Lyon = new City();

    //String to stock commands entered by users
    string command;

    //stock int in order to give as argument to method
    int id;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconde;
    char value;
    int d7;

    //time structure
    time_t time;
    struct tm date;

    // get commands entered by users
    cin>>command;

    while (command.compare("EXIT")!=0) {

        #ifdef MAP
        //cout<< "nouveau depart boucle" << "\r\n";
        //cout<< "la commande entree est : " << command << "\r\n";
        #endif

      if (command.compare("STATS_C")==0) {

        #ifdef MAP
        //cout<< "Appel a la commande STATS_C" << "\r\n";
        #endif

        cin>>id;

        //Function called
        Lyon->Stats_C(id);

        //trace
        #ifdef MAP
            cout<<id<<"\r\n";
        #endif

        // Clear the command
        command="";

     } else if (command.compare("STATS_D7_H24")==0) {

        #ifdef MAP
        //cout<< "Appel a la commande Stats_D7_H24" << "\r\n";
        #endif

        cin>>d7;
        cin>>hour;
        //--------------call the methode here-------------------
        Lyon->Stats_D7_H24(d7,hour);
        //trace
        #ifdef MAP
        cout<<d7<<"\r\n";
        cout<<hour<<"\r\n";
        #endif

        // Clear the command
        command="";

      } else if (command.compare("STATS_D7")==0) {

        #ifdef MAP
        //cout<< "Appel a la commande Stats_D7" << "\r\n";
        #endif

          cin>>d7;
          //--------------call the methode here---------------

          (*Lyon).Stats_D7(d7);
          //trace
          #ifdef MAP
          cout<<d7<<"\r\n";
          #endif

        // Clear the command
        command="";
      }
      else if (command.compare("ADD")==0) {

          #ifdef MAP
          //cout<< "Appel a la commande ADD" << "\r\n";
          #endif

          // stock into int
           cin>>id;
           cin>>year;
           cin>>month;
           cin>>day;
           cin>>hour;
           cin>>minute;
           cin>>seconde;
           cin>>d7;
           cin>>value;

          #ifdef MAP
          //cout<< "id : "<<id<<", year : "<<year<<", month : "<<month<<", day : "<<day<<", hour : "<<hour<<", minute : "<<minute<<", seconde : "<<seconde<<", d7 : "<<d7<<", value : "<<value<<"\r\n";
          #endif


        // ----------------------------call the addMethode here----------------------------
        //time=castTime(year, month, day, hour, minute, seconde);

            date.tm_year=year - 1900;
            date.tm_mon=month -1; // cause january = 0
            date.tm_mday=day;
            date.tm_hour=hour;
            date.tm_min=minute;
            date.tm_sec=seconde;
            date.tm_isdst=-1;

            time=mktime(&date);

        (*Lyon).AddState(time , id, value);


        // Clear the command
        command="";

            }
      else if (command.compare("MAX_TS")==0) {

        #ifdef MAP
        //cout<< "Appel a la commande Max_Ts" << "\r\n";
        #endif


        (*Lyon).Max_Ts();

        // Clear the command
        command="";

            }

        #ifdef MAP
        //cout<< "attente d'une nouvelle consigne" << "\r\n";
        #endif
        // wait for a new command
        cin>>command;
   }

    delete Lyon;
   return 0;
}
