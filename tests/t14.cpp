#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string cmd = "ADD";
	int s = 0;
	int d7 = 5;
	string val = "V";
	
	for ( int d = 1 ; d < 11 ; d++)
	{
		d7++;
		if (d7 > 7) d7 = 1;
		
	for ( int h = 0; h < 24; h++)
	{
		for ( int mn = 0; mn <60 ; mn++)
		{
			for ( int id = 1 ; id < 1501 ; id++)
			{
				if (id < 756) val = "V";
				else if ( d7 < 6)
				{
					if ( 6 < h && h < 9) val = "J";
					else if ( 17 < h && h < 20 && d7 == 5) val = "N";
					else if ( 17 < h && h < 20) val = "R";
					else val = "V";
				}
				else val = "V";
				cout << cmd << " " << id << " " << 2014 << " " << 10 << " " << d << " " << h << " " << mn << " " << s << " " << d7 << " " << val << endl;
			}
		}
	}
}

cout << "STATS_D7 1" <<endl << "STATS_D7 5" << endl << "STATS_D7 6" <<endl;

cout << "STATS_D7_H24 1 0" <<endl << "STATS_D7_H24 5 0" << endl << "STATS_D7_H24 6 0" <<endl;

cout << "STATS_D7_H24 1 7" <<endl << "STATS_D7_H24 5 7" << endl << "STATS_D7_H24 6 7" <<endl;

cout << "STATS_D7_H24 1 19" <<endl << "STATS_D7_H24 5 19" << endl << "STATS_D7_H24 6 19" <<endl;

cout << "STATS_C 1" << endl;
cout << "STATS_C 1500" << endl;

cout << "MAX_TS" << endl;

cout << "EXIT" << endl;
   return 0;
}

