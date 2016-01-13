#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int main(int argc, char** argv)
{
    std::ifstream ifp;
    ifp.open("/dbbdata/rbslogs/RDFPercentage.txt");
    if (ifp.is_open())
        cout << "File opened" << endl; 
    while (ifp.is_open() && !ifp.eof())
    {
       string line;
       getline(ifp, line);
       if (line == "60")
            cout << line << endl;
    }
}

