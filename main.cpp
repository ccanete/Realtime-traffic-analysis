#include <iostream>
#include <string>
#include "Sensor.h"
#include "City.h"
#include <cstdlib>
using namespace std;

int main(void)
{

    //create a city
    City* Lyon=new City();
    //to stock the cin
    string StringId;
    string StringYear;
    string StringMonth;
    string StringDay;
    string StringHour;
    string StringMinute;
    string StringSeconde;
    string StringValue;
    string StringD7;
    string Command;
    //to convert into int
    int IntId;
    int IntYear;
    int IntMonth;
    int IntDay;
    int IntHour;
    int IntMinute;
    int IntSeconde;
    int IntValue;
    int IntD7;


   getline(cin,Command);
   //cout<<Command<<endl;//pour tester la validite
   while (Command.compare("EXIT")!=0) {
      if (Command.substr(0,7).compare("STATS_C")==0) {
    Command=Command.substr(7+1,Command.npos);
    StringId=Command.substr(0,Command.find(" "));
    IntId=atoi(StringId.c_str());
    //call the methode here
     cout<<StringId<<endl;
     StringId="";

     } else if (Command.substr(0,12).compare("STATS_StringD7_H24")==0) {
        Command=Command.substr(12+1,Command.npos);
        StringD7=Command.substr(0,Command.find(" "));
        IntD7=atoi(StringD7.c_str());
        Command=Command.substr(Command.find(" ")+1,Command.npos);
        StringHour=Command.substr(0,Command.find(" "));
        IntHour=atoi(StringHour.c_str());
        //call the methode here
        //test
        cout<<StringD7<<endl;
        cout<<StringHour<<endl;
        StringD7=" ";
        StringHour=" ";

      } else if (Command.substr(0,8).compare("STATS_StringD7")==0) {
          Command=Command.substr(8+1,Command.npos);
          StringD7=Command.substr(0,Command.find(" "));
          IntD7=atoi(StringD7.c_str());
          //call the methode here
          //test
          cout<<StringD7<<endl;
          StringD7="";

      }
      else if (Command.substr(0,3).compare("ADD")==0) {

          Command=Command.substr(3+1,Command.npos);

          StringId=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringYear=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringMonth=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringDay=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringHour=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringMinute=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringSeconde=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringD7=Command.substr(0,Command.find(" "));

          Command=Command.substr(Command.find(" ")+1,Command.npos);
          StringValue=Command.substr(0,Command.find(" "));
          // convertion into int
           IntId=atoi(StringId.c_str());
           IntYear=atoi(StringYear.c_str());
           IntMonth=atoi(StringMonth.c_str());
           IntDay=atoi(StringDay.c_str());
           IntHour=atoi(StringHour.c_str());
           IntMinute=atoi(StringMinute.c_str());
           IntSeconde=atoi(StringSeconde.c_str());
           IntValue=atoi(StringValue.c_str());
           IntD7=atoi(StringD7.c_str());


          // verif all string and int
          cout<<StringId<<" "<< IntId<<endl;
          cout<<StringYear<<" "<< IntYear<<endl;
          cout<<StringMonth<<" "<< IntMonth<<endl;
          cout<<StringDay<<" "<< IntDay<<endl;
          cout<<StringHour<<" "<< IntHour<<endl;
          cout<<StringMinute<<" "<< IntMinute<<endl;
          cout<<StringSeconde<<" "<< IntSeconde<<endl;
          cout<<StringD7<<" "<< IntD7<<endl;
          cout<<StringValue<<" "<< IntValue<<endl;
        // ----------------------------call the addMethode here----------------------------
        //->

          // in order to empty the string
          StringId="";
          StringYear="";
          StringMonth="";
          StringDay="";
          StringHour="";
          StringMinute="";
          StringSeconde="";
          StringValue="";
          StringD7="";


            }
      else if (Command.substr(0,7).compare("MAX_TS")==0) {
          Command=Command.substr(7+1,Command.npos);
          cout<<Command<<endl;


            }
      Command="";
       getline(cin,Command);
   }

   return 0;
}

