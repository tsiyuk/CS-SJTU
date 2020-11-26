// Ackerman function defined by using stack
#include <iostream>
#include <stack>

using namespace std;

int Ackerman(int M, int N)
{
    stack<int> s1;
    s1.push(M);
    s1.push(N);
    int m;
    int n;
    while (true)
    {
        n = s1.top(); // record n
        s1.pop();
        if (s1.empty())
            return n; // n is the value of the Ackerman function when the stack is empty
        m = s1.top(); // record m
        s1.pop();
        if (m != 0 && n != 0)
        {
            s1.push(m - 1);
            s1.push(m);
            s1.push(n - 1);
        }
        if (m != 0 && n == 0)
        {
            s1.push(m - 1);
            s1.push(1);
        }
        if (m == 0)
        {
            s1.push(n + 1);
        }
    }
}
int main()
{
    int m, n;
    cout << "Please input m and n of the Ackerman function" << endl;
    cin >> m >> n;
    cout << Ackerman(m, n);
    return 0;
}
