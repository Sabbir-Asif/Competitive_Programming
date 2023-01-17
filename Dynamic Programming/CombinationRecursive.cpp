#include<iostream>
#define maxN 1000
using namespace std;
int C[maxN][maxN];

int rec(int n, int r)
{
    if(C[n][r] == -1)
    return C[n][r];
    if(r == 1)
    return n;
    else if(r == n || r == 0)
    return 1;
    else
    {
         C[n][r] = rec(n-1, r-1) + rec(n-1, r);
          return C[n][r];
    }
   
}
int Comb(int n, int r)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= min(i,r); j++)
        {
            C[i][j] = -1;
        }
        return rec(n,r);
    }
    
}
int main()
{
    int n,r;
    cout << "Enter N and R : ";
    cin >> n >> r;
    cout << Comb(n,r) << endl;
}