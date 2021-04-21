#include "AllClass.hpp"

Class1::Class1(string name){
    this->name = name+"_1";
}

void Class1::GetterName(int n){
    if (n == 0)
        cout << name << endl;
}

Class2::Class2(string name):Class1(name){
    this->name = name+"_2";
}

void Class2::GetterName(int n){
    if (n == 0)
        cout << name << endl;
    this->Class1::GetterName(n-1);
}

Class3::Class3(string name):Class1(name){
    this->name = name+"_3";
}

void Class3::GetterName(int n){
    if (n == 0)
        cout << name << endl;
    this->Class1::GetterName(n-1);
}

Class4::Class4(string name):Class1(name){
    this->name = name+"_4";
}

void Class4::GetterName(int n){
    if (n == 0)
        cout << name << endl;
    this->Class1::GetterName(n-1);
}

Class5::Class5(string name):Class1(name){
    this->name = name+"_5";
}

void Class5::GetterName(int n){
    if (n == 0)
        cout << name << endl;
}

Class6::Class6(string name):Class3(name),Class2(name){
    this->name = name+"_6";
}

void Class6::GetterName(int n){
    if (n == 0)
        cout << name << endl;
    this->Class2::GetterName(n-1);
    this->Class3::GetterName(n-1);
}

Class7::Class7(string name):Class4(name),Class5(name){
    this->name = name+"_7";
}

void Class7::GetterName(int n){
    if (n == 0)
        cout << name<<endl;
    this->Class4::GetterName(n-1);
    this->Class5::GetterName(n-1);
}

Class8::Class8(string name):Class6(name),Class7(name){
    this->name = name+"_8";
}

void Class8::GetterName(int n){
    if (n == 0)
        cout << name<<endl;
    this->Class6::GetterName(n-1);
    this->Class7::GetterName(n-1);
}

