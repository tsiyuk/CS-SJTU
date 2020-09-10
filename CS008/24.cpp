#include <cstring>
#include <iostream>
using namespace std;

int convert(const char *str)
{
    int sum = 0;
    int l = strlen(str);
    for (int i = 0; str[i] != '\0'; ++i)
    {
        int num = 0;
        switch (str[i])
        {
        case 'a':;
        case 'A':
            num = 10;
            break;
        case 'b':;
        case 'B':
            num = 11;
            break;
        case 'c':;
        case 'C':
            num = 12;
            break;
        case 'd':;
        case 'D':
            num = 13;
            break;
        case 'e':;
        case 'E':
            num = 14;
            break;
        case 'f':;
        case 'F':
            num = 15;
            break;
        default:
            num = str[i] - '0';
        }
        int p = power(16, l - i - 1); //求16的n次方
        sum += num * p;
    }

    return sum;
}

int power(const int a, int x)
{
    int s = 1;
    for (int i = 0; i < x; ++i)
        s *= a;
    return s;
}