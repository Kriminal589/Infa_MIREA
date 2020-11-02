#include <iostream>
using namespace std;
int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if (A<0 || B <= 0 || C < A)
        return EXIT_FAILURE;
    int N = (C - A)/B;
    cout<<N<<endl;
}
