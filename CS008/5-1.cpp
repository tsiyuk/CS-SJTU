#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a1[129],a2[129];
    cout<<"please input the first number: ";
    cin.getline(a1, 128);
    cout<<"please input the second number: ";
    cin.getline(a2, 128);
    int length, slength;
    char *a3;
    if(strlen(a1)>strlen(a2)){
        length = strlen(a1);
        slength = strlen(a2);
        a3 = a1;
    }
    else {
        length = strlen(a2);
        slength = strlen(a1);
        a3 = a2;
    }//找出长度较长的数组
    int *sum = new int[length+1];
    for(int i=0; i<=length; ++i)
        sum[i] = 0;
    for(int j=0; j<slength; ++j){
        int s = (a1[j] - '0') + (a2[j] - '0');
        if(sum[j]+s<=9) sum[j] += s;
        else {
            sum[j] += s - 10;
            sum[j+1] += 1;
        }
    }//对短数组部分进行处理
    for(int j=slength; j<length; ++j){
        int s = a3[j] - '0';
        if(sum[j]+s<=9) sum[j] += s;
        else {
            sum[j] += s - 10;
            sum[j+1] += 1;
            }
    }//对长数组部分进行处理
    char *sumchar = new char[length+2];
    for(int k=0; k<=length; ++k){
        sumchar[k] = sum[k] + '0';
    }//将int类型的数组转化为char类型
    if(sum[length] == 0) sumchar[length] = '\0';
    else sumchar[length+1] = '\0';
    //添加\0
    for(int i=0; sumchar[i]!='\0'; ++i)
        cout<<sumchar[i]<<' ';

    delete sum;
    return 0;
}