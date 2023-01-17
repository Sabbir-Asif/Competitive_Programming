#include<iostream>
using namespace std;
int *value, *profit;

int BottomUpCutRod(int n)
{
    profit[0] = 0;
    int q;
    for(int j = 1; j <= n; j++)
    {
        q = -1;
        for(int i = 0; i < j; i++)
        q = max(q, value[i] + profit[j - (i+1)]);

        profit[j] = q;
    }

    return profit[n];
}

int main()
{
    int n;
    cout << "Length of the rod : ";
    cin >> n;
    value = new int(n+1);
    profit = new int(n+1);
    cout << "Enter values : ";
    for(int i = 0; i < n; i++)
    cin >> value[i];

    cout << "profit : " << BottomUpCutRod(n) << endl;
    return 0;
}
