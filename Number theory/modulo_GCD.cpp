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
#define M 1000000007

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
			res = ((res % p) * (a % p)) % p;
			n--;
		}
		else
		{
			a = ((a % p) * (a % p)) % p;
			n /= 2;
		}
	}

	return res;
}

ll GCD(ll a, ll b, ll n)
{

	if( a == b)
	{
		return (power(a, n, M) + power(b, n, M)) % M;
	}
	else 
	{
		ll candidate = 1;
		ll num = a-b;

		for( ll i = 1; i*i <= num ; i++)
		{
			if(num%i == 0)
			{
				ll temp = (power( a, n, i) + power(b, n, i)) % i;
				if(temp == 0) candidate = max(candidate, i);

				temp = (power(a, n, num/i) + power(b, n, num/i)) % (num/i);
				if(temp == 0) candidate = max(candidate, num/i);
			}
		}

		return candidate % M;
	}
}

int main()
{
	ll a, b, n, t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> n;
		cout << GCD(a, b, n) << endl;
	}

	return 0;
}