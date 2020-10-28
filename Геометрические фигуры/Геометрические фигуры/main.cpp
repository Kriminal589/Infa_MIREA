 /*
 Вычислить площади прямоугольника, треугольника, круга, используя подпрограммы-функции.
 */
#include <iostream>
#include <math.h>
using namespace std;

double rectangle(double a, double b)
{
    if ((a < 0) || (b < 0))
        return -1;
    else
        return a * b;
}

double triangle (double a, double b, double c)
{
    if ((a < 0) || (b < 0) || (c < 0))
        return -1;
    
    if (((a+b) <= c) || ((a+c) <= b) || ((b + c) <= a))
        return -1;
    else
        return 0.25 * sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c));
}

double circul (double a)
{
    if (a < 0)
        return -1;
    else
        return M_PI * pow(a, 2.0);

}

int main()
{
    cout <<"Какую фигуру вы выберите ?"<<endl;
    cout <<"Если прямоугольник, то введите 1"<<endl;
    cout <<"Если треугольник, то введите 2"<<endl;
    cout <<"Если круг, то введите 3"<<endl;
    
    int figure; cin >> figure;
    double S;
    
    if(figure == 1)
    {
        cout <<"Введите длину и ширину прямоугольника."<<endl;
        double x,y; cin >> x >> y;
        
        S = rectangle(x, y);
        cout << S << endl;
    }
    
    if(figure == 2)
    {
        cout <<"Введите все 3 стороны треугольника."<<endl;
        
        double x,y,z; cin >> x >> y >> z;
        
//        if ((x < 0) || (y < 0) || (z < 0))
//            return 0;
        
//        if (((x+y) <= z) || ((x+z) <= y) || ((y + z) <= x))
//            return 0;
        
        S = triangle(x, y, z);
        cout << S << endl;
    }
    
    if (figure == 3)
    {
        cout << "Введите радиус окружности." << endl;
        
        double r; cin >> r;
        
//        if (r < 0)
//            return 0;

        S = circul(r);
        cout << S << endl;
    }
    
    else
        return 0;
}

