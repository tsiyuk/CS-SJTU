//3-14
#include<iostream>
using namespace std;

int main()
{
    cout<<"请输入车辆类型(C-轿车，B-客车，T-卡车)\n";
    char type;
    cin>>type;
    int d1, h1, m1, d2, h2, m2, sum, h = 0;
    cout<<"请输入入场时间(x日x时x分)\n";
    cin>>d1>>h1>>m1;
    cout<<"请输入出场时间(x日x时x分)\n";
    cin>>d2>>h2>>m2;
    if(m2-m1 < 0) h += h2-h1;
    else h += h2-h1+1;
    h += (d2-d1)*24;
    switch(type)
    {
        case 'C':{
            if(h <= 3) sum = 5*h;
            else sum = 15+10*(h-3);
            break;}
        case 'B':{
            if(h <= 2) sum = 10*h;
            else sum = 20+15*(h-2);
            break;}
        case 'T':{
            if(h == 1) sum = 10;
            else sum = 10+15*(h-1);
            break;}
    }
    cout<<sum<<endl;

    return 0;
}