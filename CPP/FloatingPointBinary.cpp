#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
    cout << "Enter floating pointer decimal part " << endl;
    char number[10];
    cin >> number;
    float floating = atof(number);
    cout << floating << endl;
    int pos = 1;
    int binary[20];
    while (floating > 0.0 && pos <= 20)
    {
        float denom = pow(2.0,pos);
        float value = 1.0/denom;
        cout << value << endl;
        if (floating >= value)
        {
            cout << "Adding 1" << endl;
            binary[pos-1] = 1;
            floating -= value;
        } else{
            cout << "Adding 0" << endl;
            binary[pos-1] = 0;
        }

        ++pos;
    }
    if (pos <= 20)
        binary[pos-1] = -1;
    for (size_t i=0; i<20 && binary[i] != -1; ++i)
        cout << binary[i];
    //cout << endl;
}
