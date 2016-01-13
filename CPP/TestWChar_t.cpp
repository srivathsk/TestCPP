#include <wchar.h>
#include <iostream>
using namespace std;

int main()
{
    wchar_t* testStr;
    testStr = new wchar_t[10];
    testStr  = L"Test";
    cout << *testStr << endl;
    wchar_t testChar = 'a';
    cout << testChar << endl;
}

