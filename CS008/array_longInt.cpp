#include <iostream>
#include <cstring>
using namespace std;

//将输入的数组倒序函数
int* input(const char* n)
{
    int l =strlen(n);
    int *tem =new int[l];
    for(int i=0, j=l-1; i<l; ++i,--j)
        tem[j] = n[i]-'0';
    return tem;
}

//将输出的数组倒序函数
void output(char* n)
{
    int l =strlen(n);
    char *tem =new char[l+1];
    for(int i=0; i<=l; ++i)
        tem[i] = n[i];
    for(int i=0, j=l-1; i<l; ++i){
        n[i] = tem[j];
        --j;
    }
    delete []tem;
}

//加法函数
char* add(const char* num1, const char* num2)
{
    int* n1 = input(num1);
    int* n2 = input(num2);//将输入数组倒序
    int llength, slength;
    int* n3;
    if(strlen(num1)>strlen(num2)){
        llength = strlen(num1);
        slength = strlen(num2);
        n3 = n1;
    }
    else {
        llength = strlen(num2);
        slength = strlen(num1);
        n3 = n2;
    }//找出长度较长的数组
    int *sum = new int[llength+1];
    for(int i=0; i<=llength; ++i)
        sum[i] = 0;
    for(int j=0; j<slength; ++j){
        int s = sum[j] + n1[j] + n2[j];
        sum[j] = s % 10;
        sum[j+1] = s / 10;
    }//对短数组部分进行处理
    for(int j=slength; j<llength; ++j){
        int s = sum[j] + n3[j];
        sum[j] = s % 10;
        sum[j+1] = s / 10;
    }//对长数组部分进行处理
    char *sumchar = new char[llength+2];
    for(int k=0; k<=llength; ++k){
        sumchar[k] = sum[k] + '0';
    }//将int类型的数组转化为char类型
    if(sum[llength] == 0) sumchar[llength] = '\0';
    else sumchar[llength+1] = '\0';
    //添加\0
    output(sumchar);
    //输出数组倒序

    delete []sum;
    return sumchar;
}

//判断num1是否大于num2
bool greaterEqual(const char* num1, const char*num2)
{
    bool flag = 0;
    int length1 = strlen(num1), length2 = strlen(num2);
    if(length1 == length2){
        for(int i=0; i<length1; ++i){
            if(num1[i] > num2[i]){
                return true;
            }
            else{
                if(num1[i] < num2[i]) return false;
                else continue;
            }
        }
        return flag;
    }
    else {
        if(length1 > length2) 
            return true;
        else return false;
        }
}

char* sub(const char* num1, const char* num2)
{
    if(!greaterEqual(num1, num2)){
        cout<<"num1 is not bigger than num2"<<endl;
        return nullptr;
    }
    //判断num1是否大于num2
    int* n1 = input(num1);
    int* n2 = input(num2);
    int llength = strlen(num1), slength = strlen(num2);
    int *dif = new int[llength];
    for(int i=0; i<llength; ++i)
        dif[i] = 0;
    for(int i=0; i<slength; ++i){
        int d = n1[i] - n2[i];
        if(dif[i]+d >= 0) dif[i] += d;
        else{
            dif[i] += (d+10);
            dif[i+1] -= 1;
        }
    }//对短数组部分进行处理
    for(int j=slength; j<llength; ++j){
        if(dif[j]+n1[j] >= 0) dif[j] += n1[j];
        else {
            dif[j] += n1[j] + 10;
            dif[j+1] -= 1;
            }
    }//对长数组部分进行处理
    char* difchar = new char[llength+1];
    for(int k=0 ;k<llength; ++k){
        difchar[k] = dif[k] + '0';
    }//将int类型的数组转化为char类型
    int i = llength;
    while(true){
        if(difchar[i-1] != '0') break;
        else --i;
    }
    difchar[i] = '\0';
    //处理多余的零并加上'\0'
    output(difchar);
    delete []dif;
    return difchar;
}

int main()
{
    char a1[129],a2[129];
    cout<<"please input the first number: ";
    cin.getline(a1, 128);
    cout<<"please input the second number: ";
    cin.getline(a2, 128);
    char *sum;
    sum = add(a1, a2);
    for(int i=0; sum[i]!='\0'; ++i)
        cout<<sum[i];
    cout<<endl;
    if(greaterEqual(a1, a2)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    char* dif;
    dif = sub(a2, a1);
    for(int i=0; dif[i]!='\0'; ++i)
        cout<<dif[i];
    cout<<endl;

    delete sum,dif;
    return 0;
}
