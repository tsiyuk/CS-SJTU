//homework 2-4
#include<iostream>
using namespace std;

int main()
{
    int work_time = 0,salary_per_hour = 0,sum = 0;
    cout<<"输入总工作时间（小时）"<<endl;
    cin>>work_time;
    cout<<"输入每小时工资"<<endl;
    cin>>salary_per_hour;
    sum = salary_per_hour * work_time;
    cout<<"应发工资为："<<sum<<endl<<"实发工资为："<<sum*0.9<<endl;

    return 0;
}