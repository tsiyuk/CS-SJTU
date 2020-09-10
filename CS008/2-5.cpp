//homework 2-5
#include<iostream>
using namespace std;

int main()
{
    double apple_price = 2.5, pear_price = 1.8, banana_price = 2.0, orange_price = 1.6;
    double apple_weight, pear_weight, banana_weight, orange_weight;
    double sum,pay,change;
    int sumi;
    cout<<"分别输入苹果，梨，香蕉，橘子的重量（斤）"<<endl;
    cin>>apple_weight>>pear_weight>>banana_weight>>orange_weight;
    sum = apple_weight * apple_price + pear_weight * pear_price + banana_weight * banana_price + orange_weight * orange_price;
    sumi = int(sum);
    sumi = (sum-sumi<0.5)?sumi:(sumi+1);
    cout<<"应付金额为："<<sumi<<endl;
    cout<<"请输入顾客付款数：";
    cin>>pay;
    change = pay - sumi;
    cout<<"找零为："<<change<<endl;

    return 0;
}