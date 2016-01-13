#include <time.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    time_t startTime = time(NULL);
    cout << "Started at " << asctime(localtime(&startTime)) << endl;
    cout << "Stated at " << ctime(&startTime) << endl;
    //time(&startTime);
//for (size_t i=0; i<1e+6; ++i)
    //sleep(10);
    int elapsedTime = time(NULL) - startTime;
    cout << "Elapsed " << elapsedTime << endl;
}
