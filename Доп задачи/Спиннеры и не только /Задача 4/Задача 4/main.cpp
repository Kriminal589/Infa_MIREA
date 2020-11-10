#include <iostream>
using namespace std;
int main(){
    int n; cout<<"Введите кол-во мест: "; cin >> n;
    if (n % 6 != 0 || n <= 0){
        cout<<"Мест должно быть больше 0 и их кол-во должно быть кратно 6"<<endl;
        return EXIT_FAILURE;
    }
    int *a = new int[n];
    int c; cin >> c; int x;
    if (c <= 0){
        cout << "Число должно быть больше 0" << endl;
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < n; i++)
        a[i] = 0;
    
    for (int i = 1; i <= c; i++){
        cin >> x;
        if (x <= 0){
            cout << "Число должно быть больше 0" << endl;
            return EXIT_FAILURE;
        }
        a[x-1] = 1;
    }
    
    int count = 0; int k = 0; int coup = 0; int j = n - 4*(n/6); int pred_coup=0;
    for (int i = 0; i < (n-j); i++){
        if (a[i] == 1)
            k++;
        else{
            k = 0; i++; coup = 0;
            while (i % 4 != 0)
                i++;
            i--;
        }
        if ((k == 4) && (a[n - count-1] == 1) && (a[n - count - 2] == 1)){
            coup++;
            if (coup > pred_coup)
                pred_coup = coup;
        }
        if ((i != 0) && ((i+1) % 4 == 0))
            count += 2;
    }
    cout<<pred_coup<<endl;
}
