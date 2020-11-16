#include <iostream>
#include <fstream>
#include <list>
using namespace std;
int main(){
    list<char> a;
    ifstream file("/Users/AndreyNovikov/Desktop/Информатика/lesson.txt");
    char k;
    while(!file.eof()){
        file>>k;
        a.push_back(k);
    }
    file.close();
    list <char> :: iterator i;
    list <char> :: iterator j;
    
    
    for (i = a.begin(); i != a.end(); i++){
        for (j = a.begin(); j != a.end(); j++){
            if (*j > *i){
                swap(*j,*i);
            }
        }
    }
    
    a.unique();
    
    for (i = a.begin(); i != a.end(); i++){
        cout << (*i) << " ";
    }
    cout << endl;
}
