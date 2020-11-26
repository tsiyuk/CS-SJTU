// transfer a decimal number to a binary number through using stack
#include <iostream>
#include <stack>

using namespace std;

void trans(int n)
{
    stack<int> s;
    while (n > 0)
    {
        s.push(n % 2);
        n = n / 2;
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}
int main()
{
    int num;
    cout << "Please input a number" << endl;
    cin >> num;
    trans(num);
    return 0;
}
