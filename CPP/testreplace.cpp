#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() 
{
    std::vector<string> v;
    v.push_back("1");
    v.push_back("Test");
    string src = "Test";
    string dest = "Replaced";
    std::replace(v.begin(), v.end(), src, dest);
    cout << v[1] << endl;
    std::vector<string> v2;
    v2.insert(v2.begin(), v.begin(), v.end());
    cout << "Size of v2 is " << v2.size() << endl;
}
