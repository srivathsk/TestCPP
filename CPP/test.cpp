#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "C++ works here" << endl;
    std::string tmp = "bsub.log";
    char* tmp_pointer = const_cast<char*>(tmp.c_str());
    size_t pos = tmp.find('.');
    cout << "pos is " << pos << endl;
}
