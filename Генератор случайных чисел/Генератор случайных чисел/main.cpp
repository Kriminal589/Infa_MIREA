#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
int main(){
    long int m, i, c, S;
    cin >> m >> i >> c;
    
    srand(time(0));
    S = rand() % 100;
    
    for (i; i < 15; i++){
        S = (m*S + i) % c;
        cout << S << endl;
    }
    return 0;
}
