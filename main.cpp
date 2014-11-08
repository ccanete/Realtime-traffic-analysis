#include <iostream>
#include <cstring>
//#include "Sensor.h"
//#include "City.h"
using namespace std;

int main(void)
{


    //to stock the cin
    string Id;
    string Year;
    string Month;
    string Day;
    string Hour;
    string Minute;
    string Seconde;
    string Value;
    string D7;
    string Command;


   getline(cin,Command);
   //cout<<Command<<endl;//pour tester la validite
   while (Command.compare("EXIT")!=0) {
      if (Command.substr(0,7).compare("STATS_C")==0) {
    Command=Command.substr(7+1,Command.length());
    Id=Command.substr(0,Command.find(" "));
     cout<<Id<<endl;
     Id="";

     } else if (Command.substr(0,12).compare("STATS_D7_H24")==0) {
        Command=Command.substr(12+1,Command.length());
        D7=Command.substr(0,Command.find(" "));
        Command=Command.substr(Command.find(" ")+1,Command.length()-1);
        Hour=Command.substr(0,Command.find(" "));
        //test
        cout<<D7<<endl;
        cout<<Hour<<endl;
        D7=" ";
        Hour=" ";

      } else if (Command.substr(0,8).compare("STATS_D7")==0) {
          Command=Command.substr(8+1,Command.length());
          D7=Command.substr(0,Command.find(" "));
          //test
          cout<<D7<<endl;
          D7="";

      }
      else if (Command.substr(0,3).compare("ADD")==0) {

          Command=Command.substr(3+1,Command.length()-1);

          Id=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Year=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Month=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Day=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Minute=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Seconde=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          D7=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.length()-1);
          Value=Command.substr(0,Command.find(" "));

          // verif all string
          cout<<Id<<endl;
          cout<<Year<<endl;
          cout<<Month<<endl;
          cout<<Day<<endl;
          cout<<Minute<<endl;
          cout<<Seconde<<endl;
          cout<<D7<<endl;
          cout<<Value<<endl;
        // call the addMethode here

          Id="";
          Year="";
          Month="";
          Day="";
          Hour="";
          Minute="";
          Seconde="";
          Value="";
          D7="";


            }
      else if (Command.substr(0,7).compare("MAX_TS")==0) {
          Command=Command.substr(7+1,Command.length());
          cout<<Command<<endl;


            }
      Command="";
       getline(cin,Command);
   }

   return 0;
}

