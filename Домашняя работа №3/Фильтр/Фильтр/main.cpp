
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    ifstream in("/Users/user/Desktop/lesson.txt");
    ofstream out("/Users/user/Desktop/lesson.txt");
    string file;
    in >> file;
    out << file;
    while (in >> file){
        out << "-";
        out << file;
    }
    out.close();
}
