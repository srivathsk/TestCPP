#include <ctime>
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    timespec starttime;
    clock_gettime(CLOCK_REALTIME, &starttime);
    for (size_t i=0; i<10; ++i)
        usleep(1000);
    timespec endtime;
    clock_gettime(CLOCK_REALTIME, &endtime);
    timespec temp;
    if ((endtime.tv_nsec-starttime.tv_nsec)<0) {
        temp.tv_sec = endtime.tv_sec-starttime.tv_sec-1;
        temp.tv_nsec = 1000000000+endtime.tv_nsec-starttime.tv_nsec;
    } else {
        temp.tv_sec = endtime.tv_sec-starttime.tv_sec;
        temp.tv_nsec = endtime.tv_nsec-starttime.tv_nsec;
    }
    double elapsedSecs = endtime.tv_sec - starttime.tv_sec;
    double elapsedNs = endtime.tv_nsec - starttime.tv_nsec;
    cout << "Elapsed secs " << elapsedSecs << endl;
    cout << "Elapsed NS " << elapsedNs << endl;
    cout << "Correct calculation " << temp.tv_sec * 1e+9 + temp.tv_nsec << endl;
}
