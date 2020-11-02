
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

int main()
{
    bool flag = 0;
    const char f_name[] = "/Users/user/Desktop/lesson.txt";
    ifstream in(f_name);
    if (!in.is_open())
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    char ch;
    while (!in.eof())
    {
        ch = ' ';
        in >> ch;
        if (isdigit(ch))
        {
            flag = 1;
            cout << ch;
        }
        else {
            if (flag == 1)
            {
                cout << " ";
                flag = 0;
            }
        }
    }
    in.close();
    return 0;
}
