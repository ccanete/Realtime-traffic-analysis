#include <iostream>
#include <cstring>
//#include "Sensor.h"
//#include "City.h"
using namespace std;

int main(void)
{
    string command;
    string data;// to stock statu and date	
   /* placer ici la déclaration de votre liste ainsi que
    * son initialisation */

   cin>>command;
   while (command.compare("EXIT")!=0) {
      if (command.compare("STATS_C")==0) {


     cout<<"entree1"<<endl;

     } else if (command.compare("STATS_D7")==0) {

        cout<<"entree2"<<endl;

      } else if (command.compare("STATS_D7_H24")==0) {
         cout<<"entree3"<<endl;


      }
      else if (command.compare("ADD")==0) {
               cout<<"entree3"<<endl;


            }
      else if (command.compare("STATS_%")==0) {
               cout<<"entree3"<<endl;


            }

      cin>>command;
   }

   return 0;
}

