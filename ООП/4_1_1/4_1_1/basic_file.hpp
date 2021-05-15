
#ifndef BASIC_FILE_HPP
#define BASIC_FILE_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BasicClass{
private:
    string name;
    BasicClass* parent;
public:
    vector <BasicClass* > children;
    vector <BasicClass* >::iterator t;
    BasicClass (BasicClass* parent, string name);
    BasicClass(BasicClass* parent);
    string GetterName();
    void SetterName(string name);
    void showtree();
    void NewHead(BasicClass* parent);
    BasicClass* HeadParent();
};

class Class1:public BasicClass{
private:
    BasicClass* temp_parent;
    BasicClass* temp_child;
public:
    Class1(BasicClass* parent = 0);
    void buildtree();
    int start();
};
class Class2:public BasicClass{
public:
    Class2(BasicClass* parent, string name);
};

#endif
