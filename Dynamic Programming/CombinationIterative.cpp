#include<iostream>
using namespace std;
int** C;

int Comb(int n, int r)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j =0; j<= min(i,r); j++)
        {
            if(j ==1)
            C[i][j] = i;
            else if(j == i || j == 0)
            C[i][j] = 1;
            else
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][r];
}

int main()
{
    int n,r;
    cout << "Enter N and R : ";
    cin >> n >> r;
    C = new int*[n+1];
    for(int i = 0; i <=n; i++)
    C[i] = new int(r+1);
    cout << Comb(n,r) << endl;
}