#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {
if (argc != 2) {
    cerr << "Incorrect number of arguments" << endl;
    return 1;
}
stringstream cmd;
cmd << "bkill " << atoi(argv[1]);
int st = ::system(cmd.str().c_str());
if(st == 0) {
  cout << "Kill succeeded" << endl;
} else {
   cout << "Kill failed" << endl;
}
}
