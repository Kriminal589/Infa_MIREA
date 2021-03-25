
#include "Treyg_class.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Treyg_class::Treyg_class(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
}

void Treyg_class::P(){
    cout << a+b+c << endl;
}

void Treyg_class::S(){
    float p = (float)(a+b+c)/2;
    cout << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
}
