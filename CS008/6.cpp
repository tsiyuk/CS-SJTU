#include <iostream>
#include <cstring>
using namespace std;

//6-1
void input(char num[])
{
    int l =strlen(num);
    char *tem =new char[l+1];
    for(int i=0; i<=l; ++i)
        tem[i] = num[i];
    for(int i=0, j=l-1; i<l; ++i){
        num[j] = tem[i];
        --j;
    }
}

//6-2
void output(char num[])
{
    int l =strlen(num);
    char *tem =new char[l+1];
    for(int i=0; i<=l; ++i)
        tem[i] = num[i];
    for(int i=0, j=l-1; i<l; ++i){
        num[i] = tem[j];
        --j;
    }
}

//6-3
void add(char num1[], char num2[], char result[])
{
    input(num1);
    input(num2);//将输入数组倒序
    int llength, slength;
    char* num3;
    if(strlen(num1)>strlen(num2)){
        llength = strlen(num1);
        slength = strlen(num2);
        num3 = num1;
    }
    else {
        llength = strlen(num2);
        slength = strlen(num1);
        num3 = num2;
    }//找出长度较长的数组
    int *sum = new int[llength+1];
    for(int i=0; i<=llength; ++i)
        sum[i] = 0;
    for(int j=0; j<slength; ++j){
        int s = (num1[j] - '0') + (num2[j] - '0');
        if(sum[j]+s<=9) sum[j] += s;
        else {
            sum[j] += s - 10;
            sum[j+1] += 1;
        }
    }//对短数组部分进行处理
    for(int j=slength; j<llength; ++j){
        int s = num3[j] - '0';
        if(sum[j]+s<=9) sum[j] += s;
        else {
            sum[j] += s - 10;
            sum[j+1] += 1;
            }
    }//对长数组部分进行处理
    result = new char[llength+2];
    for(int k=0; k<=llength; ++k){
        result[k] = sum[k] + '0';
    }//将int类型的数组转化为char类型
    if(sum[llength] == 0) result[llength] = '\0';
    else result[llength+1] = '\0';
    //添加\0
    output(result);
    //输出数组倒序
    for(int i=0; result[i]!='\0'; ++i)
    cout<<result[i]<<' ';

    delete sum;
}

int main()
{
    char a1[129],a2[129];
    cout<<"please input the first number: ";
    cin.getline(a1, 128);
    cout<<"please input the second number: ";
    cin.getline(a2, 128);
    char *sum;
    add(a1, a2, sum);

    return 0;
}