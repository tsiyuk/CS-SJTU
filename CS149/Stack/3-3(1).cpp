// ouput all the permutations of the given array by recursion
#include <iostream>

using namespace std;

void all_range_recur(int n, int j, int arr[])
{
    if (j == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    } // encounter the last element, output the permutation
    else
    {
        for (int i = j; i < n; i++)
        {
            swap(arr[j], arr[i]);           // swap two element
            all_range_recur(n, j + 1, arr); // move to next element
            swap(arr[j], arr[i]);           // revert the array, proceed the next permutation
        }
    }
}
void swap(int a, int b)
{
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}
int main()
{
    int num;
    cout << "Please input the size of the array" << endl;
    cin >> num;
    int *a = new int[num];
    cout << "Please input an array" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> a[i];
    }
    all_range_recur(num, 0, a);
    return 0;
}
