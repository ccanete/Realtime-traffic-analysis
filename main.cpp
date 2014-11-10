#include <iostream>
#include <string>
#include "Sensor.h"
#include "City.h"

using namespace std;

int main(void)
{

    //create a city
    City* Lyon=new City();
    //String to stock the cin
    string Command;
    //stock int in order to give as argument to method
    int Id;
    int Year;
    int Month;
    int Day;
    int Hour;
    int Minute;
    int Seconde;
    int Value;
    int D7;
    // stock the new in
    cin>>Command;

    while (Command.compare("EXIT")!=0) {

      if (Command.compare("STATS_C")==0) {

        cin>>Id;
        //-------------------call the methode here----------
        //trace
        cout<<Id<<endl;
        // empty the int
        Id=0;

     } else if (Command.compare("STATS_D7_H24")==0) {

        cin>>D7;
        cin>>Hour;
        //--------------call the methode here-------------------
        //trace
        cout<<D7<<endl;
        cout<<Hour<<endl;
        //empty the string
        D7=0;
        Hour=0;

      } else if (Command.compare("STATS_D7")==0) {

          cin>>D7;
          //--------------call the methode here---------------
          //trace
          cout<<D7<<endl;
          //empty the int
          D7=0;

      }
      else if (Command.compare("ADD")==0) {

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


          // trace
          cout<< Id<<endl;
          cout<< Year<<endl;
          cout<< Month<<endl;
          cout<< Day<<endl;
          cout<< Hour<<endl;
          cout<< Minute<<endl;
          cout<< Seconde<<endl;
          cout<< D7<<endl;
          cout<< Value<<endl;
        // ----------------------------call the addMethode here----------------------------


          // in order to empty the string
          Id=0;
          Year=0;
          Month=0;
          Day=0;
          Hour=0;
          Minute=0;
          Seconde=0;
          D7=0;
          Value=0;


            }
      else if (Command.compare("MAX_TS")==0) {

        //-----------call methode here------------------


            }
      // take the next world in command
      cin>>Command;
   }

   return 0;
}

