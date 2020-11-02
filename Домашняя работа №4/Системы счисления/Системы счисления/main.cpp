#include <iostream>
#include <math.h>
#include <map>
#include <ctype.h>
using namespace std;
int main(){
    
    map<char, double> alpha_0 = {
        {'0',0},{'1',1},{'2',2},{'3',3},{'4', 4},{'5', 5},{'6', 6},{'7',7},{'8',8},{'9',9},
        {'A',10}, {'B',11}, {'C',12}, {'D',13}, {'E',14}, {'F',15}, {'G',16}, {'H',17}, {'I',18},
        {'J',19}, {'K',20}, {'L',21}, {'M',22}, {'N',23}, {'O',24}, {'P',25}, {'Q',26}, {'R',27},
        {'S',28}, {'T',29}, {'U',30}, {'V',31}, {'W',32}, {'X',33}, {'Y',34}, {'Z',35}, {'-',-2}
    };
    
    map<double, char> alpha_1 = {
        {0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},
        {10,'A'}, {11,'B'}, {12,'C'}, {13,'D'}, {14,'E'}, {15,'F'}, {16,'G'}, {17,'H'}, {18,'I'},
        {19,'J'}, {20,'K'}, {21,'L'}, {22,'M'}, {23,'N'}, {24,'O'}, {25,'P'}, {26,'Q'}, {27,'R'},
        {28,'S'}, {29,'T'}, {30,'U'}, {31,'V'}, {32,'W'}, {33,'X'}, {34,'Y'}, {35,'Z'}, {-2,'-'}
    };
    
    string number; int f_system;
    cout<<"Введите начальное число: "; cin>>number;
    cout<<"Введите начальную систему счисления: "; cin>>f_system;
    if (f_system < 2 || f_system > 36){
        cout<<"Введена невозможная система счисления."<<endl;
        return EXIT_FAILURE;
    }
    long int z = number.length() - 1;
    int n_10 = 0; int p; double max = -1;
    
    for (int i = 0; i < number.length(); i++){
        int p = alpha_0[number[i]];
        if (max < p){
            max = p;
        }
    }
    
    if (max >= f_system){
        cout<<"Введено неверное число или начальная система счисления."<<endl;
        return EXIT_FAILURE;
    }
    
    for (long int i = z; i >= 0; i--){
        p = alpha_0[number[i]];
        if (p == -2)
            continue;
        n_10 += p * pow(f_system,abs(i-z));
    }
    
    int count = 0; int a = n_10; int s_system;
    cout<<"Введите конечную систему счисления: "; cin >> s_system;
    
    if (a == 0){
        cout<<"Итоговое число: "<< 0<<endl;
        return 0;
    }
    
    while(a > 0){
        count++;
        a /= s_system;
    }
   
    char array[count];
    
    for (int i = count-1; i >= 0; i--){
        char f = alpha_1[n_10%s_system];
        array[i] = f;
        n_10 /= s_system;
    }
    
    cout<<"Итоговое число: ";
    if (alpha_0[number[0]] == -2){
        cout<<"-";
        for (int i = 0; i < count; i++)
            cout<<array[i];
        cout<<endl;
    }
    else{
        for (int i = 0; i < count; i++)
            cout<<array[i];
        cout<<endl;
    }
}
