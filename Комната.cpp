#include <iostream>
#include <locale.h>
using namespace std;
int main(){
    setlocale(LC_ALL,"Russian");
    system("chcp 1251");
    bool status_day, status_light, status_curtains;
    cout << "Сейчас день или ночь ? День - 0; Ночь - 1" << endl;
    int x;
    cin >> x;
    if (x == 0)
        status_day = true;
    else
        status_day = false;
    if (status_day == true)
    {
        cout << "Раздвинуты шторы ? Да - 0; Нет - 1" << endl;
        cin >> x;
        if (x == 0)
            cout << "В комнате светло." << endl;
        else
        {
            cout << "Лампа включена ? Да - 0; Нет - 1" << endl;
            cin >> x;
            if (x == 0)
                cout << "В комнате светло." << endl;
            else
                cout << "В комнате темно." << endl;
        }
    }
    else
    {
        cout << "Лампа включена ? Да - 0; Нет - 1" << endl;
        cin >> x;
        if (x == 0)
            cout << "В комнате светло." << endl;
        else 
            cout << "В комнате темно." << endl;
    }
}
