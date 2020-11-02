#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string line;
    ifstream in("/Users/user/Desktop/lesson.txt");
    if (!in)
    {
        cout << "Файл не открыт\n\n";
        return -1;
    }
    else
    {
        if (in.is_open())
        {
            while (getline(in, line))
            {
                cout << line << endl;
            }
        }
    in.close();
    return 1;
    }
}
