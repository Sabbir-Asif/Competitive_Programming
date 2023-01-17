#include<iostream>
using namespace std;
int* frr;
bool* isComputed;
void NSU(int n)
{
    frr[0] = 0;
    frr[1] = 1;
    for(int i = 2; i < n; i++)
    frr[i] = frr[i-1] + frr[i-2];
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
    cin >> n;
    frr = new int(n);
    if (frr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    isComputed = new bool(n);
    if (isComputed == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    NSU(n);
    printFibonacci(frr, n);
}