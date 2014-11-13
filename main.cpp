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
    string Command;

    //stock int in order to give as argument to method
    int Id;
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Seconde;
    char Value;
    int D7;

    //time structure
    time_t time;
    struct tm date;

    // get commands entered by users
    cin>>Command;

    while (Command.compare("EXIT")!=0) {

        #ifdef MAP
        cout<< "nouveau depart boucle" << endl;
        cout<< "la commande entree est : " << Command << endl;
        #endif

      if (Command.compare("STATS_C")==0) {

        #ifdef MAP
        cout<< "Appel a la commande STATS_C" << endl;
        #endif

        cin>>Id;

        //Function called
        Lyon->Stats_C(Id);

        //trace
        #ifdef MAP
            cout<<Id<<endl;
        #endif

        // Clear the command
        Command="";

     } else if (Command.compare("STATS_D7_H24")==0) {

        #ifdef MAP
        cout<< "Appel a la commande STATS_D7_H24" << endl;
        #endif

        cin>>D7;
        if (D7==7)
            D7=0;
        cin>>Hour;
        //--------------call the methode here-------------------
        Lyon->STATS_D7_H24(D7,Hour);
        //trace
        #ifdef MAP
        cout<<D7<<endl;
        cout<<Hour<<endl;
        #endif

        // Clear the command
        Command="";

      } else if (Command.compare("STATS_D7")==0) {

        #ifdef MAP
        cout<< "Appel a la commande STATS_D7" << endl;
        #endif

          cin>>D7;
          //attention dimanche doit etre le 1er jour
          if (D7==7)
              D7=0;
          //--------------call the methode here---------------

          (*Lyon).STATS_D7(D7);
          //trace
          #ifdef MAP
          cout<<D7<<endl;
          #endif

        // Clear the command
        Command="";
      }
      else if (Command.compare("ADD")==0) {

          #ifdef MAP
          cout<< "Appel a la commande ADD" << endl;
          #endif

          // stock into int
           cin>>Id;
           cin>>Year;
           cin>>Month;
           cin>>Day;
           cin>>Hour;
           cin>>Minute;
           cin>>Seconde;
           cin>>D7;
           cin>>Value;

          #ifdef MAP
          cout<< "Id : "<<Id<<", Year : "<<Year<<", Month : "<<Month<<", Day : "<<Day<<", Hour : "<<Hour<<", Minute : "<<Minute<<", Seconde : "<<Seconde<<", D7 : "<<D7<<", Value : "<<Value<<endl;
          #endif


        // ----------------------------call the addMethode here----------------------------
        //time=castTime(Year, Month, Day, Hour, Minute, Seconde);

            date.tm_year=Year - 1900;
            date.tm_mon=Month -1; // cause january = 0
            date.tm_mday=Day;
            date.tm_hour=Hour;
            date.tm_min=Minute;
            date.tm_sec=Seconde;
            date.tm_isdst=-1;

            time=mktime(&date);

        (*Lyon).AddState(time , Id, Value);


        // Clear the command
        Command="";

            }
      else if (Command.compare("MAX_TS")==0) {

        #ifdef MAP
        cout<< "Appel a la commande MAX_TS" << endl;
        #endif


        (*Lyon).Max_TS();

        // Clear the command
        Command="";

            }

        #ifdef MAP
        cout<< "attente d'une nouvelle consigne" << endl;
        #endif
        // wait for a new command
        cin>>Command;
   }

    delete Lyon;
   return 0;
}

