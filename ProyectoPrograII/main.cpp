#include <iostream>  
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
	time_t current_time;
	struct tm local_time;
	int Year = local_time.tm_year + 1900;
	int Month = local_time.tm_mon + 1;
	int Day = local_time.tm_mday;
    Fehca
    cout << "Dejenme dormir" << endl;
    cout << "Testing" << endl;

    cout << "ESTA VIVOOO!!!" << endl;

    cout << "\nBryan favor conectarse >:(\n" << endl;
    cout << "Hola";
    system("cls");
    cin.get();
    return 0;
}



int main ()
{


time ( &current_time );
localtime_s(&local_time, &current_time);



int Hour = local_time.tm_hour;
int Min = local_time.tm_min;
int Sec = local_time.tm_sec;

return 0;
}