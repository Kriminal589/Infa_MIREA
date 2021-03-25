//
//  main.cpp
//  aplication
//
//  Created by Andrey Novikov on 19.02.2021.
//

#include <iostream>
using namespace std;
int main()
{
    int a; cin >> a;
    if (a < 0 || a > 9)
        std::cout << "N is wrong: "<<a;
    else{
        int* arr = new int[a];
        for (int i = 0; i < a; i++){
            arr[i] = i+1;
        }
        int index = 1;
        for (int i = 0; i < a; i++){
            int j = 0;
            while(j != index){
                cout << arr[j] << " ";
                j++;
            }
            index++;
            cout<<endl;
        }
        
    }
    return(0);
}

