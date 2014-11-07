#include <iostream>
#include <cstring>
//#include "Sensor.h"
//#include "City.h"
using namespace std;

int main(void)
{

    string data;
    string command;


   getline(cin,command);
   cout<<command<<endl;//pour tester la validite
   while (command.compare("EXIT")!=0) {
      if (command.substr(0,7).compare("STATS_C")==0) {
    data=command.substr(7,command.length());

     cout<<data<<endl;

     } else if (command.substr(0,12).compare("STATS_D7_H24")==0) {
        data=command.substr(12,command.length());
        cout<<data<<endl;

      } else if (command.substr(0,8).compare("STATS_D7")==0) {
          data=command.substr(8,command.length());
         cout<<data<<endl;


      }
      else if (command.substr(0,3).compare("ADD")==0) {
          data=command.substr(3,command.length());
          cout<<data<<endl;


            }
      else if (command.substr(0,7).compare("STATS_%")==0) {
          data=command.substr(7,command.length());
          cout<<data<<endl;


            }
      command="";
       getline(cin,command);
   }

   return 0;
}

