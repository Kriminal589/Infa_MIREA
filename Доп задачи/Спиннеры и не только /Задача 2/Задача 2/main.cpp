#include <iostream>
using namespace std;
int main(){
    int M; cin >> M;
    int s_3 = 0; int s_4 = 0;
    while (M > 2){
        if (M % 4 == 0){
            s_4++;
            M -= 4;
        }
        else {
            s_3++;
            M -= 3;
        }
    }
    if (M == 0){
        cout << s_3<<endl;
        cout << s_4<<endl;
    }
    else{
        cout << 0 << endl;
        cout << 0 << endl;
    }
}
