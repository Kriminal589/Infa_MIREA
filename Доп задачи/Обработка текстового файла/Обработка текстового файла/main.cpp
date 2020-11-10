#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(){
    
    map<char,int> alph{
        {'a',0}, {'e',1}, {'i',2}, {'o',3}, {'u',4}, {'y',5}
    };
    map<int,char> alph_1{
        {0,'a'}, {1,'e'}, {2,'i'}, {3,'o'}, {4,'u'}, {5,'y'}
    };
    
    int arr[6];
    for (int i = 0; i < 6; i++){
        arr[i] = 0;
    }
    
    char file[] = "/Users/user/Desktop/Информатика/lesson.txt";
    ifstream in (file);
    
    char ch;
    while (!in.eof()){
        ch = ' ';
        in >> ch;
        if (!isdigit(ch)){
            if ((ch == 'a')||(ch == 'e')||(ch == 'i')||(ch == 'o')||(ch == 'u')||(ch == 'y')){
                arr[alph[ch]]++;
            }
        }
    }
    in.close();
    
    int max = -1; int j = 1;
    for (int i = 0; i < 6; i++){
        if (max < arr[i]){
            max = arr[i];
            j = i;
        }
    }
    
    cout << "Больше всего буквы \"" << alph_1[j]<<"\"" << endl;
}
