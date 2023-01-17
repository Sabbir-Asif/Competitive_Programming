#include<iostream>
using namespace std;
int* frr;
int NSU(int n)
{
    if(n < 3)
    {
        frr[n] = n;
        return frr[n];
    }
    if(frr[n] > 0) return frr[n];
    frr[n] = NSU(n-1) + NSU(n-2) + NSU(n-3);
    return frr[n];
}

void printFibonacci(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


int main()
{
    int n;
    cout << "enter number of elements : ";
    cin >> n;
    frr = new int(n+1);
    for(int i = 0; i <= n; i++)
    frr[i] = -1;
    NSU(n);
    printFibonacci(frr, n);
}