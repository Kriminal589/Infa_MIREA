#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()

{

    double x;
    ofstream text("/Users/user/Desktop/lesson.txt");
    if (text.is_open())
    {
        cout << "Файл создан открыт для записи" << endl;
    }

    cout << "Введите количество чисел" << endl;
    
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        text << x << " ";

    }
    text.close();

    double summ = 0.0; double dig = 0.0;

    ifstream read("/Users/user/Desktop/lesson.txt");

    if (read.is_open())
    {
        while(read >> dig)
        {
            summ += dig;
        }
    }

    read.close();

    cout << "Sum of digits in document = " << summ << endl;
    return 0;
}
