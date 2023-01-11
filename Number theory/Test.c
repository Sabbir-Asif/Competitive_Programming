#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define repf(i,x,n) for(int i=x,i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define M 1000000
#define N 1000000000
typedef pair<int, int>  pii;  
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;

int arr[1000001];

void sieve()
{
	for(int i = 1 ; i <= M ; ++i) arr[i] = -1;

	for ( int i = 2 ; i <= M ; ++i)
	{
		if(arr[i] == -1)
		{
			for(int j = i ; j <= M ; j+=i)
				{
					if(arr[j] == -1)
						arr[j] = i;
				}
		}
	}

}

void printPrime(int n)
{
	while(n > 1)
	{
		cout << arr[n] << " " ;
		n = n/arr[n];
	}

	cout << endl;
}

int main()
{
	sieve();
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		printPrime(n);
	}

	return 0;

}