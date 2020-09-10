//3-8
#include <iostream>
using namespace std;

int main()
{
    enum wage {twage, pwage, fwage};//工资类型为计时工资，计件工资，固定工资
    int type, t, w = 0, s1;
    double tax, s2 = 0;
    cout<<"请输入工资类型(0-计时工资，1-计件工资，2-固定工资)\n";
    cin>>type;
    switch (type)
    {
    case 0:
        cout<<"请输入工作时间以及每小时薪水\n";
        cin>>t>>w;
        s1 = t * w;
        break;
    case 1:
        cout<<"请输入件数以及每件薪水\n";
        cin>>t>>w;
        s1 = t * w;
        break;
    case 2:
        cout<<"请输入固定工资\n";
        cin>>s1;
        break;
    }
    switch (s1/500)
    {
    case 0:;
    case 1:;
    case 2:;
    case 3:;
    case 4:
        tax += (s1-2000)*0.05;break;
    case 5:;
    case 6:;
    case 7:
        tax += (s1-2500)*0.1+25;break;
    default:
        tax += (s1-4000)*0.15+175;
        break;
    }
    s2 = s1-tax;
    cout<<"应发工资为 "<<s1<<endl<<"实发工资为 "<<s2<<endl;

    return 0;
}