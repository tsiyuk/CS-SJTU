// Implement Ackerman function using recursive algorithm
#include <iostream>

using namespace std;

int Ackerman(int m, int n)
{
    if (m == 0)
        return (n + 1);
    if (m != 0 && n == 0)
        return Ackerman(m - 1, 1);
    if (m != 0 && n != 0)
        return Ackerman(m - 1, Ackerman(m, n - 1));
}

int main()
{
    int m, n;
    cout << "please input m and n" << endl;
    cin >> m >> n;
    cout << Ackerman(m, n) << endl;
    return 0;
}
