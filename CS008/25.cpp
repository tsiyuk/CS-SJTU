#include <iostream>
#include <cmath>
using namespace std;

class complex
{
    friend complex operator+(const complex &num1, const complex &num2);
    friend complex operator*(const complex &num1, const complex &num2);
    friend ostream &operator<<(ostream &os, const complex &num);

private:
    double x;
    double y;

public:
    complex(const double x1 = 0, const double y1 = 0) : x(x1), y(y1) { ; }
    complex(const complex &other)
    {
        x = other.x;
        y = other.y;
    }
    void setx(double x1){x=x1;}
    void sety(double y1){y=y1;}
};

complex operator+(const complex &num1, const complex &num2)
{
    complex sum;
    sum.x = num1.x + num2.x;
    sum.y = num1.y + num2.y;
    return sum;
}

complex operator*(const complex &num1, const complex &num2)
{
    complex r;
    r.x = num1.x * num2.x - (num1.y * num2.y);
    r.y = num1.x * num2.y + num1.y * num2.x;
    return r;
}

ostream &operator<<(ostream &os, const complex &num)
{
    os << '(' << num.x << ' ';
    if (num.y > 0)
        os << "+ " << num.y << "i)" << endl;
    if (num.y < 0)
        os << "- " << num.y << "i)" << endl;
    if (num.y == 0)
        os << ')' << endl;
    
    return os;
}



void f(double a,double b,double c,complex& x1,complex& x2)
{
    double delta = b*b-4*a*c;
    double zero = 0;
    if(delta == 0){
        x1.setx(-b/(2*a));
        x1.sety(zero);
        x2.setx(-b/(2*a));
        x2.sety(zero);
    }
    if(delta>0){
        x1.setx((-b+sqrt(delta))/(2*a));
        x1.sety(zero);
        x2.setx((-b-sqrt(delta))/(2*a));
        x2.sety(zero);
    }
    else{
        x1.setx(-b/(2*a));
        x1.sety(sqrt(-delta)/(2*a));
        x2.setx(-b/(2*a));
        x2.sety(-sqrt(-delta)/(2*a));
    }
}
