#include<boost/shared_ptr.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    boost::shared_ptr<std::ofstream> ofp; 
    if (!ofp)
        cout << "Log file not initialized" << endl;
    ofp.reset(new ofstream());
    if (!ofp)
        cout << "Log file not initialized" << endl;
    cout << *ofp << endl;
    ofp->open("log.txt", std::ios::out);
    *ofp << "Test worked" << endl;
    ofp->close();
    /*ofp.reset(fopen("log.txt", "w"));
    fputs("Test worked", *ofp);
    fclose(*ofp);*/
}
