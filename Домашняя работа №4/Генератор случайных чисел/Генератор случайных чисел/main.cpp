#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
int main(){
    long long m, i, c, S;
    cin >> m >> i >> c;
    
    srand(time(0));
    //S = rand() % 100;
    long int d = i;
    long a = i;
    for (; a < d + 15; a++){
      //  srand(time_t(0));
        S = rand() % 100;
        //cout << S<<endl;
        
        S = (m*S + i) % c;
        cout << S << endl;
    }
    return 0;
}
