#include "massive.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

massive::massive(int x){
    this->N = x;
}

void massive::set_massive(){
    int x;
    for (int i = 0; i < N; i++){
        cin >> x;
        this->x[i] = x;
    }
}

void massive::get_massive(){
    for (int i = 0; i < N; i++){
        cout << setw(5) << x[i];
    }
    cout<<endl;
}

void massive::ReMassive(){
    for (int i = 0; i < N/2; i++){
        swap(x[i], x[N-i-1]);
    }
}

void massive::get_length(){
    cout << N << endl;
}
