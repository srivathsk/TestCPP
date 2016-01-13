#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int* arr = new int(10);

    boost::shared_ptr<int>  arr1 = arr;

    cout << "Addr of arr is " << &arr << endl;
    cout << "Addr of arr1 is " << &arr1.get() << endl;
}

