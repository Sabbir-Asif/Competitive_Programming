#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define repf(i,x,n) for(int i=x,i<n;i++)
#define ll long long int
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

ll power(ll a, ll n, ll p)
{
	ll res = 1;

	while(n)
	{
		if(n%2)
		{
			res = (res*a) % p;
			n--;
		}
		else
		{
			a = (a*a) % p;
			n /= 2;
		}
	}

	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << power(8, n, 10) << endl;
}
