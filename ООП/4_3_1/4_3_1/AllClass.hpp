#ifndef AllClass_hpp
#define AllClass_hpp

#include <iostream>
using namespace std;

class BasicClass{
public:
    int a[100];
    int n;
};

class Class1:virtual public BasicClass{
public:
    void in_out();
};

class Class2:virtual public BasicClass{
public:
    void sort();
    void in_out();
};

class Class3:public Class1, public Class2{};

#endif
