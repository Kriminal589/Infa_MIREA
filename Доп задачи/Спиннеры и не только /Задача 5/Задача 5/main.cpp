#include <iostream>
using namespace std;
int main(){
    int N,K;
    cout<<"Введите N: ";
    cin >> N;
    if (N <= 0){
        cout << "Слишком мало мест."<<endl;
        return EXIT_FAILURE;
    }
    int* a = new int[12];
    
    for (int i = 0; i < N+2; i++){
        if ((i == 0) || (i == N+1))
            a[i] = 1;
        else
            a[i] = 0;
    }
    cout <<"Введите K: ";
    cin >> K;
    if (K > N){
        cout<<"Слишком много учеников."<<endl;
        return EXIT_FAILURE;
    }
    int max; max = 0;
    int j = 0; int pred_max = 0; int last_max = 0;
    
    for (int s = 0; s < K; s++){
        
        for (int i = 0; i < N+2; i++){
            
            if (a[i] == 0){
                max++;
            }
            
            else {
                if (max > pred_max){
                    pred_max = max;
                    j = i - 1;
                    last_max = max;
                }
                max = 0;
            }
            
        }
        a[j - (pred_max/2)] = 1;
        if (pred_max % 2 == 0){
            cout << pred_max/2 - 1<<" ";
            cout << pred_max - pred_max/2 << endl;
        }
        else{
            cout << pred_max/2 << " ";
            cout << pred_max - pred_max/2 - 1<< endl;
        }
        pred_max = 0;
        cout<<endl;
        
    }
    if (last_max % 2 == 0){
        cout << last_max/2 - 1<<endl;
        cout << last_max - last_max/2 << endl;
    }
    else{
        cout << last_max/2 <<endl;
        cout << last_max - last_max/2 - 1<< endl;
    }
}
