// permutations implemented by stack
#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int start;          // the starting index
    int swapNode;       // the index should be swaped to
    int times;          // the times of poping
    node(int n1 = 0, int n2 = 0, int n3 = 0)
    {
        start = n1;
        swapNode = n2;
        times = n3;
    }
};
void all_range_recur(int n, int arr[])
{
    stack<node> s;      // the stack of tasks
    node cur;
    cur.start = 0;      // the first element of the array
    for (cur.swapNode = 0; cur.swapNode < n; cur.swapNode++)
    {
        s.push(cur);
    } // push the first level of subtasks into stack
    while (!s.empty())
    {
        cur = s.top();
        s.pop(); 
        if (cur.start == n - 1)
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << ' ';
            cout << endl;
        } // the subtask has been completed, output the permutation
        else
        {                                               // have not finished the permutation
            swap(arr[cur.start], arr[cur.swapNode]);    // swap the element
            if (cur.times == 0) // the first time of poping
            { // keep generating subtasks
                s.push(node(cur.start, cur.swapNode, cur.times + 1));
                ++cur.start;
                for (cur.swapNode = cur.start; cur.swapNode < n; cur.swapNode++) // push the subtasks into stack
                    s.push(cur);
            }
            // the second time of poping: swap back arr[start] and arr[swapNode]
            // return to its original location
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
    all_range_recur(num, a);
    return 0;
}