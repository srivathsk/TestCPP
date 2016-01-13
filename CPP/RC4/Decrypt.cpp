#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Base64_RC4.h"

using namespace std;


int main()
{
    std::ifstream ifp;
ifp.open("options.tng7-dt.dat", ios::binary);
    //ifp.open("RC4.dat", ios::binary);
    if (ifp.is_open())
        cout << "File opened" << endl;
    ifp.seekg(0, ifp.end);
    size_t size = ifp.tellg();
    ifp.seekg(0, ifp.beg);
    char* buffer = new char[size];
    ifp.read(buffer, size);
//cout.write(buffer, size);
    CRC4 rc4;
rc4.Decrypt(buffer, "Hey,_that's_easy!!!");
    //rc4.Decrypt(buffer, "RC4");
    std::ofstream ofp;
    ofp.open("DecryptedOptions.zip", ios::binary);
    ofp.write(buffer, size);
    cout << buffer << endl;
    /*while (ifp.eof())
    {
        std::string line;
        std::getline(ifp, line);
        cout  << line << endl;
    }*/
}
