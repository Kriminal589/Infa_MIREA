//
//  AllClass.cpp
//  4_3_1
//
//  Created by Andrey Novikov on 12.04.2021.
//

#include "AllClass.hpp"

void Class1::in_out(){
    cout << "Размер массива: ";
    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[i] = x;
    }
}

void Class2::in_out(){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

void Class2::sort(){
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (a[i] < a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
