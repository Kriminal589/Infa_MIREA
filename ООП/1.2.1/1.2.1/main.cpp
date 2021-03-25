#include <iostream>
#include "Treyg_class.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    cin >> a >> b >> c;
    Treyg_class* treyg = new Treyg_class(a,b,c);
    treyg->P();
    treyg->S();
    return 0;
}
