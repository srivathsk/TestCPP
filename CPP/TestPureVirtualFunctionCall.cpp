#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class BaseClass {
    public:
        virtual ~BaseClass() { }
        virtual void name() const = 0;
};

class DerivedClass : public BaseClass {
    public:
        void name() const {
            cout << "Derived class name called" << endl;
        }
};

int main(int argc, char** argv) {
    std::vector <DerivedClass> objContainer;  
    objContainer.push_back(DerivedClass());
    const BaseClass& objRef = objContainer.front();  
    // Do some processing using objRef and then you erase the first
    // // element of objContainer
    objContainer.erase(objContainer.begin());   
    objRef.name();  
    // // -> (name() is a pure virtual function in base class, 
    // // which has been implemented in DerivedClass).
    return 0;
}
