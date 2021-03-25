#include <iostream>
using namespace std;
int main(){
    string S; cin >> S;
    unsigned long i = S.length()-1;
    for (; i >= 0; i--){
        cout << S[i];
    }
    cout<<endl;
}
